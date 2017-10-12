#include "gldisplay.h"
#include <QPushButton>
#include <string>

using namespace Surface;
using namespace Shader;

GLDisplay::GLDisplay(QWidget *parent) : QOpenGLWidget(parent), m_displayObjects(new DisplayObjects())
{
  m_lightPos = QVector3D(0.0, 0.0, -4.0);
}

GLDisplay::~GLDisplay()
{
}

void GLDisplay::initializeGL()
{
  qDebug() << "init GL";
  m_glFunctions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>(),

  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_DST_ALPHA);
  glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);

  //  glEnable(GL_DEPTH_TEST);
  //  glDepthFunc(GL_GREATER);

  m_shaderHandler->createShaders();
  m_displayObjects->init(m_glFunctions);
}

void GLDisplay::paintGL()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  if (uniformsNeedUpdate)
    updateUniforms();

  glEnable(GL_BLEND);
  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  m_displayObjects->ball()->render(m_glFunctions);

  glDisable(GL_BLEND);
  //  m_shaderHandler->bind(SHADER_TYPES::NORMAL);
  //  m_displayObjects->ball()->render(m_glFunctions);

  m_shaderHandler->bind(SHADER_TYPES::BLACK);
  m_displayObjects->ball()->renderSkeleton(m_glFunctions);

  m_shaderHandler->bind(SHADER_TYPES::FLAT);
  m_displayObjects->axis()->render(m_glFunctions);
}

void GLDisplay::resizeGL(int w, int h)
{
  uniformsNeedUpdate = true;
  update();
  Q_UNUSED(w);
  Q_UNUSED(h);
}

void GLDisplay::setShaderHandler(Shader::ShaderHandler *shaderHandler)
{
  m_shaderHandler = shaderHandler;
}

void GLDisplay::keyPressEvent(QKeyEvent *event)
{
  qDebug() << "keu";
  switch (event->key())
  {
  case Qt::Key_Up:
    --nsAngle;
    break;
  case Qt::Key_Down:
    ++nsAngle;
    break;
  case Qt::Key_Right:
    ++ewAngle;
    break;
  case Qt::Key_Left:
    --ewAngle;
    break;
  default:
    break;
  }
  uniformsNeedUpdate = true;
  update();
}

void GLDisplay::mousePressEvent(QMouseEvent *event)
{
  setFocus();
  qDebug() << "Mouse click";
}

void GLDisplay::updateUniforms()
{
  m_projectionMatrix.setToIdentity();
  m_projectionMatrix.perspective(80.0f, width() / static_cast<float>(height()), 0.1f, 100.0f);
  m_projectionMatrix.translate(0, 0, -3);
  m_projectionMatrix.rotate(nsAngle, 1, 0, 0);
  m_projectionMatrix.rotate(ewAngle, 0, 1, 0);

  m_shaderHandler->updateUniforms(m_projectionMatrix, *m_displayObjects->ball()->modelViewMatrix());

  uniformsNeedUpdate = false;
}
