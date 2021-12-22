#include "picture.h"

Picture::Picture() {
  image = new Image(
      "C:\\Users\\hanhw\\Desktop\\Computer "
      "Graphics\\SushiBar\\textures\\Marc_Dekamps.ppm");
}

Picture::Picture(const std::string path) { image = new Image(path); }

void Picture::picture() {
  initializeOpenGLFunctions();

  glEnable(GL_TEXTURE_2D);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width(), image->height(), 0,
               GL_RGB, GL_UNSIGNED_BYTE, image->data());
  glGenerateMipmap(GL_TEXTURE_2D);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glBindTexture(GL_TEXTURE_2D, texture);

  // Frame

  glNormal3f(0, 0, 1);
  glBegin(GL_POLYGON);

  glTexCoord2f(1, 0);
  glVertex3f(1, -1, 0);

  glTexCoord2f(0, 0);
  glVertex3f(-1, -1, 0);

  glTexCoord2f(0, 1);
  glVertex3f(-1, 1, 0);

  glTexCoord2f(1, 1);
  glVertex3f(1, 1, 0);

  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

void Picture::draw() {
  glPushMatrix();
  glTranslatef(0, 1, -6.9);
  picture();
  glPopMatrix();
}