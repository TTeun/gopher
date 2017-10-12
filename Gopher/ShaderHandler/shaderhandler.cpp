#include "shaderhandler.h"

namespace Shader
{
  ShaderHandler::ShaderHandler(QObject *parent)
      : m_mainShader(new MainShader(parent)),
        m_blackShader(new BlackShader(parent)),
        m_flatshader(new FlatShader(parent)),
        m_normalShader(new NormalShader(parent))
  {
  }

  MainShader *ShaderHandler::mainShader() const { return m_mainShader.get(); }
  BlackShader *ShaderHandler::blackShader() const { return m_blackShader.get(); }
  FlatShader *ShaderHandler::flatshader() const { return m_flatshader.get(); }
  NormalShader *ShaderHandler::normalShader() const { return m_normalShader.get(); }

  void ShaderHandler::createShaders()
  {
    m_mainShader->init();
    m_flatshader->init();
    m_normalShader->init();
    m_blackShader->init();
  }

  void ShaderHandler::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    updateSingleUniform(m_mainShader.get(), projectionMatrix, modelViewMatrix);
    updateSingleUniform(m_blackShader.get(), projectionMatrix, modelViewMatrix);
    updateSingleUniform(m_normalShader.get(), projectionMatrix, modelViewMatrix);
    updateSingleUniform(m_flatshader.get(), projectionMatrix, modelViewMatrix);
  }

  template <typename T>
  void
  ShaderHandler::updateSingleUniform(T *shader, QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    shader->bind();
    shader->updateUniforms(projectionMatrix, modelViewMatrix);
  }
}
