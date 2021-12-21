#ifndef LUCKYCAT_H
#define LUCKYCAT_H

#include <QOpenGLFunctions>
#include <glm/glm.hpp>

#include "model.h"

class LuckyCat : protected QOpenGLFunctions {
 public:
  LuckyCat();
  void draw();

 private:
  Model* cat_hand;
  Model* cat_body;

  glm::vec3 position;

  float handAngle = 0;
  float angle;
  float radius;
  float speed = 0.1;

  bool section1;
  bool section2;
  bool section3;
  bool section4;

  void drawCat();
  void drawBody();
  void drawHand();

  void updatePosition();
  void checkPosition();
};

#endif  // LUCKYCAT_H
