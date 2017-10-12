#include "displayobjects.h"

namespace Display
{
  DisplayObjects::DisplayObjects() : m_ball(new SurfaceRenderable()), m_axis(new Axis()) {}

  Display::Axis *DisplayObjects::axis() const { return m_axis.get(); }
  Display::SurfaceRenderable *DisplayObjects::ball() const { return m_ball.get(); }

  void DisplayObjects::init(QOpenGLFunctions_4_1_Core *glFunctons)
  {
    m_ball->init(glFunctons);
    m_ball->createBall(1);
    //  ball->load_obj("../Suzanne.obj");
    m_axis->init(glFunctons);
  }
}
