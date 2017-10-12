#ifndef DISPLAYOBJECTS_H
#define DISPLAYOBJECTS_H

#include "axis.h"
#include "surfacerenderable.h"
#include <memory>

namespace Display
{
  class DisplayObjects
  {
  public:
    DisplayObjects();

    Display::SurfaceRenderable *ball() const;
    Display::Axis *axis() const;

    void init(QOpenGLFunctions_4_1_Core *glFunctons);

  private:
    std::unique_ptr<Display::SurfaceRenderable> m_ball;
    std::unique_ptr<Display::Axis> m_axis;
  };
}
#endif // DISPLAYOBJECTS_H
