#include "glscene.h"
#include <utility>

using namespace Surface;
using namespace Shader;
using namespace std;

GLScene::GLScene(QWidget *parent)
    : GLDisplay(parent),
      surf(new SurfaceRenderable()),
      m_surfaceRenderables(new vector<unique_ptr<SurfaceRenderable>>())
{
}

GLScene::~GLScene()
{
}

void GLScene::initializeGL()
{
  qDebug() << "init GL";
  m_glFunctions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>(),

  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_DST_ALPHA);
  glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);

  //  glEnable(GL_DEPTH_TEST);
  //  glDepthFunc(GL_GREATER);

  unique_ptr<SurfaceRenderable> newSurface{new SurfaceRenderable()};
  newSurface->init(m_glFunctions);
  //  newSurface->createBall(1);
  //    newSurface->loadObj("../Suzanne.obj");
  string func1("f(u,v) = sin(3.14 * u ^ (v + 1))");
  newSurface->fillParametric(func1);
  m_surfaceRenderables->emplace_back(std::move(newSurface));

  surf->init(m_glFunctions);
  surf->createBall(1);

  m_shaderHandler->createShaders();
}

void GLScene::paintGL()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_BLEND);

  if (uniformsNeedUpdate)
    updateUniforms();

  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  for (auto it = m_surfaceRenderables->begin(); it != m_surfaceRenderables->end(); ++it)
    (*it)->render(m_glFunctions);

  glDisable(GL_BLEND);
  //  m_shaderHandler->bind(SHADER_TYPES::NORMAL);
  //  m_displayObjects->ball()->render(m_glFunctions);

  //  m_shaderHandler->bind(SHADER_TYPES::BLACK);
  //  m_displayObjects->ball()->renderSkeleton(m_glFunctions);

  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  //  m_displayObjects->axis()->render(m_glFunctions);
}
