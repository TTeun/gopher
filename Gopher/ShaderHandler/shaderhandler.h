#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include "ShaderHandler/Implementations/blackshader.h"
#include "ShaderHandler/Implementations/flatshader.h"
#include "ShaderHandler/Implementations/mainshader.h"
#include "ShaderHandler/Implementations/normalshader.h"
#include <memory>

namespace Shader
{
  class ShaderHandler
  {
  public:
    ShaderHandler(QObject *parent = 0);

    MainShader *mainShader() const;
    BlackShader *blackShader() const;
    FlatShader *flatshader() const;
    NormalShader *normalShader() const;

    void createShaders();
    void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

  private:
    template <typename T>
    void updateSingleUniform(T *shader, QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);
    std::unique_ptr<MainShader> m_mainShader;
    std::unique_ptr<BlackShader> m_blackShader;
    std::unique_ptr<FlatShader> m_flatshader;
    std::unique_ptr<NormalShader> m_normalShader;
  };
}

#endif // SHADERHANDLER_H
