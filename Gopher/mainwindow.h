#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shaderhandler/shaderhandler.h"
#include "surfacewidget.h"
#include <QKeyEvent>
#include <QMainWindow>
#include <memory>

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  void keyPressEvent(QKeyEvent *event);

private slots:
  void addObject();

private:
  Ui::MainWindow *ui;
  std::unique_ptr<Shader::ShaderHandler> m_shaderHandler;
};

#endif // MAINWINDOW_H
