#ifndef GLOBE_H
#define GLOBE_H

#include <QOpenGLFunctions>

#include <gl/GLU.h>

#include "image.h"

class Globe : protected QOpenGLFunctions {
 public:
  Globe();

  void globe();
  void draw();

 private:
  Image* _image;

  unsigned int texture;

  float angle = 0;

  void updateAngle();
};

#endif  // GLOBE_H
