#ifndef AXIS_H
#define AXIS_H

#include "renderable.h"
#include <QMatrix4x4>
#include <memory>

namespace Display
{
  class Axis : public Renderable
  {
  public:
    Axis();
    ~Axis();

    virtual void render(QOpenGLFunctions_4_1_Core *glFunctions, QMatrix4x4 &projectionMatrix);
    virtual void init(QOpenGLFunctions_4_1_Core *glFunctions);

  protected:
    std::unique_ptr<QVector<QVector3D>> m_vertices;
    std::unique_ptr<QVector<QVector4D>> m_colors;

    uint m_coordsBO;
    uint m_colourBO;

    QMatrix4x4 m_modelViewMatrix;
    GLint m_projecionMatrixUniform;
    GLint m_modelViewMatrixUniform;

    virtual void createBuffers(QOpenGLFunctions_4_1_Core *glFunctions);
  };
}

#endif // AXIS_H
