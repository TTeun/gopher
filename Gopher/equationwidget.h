#ifndef EQUATIONWIDGET_H
#define EQUATIONWIDGET_H

#include "renderable/surfacerenderable.h"
#include "shaderhandler/shaderhandler.h"
#include <QWidget>

namespace Ui
{
  class EquationWidget;
}

class EquationWidget : public QWidget
{
  Q_OBJECT

public:
  explicit EquationWidget(QWidget *parent = 0);
  ~EquationWidget();

  Surface::SurfaceRenderable *surface() const;
  void render(QOpenGLFunctions_4_1_Core *glFunctions, Shader::ShaderHandler *ShaderHandler);

private slots:
  void equationChanged();

private:
  std::unique_ptr<Surface::SurfaceRenderable> m_surface;
  Ui::EquationWidget *ui;
  void connectWidgets();
};

#endif // EQUATIONWIDGET_H
