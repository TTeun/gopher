#ifndef DISPLAYOBJECTS_H
#define DISPLAYOBJECTS_H

#include "axis.h"
#include "surfacerenderable.h"
#include <memory>

namespace Surface
{
  class DisplayObjects
  {
  public:
    DisplayObjects();

    Surface::SurfaceRenderable *ball() const;
    Surface::Axis *axis() const;

    void init(QOpenGLFunctions_4_1_Core *glFunctons);

  private:
    std::unique_ptr<Surface::SurfaceRenderable> m_ball;
    std::unique_ptr<Surface::Axis> m_axis;
  };
}
#endif // DISPLAYOBJECTS_H
