#include "normalshader.h"

namespace Shader
{
  NormalShader::NormalShader(QObject *parent) : QOpenGLShaderProgram(parent) {}

  void NormalShader::init()
  {
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                       "../Gopher/shaders/vert_geo.glsl");
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Geometry,
                                                                       "../Gopher/shaders/geo_norm.glsl");
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                       "../Gopher/shaders/frag_geo.glsl");
    static_cast<QOpenGLShaderProgram *>(this)->link();

    m_projecionMatrixUniform = uniformLocation("projectionMatrix");
    m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
  }

  void NormalShader::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
    setUniformValue(m_projecionMatrixUniform, projectionMatrix);
  }
}
