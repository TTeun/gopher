#include "surfacerenderable.h"
#include "parser/collapse.h"
#include "parser/parser.h"
#include "parser/partialcollapse.h"
#include "parser/print.h"
#include <QElapsedTimer>
#include <climits>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Surface
{

  using namespace std;

  SurfaceRenderable::SurfaceRenderable()
      : m_vertices(new QVector<QVector3D>()),
        m_colors(new QVector<QVector3D>()),
        m_normals(new QVector<QVector3D>()),
        m_indices(new QVector<unsigned int>())
  {
  }

  SurfaceRenderable::~SurfaceRenderable()
  {
  }

  void SurfaceRenderable::init(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    assert(glFunctions);
    createBuffers(glFunctions);
    qDebug() << "Surface initialized with vao " << m_vao << " and glFunctions " << glFunctions;
  }

  void SurfaceRenderable::render(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    assert(glFunctions);

    updateBuffers(glFunctions);
    glFunctions->glBindVertexArray(m_vao);

    glFunctions->glDrawElements(GL_TRIANGLES, m_indices->size(), GL_UNSIGNED_INT, 0);
    glFunctions->glBindVertexArray(0);
  }

  void SurfaceRenderable::createBuffers(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glGenVertexArrays(1, &m_vao);
    glFunctions->glBindVertexArray(m_vao);

    glFunctions->glGenBuffers(1, &m_coordsBO);
    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_coordsBO);
    glFunctions->glEnableVertexAttribArray(0);
    glFunctions->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glFunctions->glGenBuffers(1, &m_colourBO);
    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_colourBO);
    glFunctions->glEnableVertexAttribArray(1);
    glFunctions->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glFunctions->glGenBuffers(1, &m_normalBO);
    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_normalBO);
    glFunctions->glEnableVertexAttribArray(2);
    glFunctions->glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glFunctions->glGenBuffers(1, &m_indicesBO);
    glFunctions->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBO);

    glFunctions->glBindVertexArray(0);
  }

  void SurfaceRenderable::clear()
  {
    m_vertices->clear();
    m_vertices->squeeze();
    m_colors->clear();
    m_colors->squeeze();
    m_normals->clear();
    m_normals->squeeze();
    m_indices->clear();
    m_indices->squeeze();
  }

  void SurfaceRenderable::updateBuffers(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glBindVertexArray(m_vao);

    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_coordsBO);
    glFunctions->glBufferData(
        GL_ARRAY_BUFFER, sizeof(QVector3D) * m_vertices->size(), m_vertices->data(), GL_DYNAMIC_DRAW);

    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_colourBO);
    glFunctions->glBufferData(
        GL_ARRAY_BUFFER, sizeof(QVector3D) * m_colors->size(), m_colors->data(), GL_DYNAMIC_DRAW);

    //    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_normalBO);
    //    glFunctions->glBufferData(
    //        GL_ARRAY_BUFFER, sizeof(QVector3D) * m_normals->size(), m_normals->data(), GL_DYNAMIC_DRAW);

    glFunctions->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBO);
    glFunctions->glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                              sizeof(unsigned int) * m_indices->size(),
                              m_indices->data(),
                              GL_DYNAMIC_DRAW);
  }

  void SurfaceRenderable::loadObj(const char *filename)
  {
    ifstream in(filename, ios::in);
    if (!in)
      throw string("cant open file");

    string line;
    while (getline(in, line))
    {
      if (line.substr(0, 2) == "v ")
      {
        istringstream s(line.substr(2));
        QVector3D v;
        s >> v[0];
        s >> v[1];
        s >> v[2];
        m_vertices->append(v);
        m_colors->append(QVector3D(0.6f, 0.6f, 0.6f));
      }
      else if (line.substr(0, 2) == "f ")
      {
        istringstream s(line.substr(2));
        uint a;
        QVector<unsigned int> t_indices;
        while (not s.eof())
        {
          s >> a;
          t_indices.append(a - 1);
        }
        for (int i = 2; i < t_indices.size(); ++i)
        {
          m_indices->append(t_indices[0]);
          m_indices->append(t_indices[i - 1]);
          m_indices->append(t_indices[i]);
        }
      }
      else if (line.substr(0, 3) == "vn ")
      {
      }
      else if (line[0] == '#')
      {
        /* ignoring this line */
      }
      else
      {
        /* ignoring this line */
      }
    }
  }

  QVector3D atSphericalCoords(double polar_angle, double azi_angle)
  {
    return QVector3D(cos(polar_angle) * sin(azi_angle), sin(polar_angle) * sin(azi_angle), cos(azi_angle));
  }

  void SurfaceRenderable::createBall(float radius)
  {
    clear();
    size_t polar_slices = 30;
    size_t azi_slices   = 15;
    uint index;

    double d_polar = 2 * M_PI / static_cast<double>(polar_slices);
    double d_azi   = M_PI / static_cast<double>(azi_slices);
    double polar_angle;
    double azi_angle;

    for (size_t polar = 0; polar != polar_slices; ++polar)
    {
      polar_angle = polar * d_polar;
      for (size_t azi = 0; azi != azi_slices; ++azi)
      {
        azi_angle = azi * d_azi;

        index = m_vertices->size();
        m_vertices->append(radius * atSphericalCoords(polar_angle, azi_angle));
        m_vertices->append(radius * atSphericalCoords(polar_angle + d_polar, azi_angle));
        m_vertices->append(radius * atSphericalCoords(polar_angle + d_polar, azi_angle + d_azi));
        m_vertices->append(radius * atSphericalCoords(polar_angle, azi_angle + d_azi));

        m_indices->append(index);
        m_indices->append(index + 1);
        m_indices->append(index + 2);

        m_indices->append(index);
        m_indices->append(index + 2);
        m_indices->append(index + 3);
      }
    }

    for (int i = 0; i != m_vertices->size(); ++i)
    {
      m_colors->append(QVector3D(0.2, 0.2, 0.2));
      m_normals->append(m_vertices->at(i).normalized());
    }
  }

  void SurfaceRenderable::renderSkeleton(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glBindVertexArray(m_vao);

    updateBuffers(glFunctions);
    glFunctions->glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_INT, 0);
  }

  void SurfaceRenderable::fillParametric(std::string &func,
                                         double u_min,
                                         double u_max,
                                         double v_min,
                                         double v_max,
                                         double u_steps,
                                         double v_steps)
  {
    clear();
    auto first = func.begin();
    auto end   = func.end();
    auto expr  = Parser::expression();
    if (boost::spirit::qi::phrase_parse(first,
                                        end,
                                        Parser::exp_parser<std::string::iterator>{} >> qi::eoi,
                                        boost::spirit::ascii::space,
                                        expr))
    {
      if (u_max <= u_min || v_max <= v_min)
        throw string{"Empty parameter domain!"};

      expr.syntax_tree.type = Parser::collapse(expr.syntax_tree.type);
      double val1;

      double u = u_min, v = v_min;
      float d_u = (u_max - u_min) / static_cast<float>(u_steps);
      float d_v = (v_max - v_min) / static_cast<float>(v_steps);

      double max = numeric_limits<double>::min();
      double min = numeric_limits<double>::max();

      QElapsedTimer timer;
      timer.start();
      for (size_t u_index = 0; u_index != u_steps + 1; ++u_index)
      {
        v = v_min;
        for (size_t v_index = 0; v_index != v_steps + 1; ++v_index)
        {
          val1 = Parser::eval(expr.syntax_tree.type, make_pair("u", u), make_pair("v", v));
          max  = max > val1 ? max : val1;
          min  = min < val1 ? min : val1;

          m_vertices->append(QVector3D(u, v, val1));
          v += d_v;
        }
        u += d_u;
      }
      qDebug() << "Parametric surface evaluation operation took" << timer.elapsed() << "milliseconds";

      max = max > 4.0 ? 4.0 : max;
      min = min < -4.0 ? -4.0 : min;
      if (max == min)
      {
        max = 1.0;
        min = 0;
      }

      for (auto &pos : *m_vertices)
        m_colors->append((pos[2] - min) / (max - min) * QVector3D(0.86, 0.95, 0.96));

      for (size_t u_index = 0; u_index != u_steps; ++u_index)
      {
        for (size_t v_index = 0; v_index != v_steps; ++v_index)
        {
          m_indices->append(v_index + u_index * (v_steps + 1));
          m_indices->append(v_index + 1 + u_index * (v_steps + 1));
          m_indices->append(v_index + (u_index + 1) * (v_steps + 1));

          m_indices->append(v_index + 1 + u_index * (v_steps + 1));
          m_indices->append(v_index + 1 + (u_index + 1) * (v_steps + 1));
          m_indices->append(v_index + (u_index + 1) * (v_steps + 1));
        }
      }
    }
    else
    {
      throw string{"Parse Error"};
    }
  }
}
