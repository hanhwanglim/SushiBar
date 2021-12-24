#include "sushibar.h"

#include <GL/glu.h>

SushiBar::SushiBar(QWidget* parent) : QGLWidget(parent) {
  // Setup camera
  glm::vec3 cameraPosition(0.0f, 0.0f, 0.0f);
  camera = new Camera(cameraPosition);

  // Setup timer
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  const int tickRate = 100;
  timer->start(tickRate);

  // Create objects
  room = new Room();
  cat = new LuckyCat();
  lighting = new Lighting();

  // Setting up sushi positions
  float sushiPosition[] = {-6.0f, -0.7f};
  float sushiEndPos[] = {0.0f, 2.0f};
  float sushiGap[] = {4.0f, 1.4f};
  for (float x = sushiPosition[0]; x < sushiEndPos[0]; x += sushiGap[0]) {
    for (float z = sushiPosition[1]; z < sushiEndPos[1]; z += sushiGap[1]) {
      Sushi* sushi = new Sushi(glm::vec3(x, -1.6, z));
      sushis.push_back(sushi);
    }
  }
}

/**
 * @brief Draws 3D axis to help with modelling
 *
 */
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

/**
 * @brief Initialise OpenGL
 *
 */
void SushiBar::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/**
 * @brief Paint GL
 *
 */
void SushiBar::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);

  // Draw scene
  glPushMatrix();
  const float scale = 1.5f;
  glScalef(scale, scale, scale);
  for (Sushi* _sushi : sushis) _sushi->draw();
  room->drawAll();
  cat->draw();
  glPopMatrix();

  glLoadIdentity();

  // Camera properties
  glm::vec3 cameraPosition = camera->position();
  glm::vec3 cameraTarget = camera->target();
  const glm::vec3 cameraUp(0, 1, 0);

  gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z,
            cameraTarget.x, cameraTarget.y, cameraTarget.z, cameraUp.x,
            cameraUp.y, cameraUp.z);

  glFlush();
}

/**
 * @brief Called when screen is resized
 *
 * @param w width
 * @param h height
 */
void SushiBar::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  lighting->setup();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  const float ortho = 20.0f;
  glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
}

/**
 * @brief Mouse move event
 *
 * @param event Mouse event
 */
void SushiBar::mouseMoveEvent(QMouseEvent* event) {
  if (dragCamera) {
    // Update mouse position
    QPoint newMousePosition = event->pos();
    float dx = newMousePosition.x() - mousePosition.x();
    float dy = mousePosition.y() - newMousePosition.y();

    mousePosition = newMousePosition;

    camera->handleMouseEvent(dx, dy);
  }
}

/**
 * @brief Mouse press event
 *
 * @param event Mouse event
 */
void SushiBar::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    dragCamera = true;
    mousePosition = event->pos();
  }
}

/**
 * @brief Mouse release event
 *
 * @param event Mouse event
 */
void SushiBar::mouseReleaseEvent(QMouseEvent* event) { dragCamera = false; }

SushiBar::~SushiBar() {
  delete camera;
  delete timer;
  delete room;
  delete cat;
  delete lighting;

  for (Sushi* sushi : sushis) delete sushi;
}
