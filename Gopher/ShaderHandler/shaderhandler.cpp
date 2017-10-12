#include "shaderhandler.h"

ShaderHandler::ShaderHandler(QObject *parent)
    : m_mainShader(new MainShader(parent)),
      m_blackShader(new BlackShader(parent)),
      m_flatshader(new FlatShader(parent)),
      m_normalShader(new NormalShader(parent))
{
}

MainShader *ShaderHandler::mainShader() const
{
  return m_mainShader;
}

BlackShader *ShaderHandler::blackShader() const
{
  return m_blackShader;
}

FlatShader *ShaderHandler::flatshader() const
{
  return m_flatshader;
}

NormalShader *ShaderHandler::normalShader() const
{
  return m_normalShader;
}

void ShaderHandler::createShaders()
{
  m_mainShader->init();
  m_flatshader->init();
  m_normalShader->init();
  m_blackShader->init();
}
