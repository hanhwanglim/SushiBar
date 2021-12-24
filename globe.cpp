#include "globe.h"
#include "shape.h"

#include <gl/GLU.h>

#include <filesystem>
#include <iostream>

Globe::Globe() {
  _image = new Image(
      "C:\\Users\\hanhw\\Desktop\\Computer "
      "Graphics\\SushiBar\\textures\\Mercator-projection.ppm");
}

/**
 * @brief Draw the globe onto the scene
 *
 */
void Globe::draw() {
  glPushMatrix();
  glTranslatef(4, -1.8, 3);
  glPushMatrix();
  globe();
  glPopMatrix();
  glPopMatrix();

  updateAngle();
}

/**
 * @brief Create the globe object
 *
 */
void Globe::globe() {
  initializeOpenGLFunctions();

  Shape s;
  // Draw base
  glColor3f(0.4, 0.4, 0.4);
  glPushMatrix();
  s.drawClosedCylinder(0.7, 0.2);
  glTranslatef(0, 0.2, 0);
  s.drawClosedCylinder(0.2, 0.7);
  glTranslatef(0, 1.2, 0);

  glColor3f(1, 1, 1);

  glEnable(GL_TEXTURE_2D);

  // Setup texture
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image->width(), _image->height(), 0,
               GL_RGB, GL_UNSIGNED_BYTE, _image->data());

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  static GLUquadricObj* quad = gluNewQuadric();
  // Bind texture to object
  glBindTexture(GL_TEXTURE_2D, texture);
  gluQuadricDrawStyle(quad, GLU_FILL);
  gluQuadricTexture(quad, GL_TRUE);
  gluQuadricNormals(quad, GLU_SMOOTH);

  glPushMatrix();
  glRotatef(-90, 1, 0, 0);
  glPushMatrix();
  glRotatef(angle, 0, 0, 1);  // Perform rotation
  gluSphere(quad, 1.0, 12, 12);
  glPopMatrix();
  glPopMatrix();

  // Unbind texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);

  glPopMatrix();
}

/**
 * @brief Updates the angle of the globe every tick.
 *
 */
void Globe::updateAngle() { angle += 5.0f; }

Globe::~Globe() { delete _image; }