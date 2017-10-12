#include "displayobjects.h"
#include <string>

using namespace std;

namespace Surface
{
  DisplayObjects::DisplayObjects() : m_ball(new SurfaceRenderable()), m_axis(new Axis()) {}

  Axis *DisplayObjects::axis() const { return m_axis.get(); }
  SurfaceRenderable *DisplayObjects::ball() const { return m_ball.get(); }

  void DisplayObjects::init(QOpenGLFunctions_4_1_Core *glFunctons)
  {
    m_ball->init(glFunctons);
    m_ball->createBall(1);

    string func1("f(u,v) = 0 + u + 0 + 0 * u + 1  *u ^ 1");
    string func2("u^2 + v");

    m_ball->fillParametric(func1, func2);
    //    m_ball->load_obj("../Suzanne.obj");
    m_axis->init(glFunctons);
  }
}
