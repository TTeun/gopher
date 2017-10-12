#include "gldisplay.h"
#include "equationhandler.h"
#include <QPushButton>
#include <string>

using namespace Display;
using namespace Shader;

GLDisplay::GLDisplay(QWidget *parent) : QOpenGLWidget(parent), m_displayObjects(new DisplayObjects())
{
  m_lightPos = QVector3D(0.0, 0.0, -4.0);
}

GLDisplay::~GLDisplay()
{
}

void GLDisplay::initializeGL()
{
  qDebug() << "init GL";
  m_glFunctions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>(),

  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_DST_ALPHA);
  glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);

  //  glEnable(GL_DEPTH_TEST);
  //  glDepthFunc(GL_GREATER);

  m_shaderHandler->createShaders();
  m_displayObjects->init(m_glFunctions);

  std::string str = "f(x) = x + 2";
  auto first      = str.begin();
  auto end        = str.end();
  auto expr       = client::expression();
  bool r          = boost::spirit::qi::phrase_parse(
      first, end, client::exp_parser<std::string::iterator>{} >> qi::eoi, boost::spirit::ascii::space, expr);

  if (r)
  {
    client::print_tree(expr);
  }
}

void GLDisplay::paintGL()
{
  const qreal retinaScale = devicePixelRatio();
  glViewport(0, 0, width() * retinaScale, height() * retinaScale);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  m_projectionMatrix.setToIdentity();
  m_projectionMatrix.perspective(80.0f, width() / static_cast<float>(height()), 0.1f, 100.0f);
  m_projectionMatrix.translate(0, 0, -3);
  m_projectionMatrix.rotate(nsAngle, 1, 0, 0);
  m_projectionMatrix.rotate(ewAngle, 0, 1, 0);

  m_shaderHandler->updateUniforms(m_projectionMatrix, *m_displayObjects->ball()->modelViewMatrix());
  glEnable(GL_BLEND);
  m_shaderHandler->mainShader()->bind();
  //  glEnable(GL_CULL_FACE);
  //  glCullFace(GL_FRONT);
  m_displayObjects->ball()->render(m_glFunctions);

  glDisable(GL_BLEND);
  //  m_normalShader->bind();
  //  m_normalShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  //  ball->render(m_glFunctions, m_projectionMatrix);

  m_shaderHandler->blackShader()->bind();
  m_displayObjects->ball()->renderSkeleton(m_glFunctions);

  m_shaderHandler->flatshader()->bind();
  m_displayObjects->axis()->render(m_glFunctions);
}

void GLDisplay::resizeGL(int w, int h)
{
  Q_UNUSED(w);
  Q_UNUSED(h);
}

ShaderHandler *GLDisplay::shaderHandler() const
{
  return m_shaderHandler;
}

void GLDisplay::setShaderHandler(Shader::ShaderHandler *shaderHandler)
{
  m_shaderHandler = shaderHandler;
}
