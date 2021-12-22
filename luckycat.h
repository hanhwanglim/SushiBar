#ifndef LUCKYCAT_H
#define LUCKYCAT_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <glm/glm.hpp>

#include "model.h"
#include "material.h"

class LuckyCat : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  LuckyCat();

  void draw();

 private:
  Model* cat_hand;
  Model* cat_body;

  Material material;

  glm::vec3 position;

  float handAngle = 0;
  float angle;
  float radius;
  float speed = 0.1;
  float angularSpeed = 8.0f;
  
  float oldSpeed = 0;
  float oldAngularSpeed = 0;

  bool section1;
  bool section2;
  bool section3;
  bool section4;

  void drawCat();
  void drawBody();
  void drawHand();

  void updatePosition();
  void checkPosition();

 public slots:
  void setSpeed(int speed);
  void stopTrack();
};

#endif  // LUCKYCAT_H
