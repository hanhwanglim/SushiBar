#ifndef GLOBE_H
#define GLOBE_H

#include "image.h"
#include "shape.h"

class Globe {
 public:
  Globe();
  ~Globe();

  void globe();
  void drawGlobe();

 private:
  Image* _image;    // Texture image
  Shape s;          // Object to construct shapes

  float _angle;     // Angle to control rotation of globe

  void updateAngle();
};

#endif
