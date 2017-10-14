#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QOpenGLShaderProgram>
#include <QString>

namespace Shader
{
  class ShaderProgram : public QOpenGLShaderProgram
  {
  public:
    ShaderProgram(QObject *parent = 0);

    void init(QString const &vert, QString const &frag, QString const &geom = QString(""));
    void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

  private:
    GLint m_projecionMatrixUniform;
    GLint m_modelViewMatrixUniform;
  };
}
#endif // SHADERPROGRAM_H
