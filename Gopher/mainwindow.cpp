#include "mainwindow.h"
#include "gldisplay.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_shaderHandler(new Shader::ShaderHandler(this))
{
  qDebug() << "MainWindow constructor";
  ui->setupUi(this);
  ui->openGLWidget->setShaderHandler(m_shaderHandler.get());
  ui->openGLWidget->setMainWindowLayout(this->layout());
  connect(ui->addObjectMenuItem, SIGNAL(triggered()), this, SLOT(addObject()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  ui->openGLWidget->update();
}

void MainWindow::addObject()
{
  qDebug() << "Add object";
  ui->openGLWidget->requestNewSurfaceRendearble();
  ui->openGLWidget->update();
}
