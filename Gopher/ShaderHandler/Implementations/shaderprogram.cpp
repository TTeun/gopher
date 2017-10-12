#include "shaderprogram.h"

namespace Shader
{
  ShaderProgram::ShaderProgram(QObject *parent) : QOpenGLShaderProgram(parent) {}

  void ShaderProgram::init(QString const &vert, QString const &frag, QString const &geom)
  {
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                                       vert.toUtf8().constData());
    if (geom.length() != 0)
      static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Geometry,
                                                                         geom.toUtf8().constData());
    static_cast<QOpenGLShaderProgram *>(this)->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                                       frag.toUtf8().constData());

    static_cast<QOpenGLShaderProgram *>(this)->link();

    m_projecionMatrixUniform = uniformLocation("projectionMatrix");
    m_modelViewMatrixUniform = uniformLocation("modelViewMatrix");
  }

  void ShaderProgram::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    setUniformValue(m_modelViewMatrixUniform, modelViewMatrix);
    setUniformValue(m_projecionMatrixUniform, projectionMatrix);
  }
}
