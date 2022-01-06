/*
 * Code was sourced and modified from SolidCube texture tutorial
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>

#include <string>

class Image {
 public:
  Image(const std::string& path);

  ~Image();

  const unsigned char* data() const;

  /**
   * @brief Returns the width of the image
   * 
   * @return unsigned int width
   */
  unsigned int width() const { return _width; }

  /**
   * @brief Returns the height of the image
   * 
   * @return unsigned int height
   */
  unsigned int height() const { return _height; }

 private:
  Image(const Image&);

  unsigned int _width;
  unsigned int _height;

  QImage* image;

  unsigned char* _image;
};

#endif
