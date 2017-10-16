#include "glscene.h"
#include "equationwidget.h"
#include "mainwindow.h"
#include <QLayout>
#include <utility>

using namespace Surface;
using namespace Shader;
using namespace std;

GLScene::GLScene(QWidget *parent)
    : GLDisplay(parent), m_axis(new Axis()), m_surfaceRenderables(new vector<EquationWidget *>())
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
    (*it)->render(m_glFunctions, m_shaderHandler);

  glDisable(GL_DEPTH_TEST);
  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  m_axis->render(m_glFunctions);
}

void GLScene::requestNewSurfaceRendearble()
{
  m_needsNewSurfaaceRenderable = true;
}

void GLScene::setMainWindow(MainWindow *mainWindow)
{
  m_mainWindow = mainWindow;
}

void GLScene::addSurfaceRenderable()
{
  auto *s = new EquationWidget(nullptr);
  s->surface()->init(m_glFunctions);
  m_mainWindow->surfaceWidgetWasAdded(s);

  m_surfaceRenderables->emplace_back(std::move(s));
}
