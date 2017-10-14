#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include "shaderprogram.h"
#include <memory>
#include <vector>

namespace Shader
{

  enum class SHADER_TYPES
  {
    MAIN             = 0,
    BLACK            = 1,
    FLAT             = 2,
    NORMAL           = 3,
    NUM_SHADER_TYPES = 4
  };

  class ShaderHandler
  {
  public:
    ShaderHandler(QObject *parent = 0);

    void createShaders();
    void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);
    void bind(SHADER_TYPES type);

  private:
    template <typename T>
    void updateSingleUniform(T *shader, QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

    std::vector<ShaderProgram *> *m_shaderPrograms;
  };
}

#endif // SHADERHANDLER_H
