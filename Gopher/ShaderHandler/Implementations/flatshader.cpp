#include "flatshader.h"

namespace Shader
{
  FlatShader::FlatShader(QObject *parent) : QOpenGLShaderProgram(parent) {}

  void FlatShader::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
    setUniformValue(m_projecionMatrixUniform, projectionMatrix);
  }

  void FlatShader::init()
  {
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                       "../Gopher/shaders/vert_flat.glsl");
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                       "../Gopher/shaders/frag_flat.glsl");
    static_cast<QOpenGLShaderProgram *>(this)->link();

    m_projecionMatrixUniform = uniformLocation("projectionMatrix");
    m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
  }
}
