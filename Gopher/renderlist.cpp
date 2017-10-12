#include "renderlist.h"
#include "equationhandler.h"
#include <QPushButton>
#include <string>

RenderList::RenderList(QWidget *parent)
    : QOpenGLWidget(parent),
      m_mainShader(new MainShader(this)),
      m_blackShader(new BlackShader(this)),
      m_flatshader(new FlatShader(this)),
      m_normalShader(new NormalShader(this)),
      ball(new BallRenderable()),
      axis(new Axis())
{
  m_lightPos = QVector3D(0.0, 0.0, -4.0);
}

RenderList::~RenderList()
{
}

void RenderList::initializeGL()
{
  qDebug() << "init GL";
  m_glFunctions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>(),

  glClearColor(1.0, 1.0, 1.0, 1.0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_DST_ALPHA);
  glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);

  //  glEnable(GL_DEPTH_TEST);
  //  glDepthFunc(GL_GREATER);

  createShaders();
  ball->init(m_glFunctions);
  ball->create();
  //  ball->load_obj("../Suzanne.obj");
  axis->init(m_glFunctions);
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

void RenderList::paintGL()
{
  render();
}

void RenderList::resizeGL(int w, int h)
{
}

void RenderList::createShaders()
{
  m_mainShader->init();
  m_flatshader->init();
  m_normalShader->init();
  m_blackShader->init();
}

void RenderList::render()
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

  nsAngle += 2;
  ewAngle += 1;

  glEnable(GL_BLEND);
  m_mainShader->bind();
  m_mainShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  //  glEnable(GL_CULL_FACE);
  //  glCullFace(GL_FRONT);
  ball->render(m_glFunctions, m_projectionMatrix);

  glDisable(GL_BLEND);
  //  m_normalShader->bind();
  //  m_normalShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  //  ball->render(m_glFunctions, m_projectionMatrix);

  m_blackShader->bind();
  m_blackShader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  ball->renderSkeleton(m_glFunctions, m_projectionMatrix);

  m_flatshader->bind();
  m_flatshader->updateUniforms(m_projectionMatrix, *ball->modelViewMatrix());
  axis->render(m_glFunctions, m_projectionMatrix);
}
