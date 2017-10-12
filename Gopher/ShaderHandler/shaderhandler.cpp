#include "shaderhandler.h"

using namespace std;

namespace Shader
{
  ShaderHandler::ShaderHandler(QObject *parent)
      : m_shaderPrograms(new vector<ShaderProgram *>(static_cast<size_t>(SHADER_TYPES::NUM_SHADER_TYPES)))
  {
    for (size_t idx = 0; idx != static_cast<size_t>(SHADER_TYPES::NUM_SHADER_TYPES); ++idx)
    {
      (*m_shaderPrograms)[idx] = new ShaderProgram(parent);
    }
  }

  void ShaderHandler::createShaders()
  {
    m_shaderPrograms->at(static_cast<size_t>(SHADER_TYPES::MAIN))
        ->init("../Gopher/shaders/vertshader.glsl", "../Gopher/shaders/fragshader.glsl");
    m_shaderPrograms->at(static_cast<size_t>(SHADER_TYPES::BLACK))
        ->init("../Gopher/shaders/vert_black.glsl", "../Gopher/shaders/frag_black.glsl");
    m_shaderPrograms->at(static_cast<size_t>(SHADER_TYPES::NORMAL))
        ->init("../Gopher/shaders/vert_geo.glsl",
               "../Gopher/shaders/frag_geo.glsl",
               "../Gopher/shaders/geo_norm.glsl");
    m_shaderPrograms->at(static_cast<size_t>(SHADER_TYPES::FLAT))
        ->init("../Gopher/shaders/vert_flat.glsl", "../Gopher/shaders/frag_flat.glsl");
  }

  void ShaderHandler::updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    for (auto *shader : *m_shaderPrograms)
      updateSingleUniform(shader, projectionMatrix, modelViewMatrix);
  }

  void ShaderHandler::bind(SHADER_TYPES type) { m_shaderPrograms->at(static_cast<size_t>(type))->bind(); }

  template <typename T>
  void
  ShaderHandler::updateSingleUniform(T *shader, QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix)
  {
    shader->bind();
    shader->updateUniforms(projectionMatrix, modelViewMatrix);
  }
}
