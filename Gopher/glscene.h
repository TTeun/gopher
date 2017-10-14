#ifndef GLSCENE_H
#define GLSCENE_H

#include "gldisplay.h"
#include "surfacewidget.h"
#include <QLayout>
#include <memory>
#include <vector>

class GLScene : public GLDisplay
{
public:
  explicit GLScene(QWidget *parent = 0);
  virtual ~GLScene();

  void initializeGL();
  void paintGL();
  void requestNewSurfaceRendearble();
  SurfaceWidget *addSurfaceWidget();
  void setMainWindowLayout(QLayout *layout);

private:
  QLayout *m_mainWindowLayout;
  bool m_needsNewSurfaaceRenderable = false;
  void addSurfaceRenderable();
  std::unique_ptr<Surface::Axis> m_axis;
  std::unique_ptr<std::vector<SurfaceWidget *>> m_surfaceRenderables;
};

#endif // GLSCENE_H
