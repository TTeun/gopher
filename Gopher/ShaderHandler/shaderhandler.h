#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include "ShaderHandler/Implementations/blackshader.h"
#include "ShaderHandler/Implementations/flatshader.h"
#include "ShaderHandler/Implementations/mainshader.h"
#include "ShaderHandler/Implementations/normalshader.h"

class ShaderHandler
{
public:
  ShaderHandler(QObject *parent = 0);

  MainShader *mainShader() const;
  BlackShader *blackShader() const;
  FlatShader *flatshader() const;
  NormalShader *normalShader() const;
  void createShaders();

private:
  MainShader *m_mainShader;
  BlackShader *m_blackShader;
  FlatShader *m_flatshader;
  NormalShader *m_normalShader;
};

#endif // SHADERHANDLER_H
