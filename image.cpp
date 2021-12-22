#include "image.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Image::Image(const std::string& file_name) {
  image = new QImage(QString(file_name.c_str()));

  _width = image->width();
  _height = image->height();

  _image = new unsigned char[_width * _height * 3];

  unsigned int nm = _width * _height;
  for (unsigned int i = 0; i < nm; i++) {
    std::div_t part = std::div((int)i, (int)_width);
    QRgb colval = image->pixel(_width - part.rem - 1, part.quot);
    _image[3 * nm - 3 * i - 3] = qRed(colval);
    _image[3 * nm - 3 * i - 2] = qGreen(colval);
    _image[3 * nm - 3 * i - 1] = qBlue(colval);
  }
}

unsigned char* Image::data() const { return _image; }

Image::~Image() {
  delete _image;
  delete image;
}