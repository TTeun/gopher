#include "gldisplay.h"
#include <QPushButton>
#include <string>

using namespace Surface;
using namespace Shader;

GLDisplay::GLDisplay(QWidget *parent) : QOpenGLWidget(parent)
{
  m_lightPos = QVector3D(0.0, 0.0, -4.0);

  m_modelViewMatrix.setToIdentity();
  m_modelViewMatrix.rotate(-50, QVector3D(1.0, 0.0, 0.0));
}

GLDisplay::~GLDisplay()
{
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
  m_projectionMatrix.translate(0, 0, -4);
  m_projectionMatrix.rotate(nsAngle, 1, 0, 0);
  m_projectionMatrix.rotate(ewAngle, 0, 1, 0);

  m_shaderHandler->updateUniforms(m_projectionMatrix, m_modelViewMatrix);

  uniformsNeedUpdate = false;
}
