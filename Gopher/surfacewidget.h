#ifndef SURFACEWIDGET_H
#define SURFACEWIDGET_H

#include "renderable/surfacerenderable.h"
#include <QWidget>
#include <memory>

namespace Ui
{
  class SurfaceWidget;
}

class SurfaceWidget : public QWidget
{
  Q_OBJECT

public:
  explicit SurfaceWidget(QWidget *parent = 0);
  ~SurfaceWidget();

  Surface::SurfaceRenderable *surface() const;

private slots:
  void equationChanged();

private:
  Ui::SurfaceWidget *ui;
  std::unique_ptr<Surface::SurfaceRenderable> m_surface;
};

#endif // SURFACEWIDGET_H
