#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>

#include <string>

class Image {
 public:
  Image(const std::string& path);

  ~Image();

  unsigned char* data() const;

  unsigned int width() const { return _width; }
  unsigned int height() const { return _height; }

 private:
  Image(const Image&);

  unsigned int _width;
  unsigned int _height;

  QImage* image;

  unsigned char* _image;
};

#endif  // IMAGE_H
