#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "equationwidget.h"
#include "shaderhandler/shaderhandler.h"
#include "surfacewidget.h"
#include <QGroupBox>
#include <QKeyEvent>
#include <QMainWindow>
#include <QPushButton>
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

  void surfaceWidgetWasAdded(EquationWidget *addedWidget);

protected:
  void keyPressEvent(QKeyEvent *event);

private slots:
  void addObject();
  void showHideGroupBox();

private:
  Ui::MainWindow *ui;
  QGroupBox *functionsBox;
  QPushButton *collapseButton = new QPushButton(">");
  std::unique_ptr<Shader::ShaderHandler> m_shaderHandler;
};

#endif // MAINWINDOW_H
