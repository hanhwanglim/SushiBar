#ifndef GLOBE_H
#define GLOBE_H

#include <QOpenGLFunctions>

#include "image.h"

class Globe : protected QOpenGLFunctions {
 public:
  Globe();
  ~Globe();

  void globe();
  void draw();

 private:
  Image* _image;
  float angle = 0;

  void updateAngle();
};

#endif  // GLOBE_H
