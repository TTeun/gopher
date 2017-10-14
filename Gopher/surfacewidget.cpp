#include "surfacewidget.h"
#include "ui_surfacewidget.h"

using namespace Surface;

SurfaceWidget::SurfaceWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::SurfaceWidget), m_surface(new SurfaceRenderable())
{
  ui->setupUi(this);
}

SurfaceWidget::~SurfaceWidget()
{
  delete ui;
}

Surface::SurfaceRenderable *SurfaceWidget::surface() const
{
  return m_surface.get();
}
