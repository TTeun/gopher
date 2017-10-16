#include "surfacewidget.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPalette>
#include <QVBoxLayout>
#include <string>

using namespace Surface;

SurfaceWidget::SurfaceWidget(QWidget *parent) : QWidget(parent), m_surface(new SurfaceRenderable())
{
  QVBoxLayout *grid = new QVBoxLayout();
  this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  this->setGeometry(0, 0, 220, 180);
  //  this->setStyleSheet("background-color: rgb(220, 220, 220)");

  m_equationLine = new QLineEdit(this);

  m_uMin = new QDoubleSpinBox(this);
  m_uMax = new QDoubleSpinBox(this);
  m_vMin = new QDoubleSpinBox(this);
  m_vMax = new QDoubleSpinBox(this);

  m_uSteps = new QSpinBox(this);
  m_vSteps = new QSpinBox(this);

  m_deleteButton = new QPushButton("X");

  domainGroupbox                    = new QGroupBox("Domain");
  QGridLayout *domainGroupboxLayout = new QGridLayout();

  QLabel *uLabel = new QLabel("u", this);
  QLabel *vLabel = new QLabel("v", this);

  setMinMaxInitial(m_uMin, -10000.0, 10000.0, -3.0);
  setMinMaxInitial(m_uMax, -10000.0, 10000.0, 3.0);
  setMinMaxInitial(m_vMin, -10000.0, 10000.0, -3.0);
  setMinMaxInitial(m_vMax, -10000.0, 10000.0, 3.0);
  setMinMaxInitial(m_uSteps, 1, 10000, 50);
  setMinMaxInitial(m_vSteps, 1, 10000, 50);

  m_deleteButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  m_deleteButton->setMaximumSize(15, 15);

  grid->addWidget(m_deleteButton);
  grid->addWidget(m_equationLine);
  domainGroupboxLayout->addWidget(uLabel, 0, 0);
  domainGroupboxLayout->addWidget(m_uMin, 0, 1);
  domainGroupboxLayout->addWidget(m_uMax, 0, 2);
  domainGroupboxLayout->addWidget(m_uSteps, 0, 3);
  domainGroupboxLayout->addWidget(vLabel, 1, 0);
  domainGroupboxLayout->addWidget(m_vMin, 1, 1);
  domainGroupboxLayout->addWidget(m_vMax, 1, 2);
  domainGroupboxLayout->addWidget(m_vSteps, 1, 3);
  grid->addWidget(domainGroupbox);
  connectWidgets();

  setLayout(grid);
}

SurfaceWidget::~SurfaceWidget()
{
}

SurfaceRenderable *SurfaceWidget::surface() const
{
  return m_surface.get();
}

QSize SurfaceWidget::sizeHint()
{
}

QSize SurfaceWidget::minimumSizeHint()
{
}

void SurfaceWidget::resizeEvent(QResizeEvent *event)
{
}

void SurfaceWidget::equationChanged()
{
  if (m_equationLine->text().size() == 0)
    return;

  QString eq = "f(u,v)=";
  eq.append(m_equationLine->text());
  std::string eq_str = eq.toUtf8().constData();
  try
  {
    m_surface->fillParametric(eq_str,
                              m_uMin->value(),
                              m_uMax->value(),
                              m_vMin->value(),
                              m_vMax->value(),
                              m_uSteps->value(),
                              m_vSteps->value());
  }
  catch (std::string &e)
  {
    qDebug() << e.c_str();
  }
}

void SurfaceWidget::initWidgets()
{
}

void SurfaceWidget::connectWidgets()
{
  connect(m_equationLine, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_uMin, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_uMax, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_vMin, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_vMax, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_uSteps, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
  connect(m_uSteps, SIGNAL(editingFinished()), this, SLOT(equationChanged()));
}

template <typename SpinBox, typename ValueType>
void SurfaceWidget::setMinMaxInitial(SpinBox *spinBox, ValueType min, ValueType max, ValueType initial)
{
  spinBox->setMinimum(min);
  spinBox->setMaximum(max);
  spinBox->setValue(initial);
}
