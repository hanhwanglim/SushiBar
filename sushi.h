#ifndef SUSHI_H
#define SUSHI_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include <glm/glm.hpp>

#include "material.h"

class Sushi : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  Sushi();
  Sushi(glm::vec3 position);

  void draw();

 private:
  glm::vec3 position;

  float angle;
  float speed = 0.1f;
  float angularSpeed = 8.0f;
  float radius;

  // Saving speeds if the track is paused
  float oldAngularSpeed = 0;
  float oldSpeed = 0;

  // Track section
  bool section1 = false;
  bool section2 = false;
  bool section3 = false;
  bool section4 = false;

  float updateAngle();

  void updatePosition();
  void checkPosition();

  void plate();
  void drawSushi();
  void sushi();

 public slots:
  void setSpeed(int speed);
  void stopTrack();
};

#endif
