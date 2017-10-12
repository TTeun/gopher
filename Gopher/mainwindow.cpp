#include "mainwindow.h"
#include "globjects.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_shaderHandler(new Shader::ShaderHandler(this))
{
  qDebug() << "MainWindow constructor";
  ui->setupUi(this);
  ui->openGLWidget->setShaderHandler(m_shaderHandler.get());
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Up)
  {
    qDebug() << "a";
  }
  ui->openGLWidget->update();
}
