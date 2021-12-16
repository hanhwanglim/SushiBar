#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include "camera.h"

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QWidget>

class SushiBar : public QOpenGLWidget {
  Q_OBJECT
 public:

  SushiBar(QWidget* parent);
  ~SushiBar();

 private:

  Camera* camera;
  QPoint mousePosition;
  bool dragCamera = false;
  
  void cube();
  void drawAxis();

 protected:

   void initializeGL() ;
   void paintGL() ;
   void resizeGL(int w, int h) ;

  void mouseMoveEvent(QMouseEvent* event) ;
  void mousePressEvent(QMouseEvent* event) ;
  void mouseReleaseEvent(QMouseEvent* event) ;

};

#endif
