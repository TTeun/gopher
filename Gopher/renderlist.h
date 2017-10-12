#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "RenderableObjects/ballrenderable.h"
#include "ShaderHandler/blackshader.h"
#include "ShaderHandler/flatshader.h"
#include "ShaderHandler/mainshader.h"
#include "ShaderHandler/normalshader.h"
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
  void createShaders();
  void render();

private:
  QOpenGLFunctions_4_1_Core *m_glFunctions;
  MainShader *m_mainShader;
  BlackShader *m_blackShader;
  FlatShader *m_flatshader;
  NormalShader *m_normalShader;

  QVector3D m_lightPos;
  unique_ptr<BallRenderable> ball;
  unique_ptr<Axis> axis;
  QMatrix4x4 m_projectionMatrix;
  float nsAngle = 0.0f;
  float ewAngle = 0.0f;

  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_readNormalsUniform;
  GLint m_lightPosUniform;
};

#endif // TRIANGLEWINDOW_H
