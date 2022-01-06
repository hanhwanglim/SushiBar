#include "image.h"

/**
 * @brief Create image
 *
 * @param path file path
 */
Image::Image(const std::string& path) {
  image = new QImage(QString(path.c_str()));

  // Image properties
  _width = image->width();
  _height = image->height();

  _image = new unsigned char[_width * _height * 3];

  // Load image
  unsigned int nm = _width * _height;
  for (unsigned int i = 0; i < nm; i++) {
    std::div_t part = std::div((int)i, (int)_width);
    QRgb color = image->pixel(_width - part.rem - 1, part.quot);
    _image[3 * nm - 3 * i - 3] = qRed(color);
    _image[3 * nm - 3 * i - 2] = qGreen(color);
    _image[3 * nm - 3 * i - 1] = qBlue(color);
  }
}

/**
 * @brief Returns a pointer to the image data
 *
 * @return const unsigned char* Pointer to the image data
 */
const unsigned char* Image::data() const { return _image; }

Image::~Image() {
  delete _image;
  delete image;
}
