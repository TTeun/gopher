#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "RenderableObjects/ballrenderable.h"
#include "ShaderHandler/shaderhandler.h"
#include "parser/parser.h"
#include "parser/print.h"
#include "parser/simplify.h"
#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLWidget>
#include <QVector>
#include <QtCore/qmath.h>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>
#include <memory>

class RenderList : public QOpenGLWidget
{
public:
  explicit RenderList(QWidget *parent = 0);
  virtual ~RenderList();

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

private:
  QOpenGLFunctions_4_1_Core *m_glFunctions;
  ShaderHandler *m_shaderHandler;

  QVector3D m_lightPos;
  std::unique_ptr<Display::BallRenderable> ball;
  std::unique_ptr<Display::Axis> axis;
  QMatrix4x4 m_projectionMatrix;
  float nsAngle = 0.0f;
  float ewAngle = 0.0f;

  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  GLint m_lightPosUniform;
};

#endif // TRIANGLEWINDOW_H
