#ifndef SURFACEWIDGET_H
#define SURFACEWIDGET_H

#include "renderable/surfacerenderable.h"
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include <memory>

class SurfaceWidget : public QWidget
{
  Q_OBJECT

public:
  explicit SurfaceWidget(QWidget *parent = 0);
  ~SurfaceWidget();

  Surface::SurfaceRenderable *surface() const;

  QSize sizeHint();
  QSize minimumSizeHint();
  void resizeEvent(QResizeEvent *event);
private slots:
  void equationChanged();

private:
  template <typename SpinBox, typename ValueType>
  void setMinMaxInitial(SpinBox *spinBox, ValueType min, ValueType max, ValueType initial);

  QGroupBox *domainGroupbox;
  void initWidgets();
  void connectWidgets();
  QPushButton *m_deleteButton;
  QLineEdit *m_equationLine;
  QDoubleSpinBox *m_uMin, *m_uMax, *m_vMin, *m_vMax;
  QSpinBox *m_uSteps, *m_vSteps;

  std::unique_ptr<Surface::SurfaceRenderable> m_surface;
};

#endif // SURFACEWIDGET_H
