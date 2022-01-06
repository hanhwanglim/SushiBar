#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "camera.h"
#include "luckycat.h"
#include "room.h"
#include "shape.h"
#include "sushi.h"

#include <QGLWidget>
#include <QImage>
#include <QMouseEvent>

#include <vector>

class SushiBar : public QGLWidget {
  Q_OBJECT

 public:
  SushiBar(QWidget* parent);
  ~SushiBar();

  std::vector<Sushi*> _sushis;
  LuckyCat* _cat;

 protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);

 private:
  void drawAll();
  void axis();
  void createSushis();

  Camera* _camera;
  QPoint _mousePos;
  bool _dragCamera = false;

  Room* _room;
};

#endif
