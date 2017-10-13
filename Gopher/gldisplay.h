#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "ShaderHandler/shaderhandler.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLWidget>
#include <QtGui/QMatrix4x4>
#include <memory>

class GLDisplay : public QOpenGLWidget
{
public:
  explicit GLDisplay(QWidget *parent = 0);
  virtual ~GLDisplay();

  void resizeGL(int w, int h);
  void setShaderHandler(Shader::ShaderHandler *shaderHandler);

protected:
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);

protected:
  QOpenGLFunctions_4_1_Core *m_glFunctions;
  Shader::ShaderHandler *m_shaderHandler;

  bool uniformsNeedUpdate = true;
  void updateUniforms();
  QVector3D m_lightPos;
  QMatrix4x4 m_projectionMatrix;
  QMatrix4x4 m_modelViewMatrix;

  float nsAngle = 0.0f;
  float ewAngle = 0.0f;
};

#endif // TRIANGLEWINDOW_H
