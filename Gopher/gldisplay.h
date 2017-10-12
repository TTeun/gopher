#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "RenderableObjects/displayobjects.h"
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

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  void setShaderHandler(Shader::ShaderHandler *shaderHandler);

protected:
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);

private:
  QOpenGLFunctions_4_1_Core *m_glFunctions;
  Shader::ShaderHandler *m_shaderHandler;
  Surface::DisplayObjects *m_displayObjects;

  bool uniformsNeedUpdate = true;
  void updateUniforms();
  QVector3D m_lightPos;
  QMatrix4x4 m_projectionMatrix;
  float nsAngle = 0.0f;
  float ewAngle = 0.0f;

  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  GLint m_lightPosUniform;
};

#endif // TRIANGLEWINDOW_H
