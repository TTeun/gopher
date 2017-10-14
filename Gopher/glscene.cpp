#include "glscene.h"
#include <utility>

using namespace Surface;
using namespace Shader;
using namespace std;

GLScene::GLScene(QWidget *parent)
    : GLDisplay(parent), m_axis(new Axis()), m_surfaceRenderables(new vector<SurfaceWidget *>())
{
  qDebug() << "GLScene constructor";
}

GLScene::~GLScene()
{
}

void GLScene::initializeGL()
{
  qDebug() << "init GL";
  m_glFunctions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>(),

  glClearColor(1.0, 1.0, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  m_axis->init(m_glFunctions);
  m_shaderHandler->createShaders();
}

void GLScene::paintGL()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  if (m_needsNewSurfaaceRenderable)
  {
    m_needsNewSurfaaceRenderable = false;
    addSurfaceRenderable();
  }

  if (uniformsNeedUpdate)
    updateUniforms();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  for (auto it = m_surfaceRenderables->begin(); it != m_surfaceRenderables->end(); ++it)
  {
    m_shaderHandler->bind(SHADER_TYPES::BLACK);
    (*it)->surface()->renderSkeleton(m_glFunctions);

    m_shaderHandler->bind(SHADER_TYPES::FLAT);
    (*it)->surface()->render(m_glFunctions);
  }

  glDisable(GL_DEPTH_TEST);
  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  m_axis->render(m_glFunctions);
}

void GLScene::requestNewSurfaceRendearble()
{
  m_needsNewSurfaaceRenderable = true;
}

void GLScene::setMainWindowLayout(QLayout *layout)
{
  m_mainWindowLayout = layout;
}

void GLScene::addSurfaceRenderable()
{
  auto *s = new SurfaceWidget(m_mainWindowLayout->widget());
  s->surface()->init(m_glFunctions);
  string func1("f(u,v) = sin(3.14 * u) * cos(3.14 *v)");
  s->surface()->fillParametric(func1);
  m_mainWindowLayout->addWidget(s);

  m_surfaceRenderables->emplace_back(std::move(s));
}
