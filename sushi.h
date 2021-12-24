#ifndef SUSHI_H
#define SUSHI_H

#include "trackobject.h"

class Sushi : public TrackObject {
 public:
  Sushi();
  Sushi(glm::vec3 position);

  void plate();
  void drawSushi();
  void sushi();

  void draw();
};

#endif  // SUSHI_H
