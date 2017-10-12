#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ShaderHandler/shaderhandler.h"
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

private:
  std::unique_ptr<Shader::ShaderHandler> m_shaderHandler;
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
