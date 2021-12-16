#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include <QOpenGLWidget>
#include <QWidget>

class SushiBar : public QOpenGLWidget {
  Q_OBJECT
 public:
  SushiBar(QWidget* parent);
  ~SushiBar();

 private:
  void cube();

 protected:
  virtual void initializeGL();
  virtual void paintGL();
  virtual void resizeGL(int w, int h);

  // virtual void mouseMoveEvent(QMouseEvent* event);
  // virtual void mousePressEvent(QMouseEvent* event);
  // virtual void mouseReleaseEvent(QMouseEvent* event);

};

#endif
