#ifndef GLSCENE_H
#define GLSCENE_H

#include "equationwidget.h"
#include "gldisplay.h"
#include "surfacewidget.h"
#include <memory>
#include <vector>

class MainWindow;

class GLScene : public GLDisplay
{
public:
  explicit GLScene(QWidget *parent = 0);
  virtual ~GLScene();

  void initializeGL();
  void paintGL();
  void requestNewSurfaceRendearble();
  void setMainWindow(MainWindow *mainWindow);

private:
  MainWindow *m_mainWindow;
  bool m_needsNewSurfaaceRenderable = false;
  void addSurfaceRenderable();
  std::unique_ptr<Surface::Axis> m_axis;
  std::unique_ptr<std::vector<EquationWidget *>> m_surfaceRenderables;
};

#endif // GLSCENE_H
