#ifndef PICTURE_H
#define PICTURE_H


#include <QOpenGLFunctions>

#include <gl/GLU.h>

#include <string>

#include "image.h"

class Picture : protected QOpenGLFunctions {
 public:
  Picture();
  Picture(const std::string path);

  void picture();
  void draw();

 private:
  Image* image;
  unsigned int texture;
};

#endif  // PICTURE_H
