#include "equationwidget.h"
#include "ui_equationwidget.h"

using namespace Surface;
using namespace Shader;

EquationWidget::EquationWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::EquationWidget), m_surface(new SurfaceRenderable())
{
  ui->setupUi(this);
  connectWidgets();
}

EquationWidget::~EquationWidget()
{
  delete ui;
}

SurfaceRenderable *EquationWidget::surface() const
{
  return m_surface.get();
}

void EquationWidget::render(QOpenGLFunctions_4_1_Core *glFunctions, ShaderHandler *ShaderHandler)
{
  if (ui->m_showGrid->isChecked())
  {
    glDepthFunc(GL_LESS);
    ShaderHandler->bind(SHADER_TYPES::BLACK);
    m_surface->renderSkeleton(glFunctions);
  }
  if (ui->m_showSurface->isChecked())
  {
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.0f, 1.0f);

    ShaderHandler->bind(SHADER_TYPES::FLAT);
    m_surface->render(glFunctions);
  }
}

void EquationWidget::equationChanged()
{
  if (ui->m_equationLine->text().size() == 0)
    return;

  QString eq = "f(u,v)=";
  eq.append(ui->m_equationLine->text());
  std::string eq_str = eq.toUtf8().constData();
  try
  {
    m_surface->fillParametric(eq_str,
                              ui->m_uMin->value(),
                              ui->m_uMax->value(),
                              ui->m_vMin->value(),
                              ui->m_vMax->value(),
                              ui->m_uSteps->value(),
                              ui->m_vSteps->value());
  }
  catch (std::string &e)
  {
    qDebug() << e.c_str();
  }
}

void EquationWidget::connectWidgets()
{
  connect(ui->m_equationLine, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_uMin, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_uMax, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_vMin, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_vMax, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_uSteps, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->m_uSteps, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
}
