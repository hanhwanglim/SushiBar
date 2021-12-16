#include "sushi_bar.h"

#include <gl/GLU.h>

#include <QTimer>

SushiBar::SushiBar(QWidget* parent) : QOpenGLWidget(parent) {


  // Setup timer
  QTimer* timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, QOverload<>::of(&SushiBar::update));
  timer->start(100);
}

void SushiBar::cube() {
  glColor3f(1.0f, 0.0f, 0.0f);
  GLUquadric* quad = gluNewQuadric();
  gluSphere(quad, 1, 12, 12);
}

void SushiBar::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void SushiBar::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  this->cube();
  glLoadIdentity();

  gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);

  glFlush();
}

void SushiBar::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float ortho = 5.0f;
  glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
}



SushiBar::~SushiBar() {}
