#include "picture.h"

/**
 * @brief Construct a new Picture:: Picture object
 * 
 * @param path 
 */
Picture::Picture(const std::string path) { image = new Image(path); }

/**
 * @brief Binds the image onto a surface
 * 
 */
void Picture::picture() {
  glEnable(GL_TEXTURE_2D);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  // Load texture
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width(), image->height(), 0,
               GL_RGB, GL_UNSIGNED_BYTE, image->data());

  // Texture settings
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glBindTexture(GL_TEXTURE_2D, texture);

  // Frame 

  glBegin(GL_QUADS);
  glNormal3f(0.0f, 0.0f, 1.0f); 
  glTexCoord2f(1.0f, 0.0f);  glVertex3f( 1.0f, -1.0f, 0.0f); 
  glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0f, -1.0f, 0.0f); 
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0f,  1.0f, 0.0f); 
  glTexCoord2f(1.0f, 1.0f);  glVertex3f( 1.0f,  1.0f, 0.0f);
  glEnd();

  // Unbind texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

/**
 * @brief Draws picture on scene
 *
 */
void Picture::draw() { picture(); }

Picture::~Picture() { delete image; }