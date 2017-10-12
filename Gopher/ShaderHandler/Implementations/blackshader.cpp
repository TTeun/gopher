#include "blackshader.h"

BlackShader::BlackShader(QObject *parent) : QOpenGLShaderProgram(parent)
{
}

void BlackShader::init()
{
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                     "../Gopher/shaders/vert_black.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                     "../Gopher/shaders/frag_black.glsl");
  static_cast<QOpenGLShaderProgram *>(this)->link();

  m_projecionMatrixUniform = uniformLocation("projectionMatrix");
  m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
}

void BlackShader::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
{
  setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
  setUniformValue(m_projecionMatrixUniform, projectionMatrix);
}
