#include "surfacerenderable.h"
#include <cmath>
#include <fstream>
#include <sstream>

#include "parser/collapse.h"
#include "parser/parser.h"
#include "parser/partialcollapse.h"
#include "parser/print.h"

namespace Surface
{

  using namespace std;

  SurfaceRenderable::SurfaceRenderable()
      : m_vertices(new QVector<QVector3D>()),
        m_colors(new QVector<QVector4D>()),
        m_normals(new QVector<QVector3D>()),
        m_indices(new QVector<unsigned int>()),
        m_modelViewMatrix(new QMatrix4x4)
  {
  }

  SurfaceRenderable::~SurfaceRenderable()
  {
  }

  void SurfaceRenderable::init(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    createBuffers(glFunctions);
  }

  void SurfaceRenderable::render(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glBindVertexArray(m_vao);

    updateBuffers(glFunctions);
    glFunctions->glDrawElements(GL_TRIANGLES, m_indices->size(), GL_UNSIGNED_INT, 0);
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
    glFunctions->glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

    glFunctions->glGenBuffers(1, &m_normalBO);
    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_normalBO);
    glFunctions->glEnableVertexAttribArray(2);
    glFunctions->glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glFunctions->glGenBuffers(1, &m_indicesBO);
    glFunctions->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBO);

    glFunctions->glBindVertexArray(0);
  }

  void SurfaceRenderable::updateBuffers(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glBindVertexArray(m_vao);

    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_coordsBO);
    glFunctions->glBufferData(
        GL_ARRAY_BUFFER, sizeof(QVector3D) * m_vertices->size(), m_vertices->data(), GL_DYNAMIC_DRAW);

    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_colourBO);
    glFunctions->glBufferData(
        GL_ARRAY_BUFFER, sizeof(QVector4D) * m_colors->size(), m_colors->data(), GL_DYNAMIC_DRAW);

    glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_normalBO);
    glFunctions->glBufferData(
        GL_ARRAY_BUFFER, sizeof(QVector3D) * m_normals->size(), m_normals->data(), GL_DYNAMIC_DRAW);

    glFunctions->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBO);
    glFunctions->glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                              sizeof(unsigned int) * m_indices->size(),
                              m_indices->data(),
                              GL_DYNAMIC_DRAW);
  }

  QMatrix4x4 *SurfaceRenderable::modelViewMatrix() const
  {
    return m_modelViewMatrix;
  }

  void SurfaceRenderable::setModelViewMatrix(QMatrix4x4 *modelViewMatrix)
  {
    m_modelViewMatrix = modelViewMatrix;
  }

  void SurfaceRenderable::load_obj(const char *filename)
  {
    ifstream in(filename, ios::in);
    if (!in)
    {
      qDebug() << "Cannot open " << filename << endl;
      exit(1);
    }

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
        m_colors->append(QVector4D(0.6f, 0.6f, 0.6f, 0.5f));
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
    m_vertices->clear();
    m_vertices->squeeze();
    m_colors->clear();
    m_colors->squeeze();
    m_normals->clear();
    m_normals->squeeze();
    m_indices->clear();
    m_indices->squeeze();

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
      m_colors->append(QVector4D(0.2, 0.2, 0.2, 0.2));
      m_normals->append(m_vertices->at(i).normalized());
    }
  }

  void SurfaceRenderable::renderSkeleton(QOpenGLFunctions_4_1_Core *glFunctions)
  {
    glFunctions->glBindVertexArray(m_vao);

    updateBuffers(glFunctions);
    glFunctions->glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_INT, 0);
  }

  void SurfaceRenderable::fillParametric(std::string &func1, std::string &func2)
  {
    auto first = func1.begin();
    auto end   = func1.end();
    auto expr  = Parser::expression();

    if (boost::spirit::qi::phrase_parse(first,
                                        end,
                                        Parser::exp_parser<std::string::iterator>{} >> qi::eoi,
                                        boost::spirit::ascii::space,
                                        expr))
    {
      double val;
      expr.syntax_tree.type = Parser::collapse(expr.syntax_tree.type);
      for (size_t i = 0; i != 10000; ++i)
        val = Parser::eval(expr.syntax_tree.type, make_pair("u", 1.0), make_pair("v", 1.0));
      //      expr.syntax_tree.type = Parser::partialCollapse(expr.syntax_tree.type, string("u"), 0.0);
      Parser::printTree(expr);
    }
    else
    {
      qDebug() << "Parse failed";
    }
  }
}
