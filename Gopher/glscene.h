#ifndef GLSCENE_H
#define GLSCENE_H

#include "RenderableObjects/surfacerenderable.h"
#include "gldisplay.h"
#include <memory>
#include <vector>

class GLScene : public GLDisplay
{
public:
  explicit GLScene(QWidget *parent = 0);
  virtual ~GLScene();

  void initializeGL();
  void paintGL();

  Surface::SurfaceRenderable *surf;

private:
  std::unique_ptr<Surface::Axis> m_axis;
  std::unique_ptr<std::vector<std::unique_ptr<Surface::SurfaceRenderable>>> m_surfaceRenderables;
};

#endif // GLSCENE_H
