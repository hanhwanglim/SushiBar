#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include "camera.h"
 #include "model.h"

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QWidget>

class SushiBar : public QOpenGLWidget, protected QOpenGLFunctions {
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

  QOpenGLShaderProgram* program;
  Model* cat;


 protected:

   void initializeGL() ;
   void paintGL() ;
   void resizeGL(int w, int h) ;

  void mouseMoveEvent(QMouseEvent* event) ;
  void mousePressEvent(QMouseEvent* event) ;
  void mouseReleaseEvent(QMouseEvent* event) ;

};

#endif
