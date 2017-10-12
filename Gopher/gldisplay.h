#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "RenderableObjects/axis.h"
#include "RenderableObjects/ballrenderable.h"
#include "RenderableObjects/displayobjects.h"
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

class GLDisplay : public QOpenGLWidget
{
public:
  explicit GLDisplay(QWidget *parent = 0);
  virtual ~GLDisplay();

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  Shader::ShaderHandler *shaderHandler() const;
  void setShaderHandler(Shader::ShaderHandler *shaderHandler);

private:
  QOpenGLFunctions_4_1_Core *m_glFunctions;
  Shader::ShaderHandler *m_shaderHandler;
  Display::DisplayObjects *m_displayObjects;

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
