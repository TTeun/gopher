#include "mainwindow.h"
#include "renderlist.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  qDebug() << "MainWindow constructor";

  ui->setupUi(this);

  RenderList *r = new RenderList(this);

  r->resize(400, 400);
  r->show();
}

MainWindow::~MainWindow()
{
  delete ui;
}
