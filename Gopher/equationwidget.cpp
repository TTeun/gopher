#include "equationwidget.h"
#include <QGridLayout>
#include <QLineEdit>
EquationWidget::EquationWidget(QWidget *parent) : QWidget(parent)
{
  QGridLayout *gridLayout = new QGridLayout(this);
  setLayout(gridLayout);

  QLineEdit *q = new QLineEdit(this);
  layout()->addWidget(q);
  q->hide();

  QLineEdit *g = new QLineEdit(this);
  layout()->addWidget(g);
}
