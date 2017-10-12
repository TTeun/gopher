#include "mainwindow.h"
#include "renderlist.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  qDebug() << "MainWindow constructor";

  ui->setupUi(this);
}

MainWindow::~MainWindow()
{

  delete ui;
}
