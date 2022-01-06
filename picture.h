#ifndef PICTURE_H
#define PICTURE_H

#include "image.h"

#include <string>

class Picture {
 public:
  Picture(const std::string path);
  ~Picture();

  void picture();
  void draw();

 private:
  Image* image;
  unsigned int texture;
};

#endif