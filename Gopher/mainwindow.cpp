#include "mainwindow.h"
#include "gldisplay.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGroupBox>
#include <QLayout>
#include <cassert>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_shaderHandler(new Shader::ShaderHandler(this))
{
  qDebug() << "MainWindow constructor";
  ui->setupUi(this);
  ui->openGLWidget->setShaderHandler(m_shaderHandler.get());
  ui->openGLWidget->setMainWindow(this);
  connect(ui->addObjectMenuItem, SIGNAL(triggered()), this, SLOT(addObject()));

  collapseButton = new QPushButton(">");
  collapseButton->setMaximumWidth(10);
  collapseButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  centralWidget()->layout()->addWidget(collapseButton);

  QVBoxLayout *vBox = new QVBoxLayout();
  vBox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  functionsBox = new QGroupBox("Equations");
  functionsBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  functionsBox->setLayout(vBox);
  functionsBox->setMaximumWidth(270);
  centralWidget()->layout()->addWidget(functionsBox);

  connect(collapseButton, SIGNAL(pressed()), this, SLOT(showHideGroupBox()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  ui->openGLWidget->update();
}

void MainWindow::surfaceWidgetWasAdded(EquationWidget *addedWidget)
{
  functionsBox->layout()->addWidget(addedWidget);
  ui->openGLWidget->update();
  update();
}

void MainWindow::addObject()
{
  qDebug() << "Added new SurfaceWidget";
  ui->openGLWidget->requestNewSurfaceRendearble();

  functionsBox->show();
  collapseButton->setText(">");

  ui->openGLWidget->update();
}

void MainWindow::showHideGroupBox()
{
  if (functionsBox->isVisible())
  {
    functionsBox->hide();
    collapseButton->setText("<");
  }
  else
  {
    functionsBox->show();
    collapseButton->setText(">");
  }
}
