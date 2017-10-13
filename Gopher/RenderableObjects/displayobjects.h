#ifndef DISPLAYOBJECTS_H
#define DISPLAYOBJECTS_H

#include "axis.h"
#include "surfacerenderable.h"
#include <memory>
#include <vector>

namespace Surface
{
  class DisplayObjects
  {
  public:
    DisplayObjects();
    ~DisplayObjects();

    Surface::Axis *axis() const;
    void init(QOpenGLFunctions_4_1_Core *glFunctons);
    void addSurfaceRenderable();

    std::vector<std::unique_ptr<SurfaceRenderable>> const *surfaceRenderables() const;
    std::unique_ptr<SurfaceRenderable> surf;

    void render();

  private:
    QOpenGLFunctions_4_1_Core *m_glFunctons;
    std::unique_ptr<std::vector<std::unique_ptr<SurfaceRenderable>>> m_surfaceRenderables;
    std::unique_ptr<Surface::Axis> m_axis;
  };
}
#endif // DISPLAYOBJECTS_H
