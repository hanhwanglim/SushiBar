#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QWidget>

#include <vector>

#include "camera.h"
#include "globe.h"
#include "lighting.h"
#include "luckycat.h"
#include "room.h"
#include "shape.h"
#include "sushi.h"

class SushiBar : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  SushiBar(QWidget* parent);
  ~SushiBar();

  std::vector<Sushi*> sushis;
  LuckyCat* cat;

 private:
  Camera* camera;
  QPoint mousePosition;
  bool dragCamera = false;

  void cube();
  void drawAxis();
  void drawCat();

  QOpenGLShaderProgram* program;

  Room* room;
  Sushi* sushi;
  Lighting* lighting;
  Globe* globe;

 protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
};

#endif
