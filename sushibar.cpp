#include "sushibar.h"

#include <GL/glu.h>

/**
 * @brief Construct a new Sushi Bar:: Sushi Bar object
 * 
 * @param parent 
 */
SushiBar::SushiBar(QWidget* parent) : QGLWidget(parent) {
  // Create objects
  _camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f));
  _room = new Room();
  _cat = new LuckyCat();
  createSushis();
}

/**
 * @brief Initialise OpenGL functions
 * 
 */
void SushiBar::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.3, 0.3, 0.3, 0.0);
}

/**
 * @brief Called when window is resized
 * 
 * @param w width of window
 * @param h height of window
 */
void SushiBar::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  // Lighting
  GLfloat light_pos[] = {0., 0., 1., 0.};

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.);

  // Perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  const float ORTHO = 20.0f;
  glOrtho(-ORTHO, ORTHO, -ORTHO, ORTHO, -ORTHO, ORTHO);
}

/**
 * @brief Draws axis onto the scene
 * 
 */
void SushiBar::axis() {
  const float LINE_LENGTH = 100.0f;

  glBegin(GL_LINES);

  // x-axis encoded in red
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(LINE_LENGTH, 0.0f, 0.0f);
  glVertex3f(-LINE_LENGTH, 0.0f, 0.0f);

  // y-axis encoded in red
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, LINE_LENGTH, 0.0f);
  glVertex3f(0.0f, -LINE_LENGTH, 0.0f);

  // z-axis encoded in red
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, LINE_LENGTH);
  glVertex3f(0.0f, 0.0f, -LINE_LENGTH);

  glEnd();
}

/**
 * @brief Draws everything in the scene
 * 
 */
void SushiBar::drawAll() {
  _room->drawAll();

  for (Sushi* sushi : _sushis) sushi->draw();

  _cat->draw();
}

/**
 * @brief Creates sushis in the track
 * 
 */
void SushiBar::createSushis() {
  const float X_RANGE[2] = {-6.0f, 0.0f};
  const float Z_RANGE[2] = {-0.7f, 2.0f};

  const float X_INTERVAL = 4.0f;
  const float y = -1.6f;
  const float Z_INTERVAL = 1.4f;

  for (float x = X_RANGE[0]; x < X_RANGE[1]; x += X_INTERVAL) {
    for (float z = Z_RANGE[0]; z < Z_RANGE[1]; z += Z_INTERVAL) {
      Sushi* sushi = new Sushi(glm::vec3(x, y, z));
      _sushis.push_back(sushi);
    }
  }
}

/**
 * @brief Paints scene
 * 
 */
void SushiBar::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw scene
  glMatrixMode(GL_MODELVIEW);
  const float SCALE = 1.5;
  glScalef(SCALE, SCALE, SCALE);
  drawAll();

  // Camera
  glLoadIdentity();

  glm::vec3 cameraPos = _camera->position();
  glm::vec3 cameraTar = _camera->target();
  glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);
  gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, cameraTar.x, cameraTar.y,
            cameraTar.z, cameraUp.x, cameraUp.y, cameraUp.z);

  glFlush();
}

/**
 * @brief Mouse move event
 * 
 * @param event Mouse event
 */
void SushiBar::mouseMoveEvent(QMouseEvent* event) {
  if (_dragCamera) {
    QPoint mousePos = event->pos();
    float dx = mousePos.x() - _mousePos.x();
    float dy = _mousePos.y() - mousePos.y();

    _mousePos = mousePos;

    _camera->handleMouseEvent(dx, dy);
  }
}

/**
 * @brief Mouse press event
 * 
 * @param event Mouse event
 */
void SushiBar::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    _dragCamera = true;
    _mousePos = event->pos();
  }
}

/**
 * @brief Mouse release event
 * 
 */
void SushiBar::mouseReleaseEvent(QMouseEvent*) { _dragCamera = false; }

SushiBar::~SushiBar() {
  delete _room;
  delete _cat;
  delete _camera;

  for (Sushi* sushi : _sushis) delete sushi;
}