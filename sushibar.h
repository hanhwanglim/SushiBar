#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QWidget>

#include <vector>

#include "camera.h"
#include "globe.h"
#include "lighting.h"
#include "luckycat.h"
#include "room.h"
#include "shape.h"
#include "sushi.h"

class SushiBar : public QGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  SushiBar(QWidget* parent);
  ~SushiBar();

  std::vector<Sushi*> sushis;
  LuckyCat* cat;

 private:
  // Camera settings

  Camera* camera;
  QPoint mousePosition;
  bool dragCamera = false;

  // Objects

  Room* room;
  Sushi* sushi;
  Lighting* lighting;
  Globe* globe;

  // Timer
  QTimer* timer;

  void drawAxis();

 protected:
  // OpenGL functions
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  // Mouse events
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
};

#endif
