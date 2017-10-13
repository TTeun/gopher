#include "displayobjects.h"
#include <string>

using namespace std;

namespace Surface
{
  DisplayObjects::DisplayObjects()
      : m_surfaceRenderables(new vector<unique_ptr<SurfaceRenderable>>()),
        m_axis(new Axis()),
        surf(new SurfaceRenderable())
  {
  }

  DisplayObjects::~DisplayObjects()
  {
  }

  Axis *DisplayObjects::axis() const
  {
    return m_axis.get();
  }

  void DisplayObjects::init(QOpenGLFunctions_4_1_Core *glFunctons)
  {
    m_glFunctons = glFunctons;
    m_axis->init(m_glFunctons);
    addSurfaceRenderable();
    //    surf->createBall(1);
    //    surf->init(m_glFunctons);
  }

  void DisplayObjects::addSurfaceRenderable()
  {
    qDebug() << "Added surface " << m_glFunctons;
    unique_ptr<SurfaceRenderable> newSurface{new SurfaceRenderable()};
    newSurface->init(m_glFunctons);
    newSurface->createBall(1);
    //    newSurface->loadObj("../Suzanne.obj");
    //    string func1("f(u,v) = sin(3.14 * u)");
    //    newSurface->fillParametric(func1);
    m_surfaceRenderables->emplace_back(std::move(newSurface));
  }

  std::vector<std::unique_ptr<SurfaceRenderable>> const *DisplayObjects::surfaceRenderables() const
  {
    return m_surfaceRenderables.get();
  }

  void DisplayObjects::render()
  {
    if (m_surfaceRenderables->size() != 0)
    {
      m_surfaceRenderables->at(0)->render(m_glFunctons);
      qDebug() << "asdsa";
    }
  }
}
