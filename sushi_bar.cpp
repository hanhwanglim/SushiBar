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

  program = new QOpenGLShaderProgram(this);
  cat = nullptr;
}

void SushiBar::cube() {
  glColor3f(1.0f, 0.0f, 0.0f);
  GLUquadric* quad = gluNewQuadric();
  gluCylinder(quad, 2, 1, 1, 12, 12);
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

  // Shaders
  if (!program->addShaderFromSourceFile(QOpenGLShader::Vertex, "C:\\Users\\hanhw\\Desktop\\Computer Graphics\\SushiBar\\shaders\\model.vert")) {
      std::cout << "Vertex shader compile failed" << std::endl;
  }
  if (!program->addShaderFromSourceFile(QOpenGLShader::Fragment, "C:\\Users\\hanhw\\Desktop\\Computer Graphics\\SushiBar\\shaders\\model.frag")) {
      std::cout << "Fragment shader compile failed" << std::endl;
  }
  if (!program->link()) {
      std::cout << "Linking failed" << std::endl;
  }

  cat = new Model("C:\\Users\\hanhw\\Desktop\\Computer Graphics\\SushiBar\\models\\cat_body.obj");
}

void SushiBar::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
//  this->cube();
  this->drawAxis();

  QMatrix4x4 model;
  model.scale(0.15, 0.15, 0.15);
  if (!program->bind()) std::cout << "bind failed" << std::endl;
  program->setUniformValue("model", model);
  cat->draw(program);
  program->release();
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

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float ortho = 10.0f;
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
