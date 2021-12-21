#include "sushi_bar.h"

#include <gl/GLU.h>

#include <QTimer>

#include <glm/gtx/string_cast.hpp>
#include <iostream>

SushiBar::SushiBar(QWidget* parent) : QOpenGLWidget(parent) {
  // Setup camera
  glm::vec3 cameraPosition(0.0f, 0.0f, 0.0f);
  this->camera = new Camera(cameraPosition);

  // Setup timer
  QTimer* timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, QOverload<>::of(&SushiBar::update));
  timer->start(100);

  

  room = new Room();
  sushi = new Sushi();
  cat = new LuckyCat();
  lighting = new Lighting();
}

void SushiBar::drawAxis() {
  GLfloat lineLength = 100.0f;

  glBegin(GL_LINES);

  // x-axis encoded in red
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(-lineLength, 0.0, 0.0);
  glVertex3f(lineLength, 0.0, 0.0);

  // y-axis encoded in green
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0, -lineLength, 0.0);
  glVertex3f(0.0, lineLength, 0.0);

  // z-axis encoded in blue
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0, 0.0, -lineLength);
  glVertex3f(0.0, 0.0, lineLength);

  glEnd();
}



void SushiBar::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void SushiBar::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  // this->drawAxis();
  // glPushMatrix();
  // // glScalef(2.0,2.0,2.0);
  // glPushMatrix();
  // // glScalef(10,10,10);
  // sushi->draw();
  // glPopMatrix();
  room->drawAll();
  // glPopMatrix();
  //  this->drawCat();
cat->draw();
  lighting->setup();
  glLoadIdentity();


  // Camera properties
  glm::vec3 cameraPosition = camera->position();
  glm::vec3 cameraTarget = camera->target();
  glm::vec3 cameraUp(0, 1, 0);

  gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, 
            cameraTarget.x, cameraTarget.y, cameraTarget.z, 
            cameraUp.x, cameraUp.y, cameraUp.z);

  glFlush();
}

void SushiBar::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // lighting->setup();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float ortho = 20.0f;
  glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
}


void SushiBar::mouseMoveEvent(QMouseEvent* event) {
  if (dragCamera) {
    QPoint newMousePosition = event->pos();
    float dx = newMousePosition.x() - mousePosition.x();
    float dy = mousePosition.y() - newMousePosition.y();

    mousePosition = newMousePosition;

    camera->handleMouseEvent(dx, dy);
  }
}

void SushiBar::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    dragCamera = true;
    mousePosition = event->pos();
  }
}

void SushiBar::mouseReleaseEvent(QMouseEvent* event) { dragCamera = false; }

SushiBar::~SushiBar() {}
