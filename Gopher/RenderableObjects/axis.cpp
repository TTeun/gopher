#include "axis.h"

Axis::Axis() : m_vertices(new QVector<QVector3D>()), m_colors(new QVector<QVector4D>())
{
  m_vertices->append(QVector3D(0, 0, 0));
  m_vertices->append(QVector3D(1, 0, 0));

  m_vertices->append(QVector3D(0, 0, 0));
  m_vertices->append(QVector3D(0, 1, 0));

  m_vertices->append(QVector3D(0, 0, 0));
  m_vertices->append(QVector3D(0, 0, 1));

  m_colors->append(QVector4D(1, 0, 0, 1));
  m_colors->append(QVector4D(1, 0, 0, 1));

  m_colors->append(QVector4D(0, 1, 0, 1));
  m_colors->append(QVector4D(0, 1, 0, 1));

  m_colors->append(QVector4D(0, 0, 1, 1));
  m_colors->append(QVector4D(0, 0, 1, 1));
}

Axis::~Axis()
{
}

void Axis::createBuffers(QOpenGLFunctions_4_1_Core *glFunctions)
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

  glFunctions->glBindVertexArray(0);
}

void Axis::init(QOpenGLFunctions_4_1_Core *glFunctions)
{
  createBuffers(glFunctions);
}

void Axis::render(QOpenGLFunctions_4_1_Core *glFunctions, QMatrix4x4 &projectionMatrix)
{
  glFunctions->glBindVertexArray(m_vao);

  glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_coordsBO);
  glFunctions->glBufferData(
      GL_ARRAY_BUFFER, sizeof(QVector3D) * m_vertices->size(), m_vertices->data(), GL_DYNAMIC_DRAW);

  glFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_colourBO);
  glFunctions->glBufferData(
      GL_ARRAY_BUFFER, sizeof(QVector4D) * m_colors->size(), m_colors->data(), GL_DYNAMIC_DRAW);

  glFunctions->glDrawArrays(GL_LINES, 0, m_vertices->size());
}
