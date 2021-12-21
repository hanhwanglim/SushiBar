#ifndef SUSHI_H
#define SUSHI_H

#include <QOpenGLFunctions>
#include <glm/glm.hpp>

class Sushi : protected QOpenGLFunctions {
 public:
  Sushi();
  Sushi(glm::vec3 position);
  void draw();

 private:
  glm::vec3 position;

  float angle;

  float speed = 0.1f;
  
  float radius;

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
};

#endif
