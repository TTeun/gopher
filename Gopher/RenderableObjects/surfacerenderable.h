#ifndef SURFACERENDERABLE_H
#define SURFACERENDERABLE_H

#include "renderable.h"
#include <QMatrix4x4>
#include <QVector3D>
#include <QVector4D>
#include <QVector>
#include <QWindow>
#include <memory>
#include <string>

namespace Surface
{
  enum DISPLAY_TYPES
  {
    SURFACE = 1,
    POINTS  = 2,
    LINES   = 4
  };

  class SurfaceRenderable : public Renderable
  {
  public:
    SurfaceRenderable();
    ~SurfaceRenderable();

    void init(QOpenGLFunctions_4_1_Core *glFunctions) override;
    void render(QOpenGLFunctions_4_1_Core *ui) override;
    void load_obj(const char *filename);
    void createBall(float radius);
    void renderSkeleton(QOpenGLFunctions_4_1_Core *glFunctions);
    void fillParametric(std::string &func1, std::string &func2);

    QMatrix4x4 *modelViewMatrix() const;
    void setModelViewMatrix(QMatrix4x4 *modelViewMatrix);

  protected:
    void createBuffers(QOpenGLFunctions_4_1_Core *ui) override;

    std::unique_ptr<QVector<QVector3D>> m_vertices;
    std::unique_ptr<QVector<QVector4D>> m_colors;
    std::unique_ptr<QVector<QVector3D>> m_normals;
    std::unique_ptr<QVector<unsigned int>> m_indices;

    void updateBuffers(QOpenGLFunctions_4_1_Core *ui);

    uint m_coordsBO;
    uint m_colourBO;
    uint m_normalBO;
    uint m_indicesBO;

    QMatrix4x4 *m_modelViewMatrix;
  };
}
#endif // SURFACERENDERABLE_H
