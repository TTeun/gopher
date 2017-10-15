#include "surfacewidget.h"
#include "ui_surfacewidget.h"
#include <QLineEdit>
#include <string>

using namespace Surface;

SurfaceWidget::SurfaceWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::SurfaceWidget), m_surface(new SurfaceRenderable())
{
  ui->setupUi(this);
  connect(ui->equationLine, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->var1Min, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->var1Max, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->var2Min, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->var2Max, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->uStepsSpinbox, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(ui->vStepsSpinbox, SIGNAL(editingFinished()), this, SLOT(equationChanged()));

  connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(updateSizes(int)));

  ui->colorButton->setStyleSheet("background: red");

  ui->equationLine->hide();
  QLineEdit *q = new QLineEdit(this);
  layout()->addWidget(q);
}

SurfaceWidget::~SurfaceWidget()
{
  delete ui;
}

SurfaceRenderable *SurfaceWidget::surface() const
{
  return m_surface.get();
}

void SurfaceWidget::equationChanged()
{
  if (ui->equationLine->text().size() == 0)
    return;

  QString eq = "f(u,v)=";
  eq.append(ui->equationLine->text());
  std::string eq_str = eq.toUtf8().constData();
  try
  {
    m_surface->fillParametric(eq_str,
                              ui->var1Min->value(),
                              ui->var1Max->value(),
                              ui->var2Min->value(),
                              ui->var2Max->value(),
                              ui->uStepsSpinbox->value(),
                              ui->vStepsSpinbox->value());
  }
  catch (std::string &e)
  {
    qDebug() << e.c_str();
  }
}

void SurfaceWidget::updateSizes(int index)
{
  for (int i = 0; i < ui->tabWidget->count(); i++)
    if (i != index)
      ui->tabWidget->widget(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

  ui->tabWidget->widget(index)->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  ui->tabWidget->widget(index)->resize(ui->tabWidget->widget(index)->minimumSizeHint());
  ui->tabWidget->widget(index)->adjustSize();
  resize(minimumSizeHint());
  adjustSize();
}
