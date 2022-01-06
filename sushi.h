#ifndef SUSHI_H
#define SUSHI_H

#include <glm/glm.hpp>

#include "shape.h"
#include "trackobject.h"

class Sushi : public TrackObject {
 public:
  Sushi(glm::vec3 position);
  ~Sushi();

  void plate();
  void sushi();
  void drawSushi();

  void draw();

 private:
  Shape s;
};

#endif