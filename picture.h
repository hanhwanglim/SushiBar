#ifndef PICTURE_H
#define PICTURE_H


#include <QOpenGLFunctions>

#include <GL/glu.h>

#include <string>

#include "image.h"

class Picture : protected QOpenGLFunctions {
 public:
  Picture();
  Picture(const std::string path);
  ~Picture();

  void picture();
  void draw();

 private:
  Image* image;
  unsigned int texture;
};

#endif  // PICTURE_H
