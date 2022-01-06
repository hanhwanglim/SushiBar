#include "globe.h"
#include "material.h"

#include <GL/glu.h>

/**
 * @brief Construct a new Globe:: Globe object.
 * 
 */
Globe::Globe() { _image = new Image("./textures/Mercator-projection.ppm"); }

/**
 * @brief Create the globe object.
 * 
 */
void Globe::globe() {
  // Stand
  glMaterialfv(GL_FRONT, GL_AMBIENT, SILVER.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, SILVER.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, SILVER.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, SILVER.shininess);

  glPushMatrix();

  // Base
  s.drawClosedCylinder(0.7f, 0.2f);
  glTranslatef(0.0f, 0.2f, 0.0f);
  // Rod
  s.drawClosedCylinder(0.2f, 0.7f);
  glTranslatef(0.0f, 1.2f, 0.0f);

  // Globe
  const float RADIUS = 1.0f;
  const float SLICES = 12.0f;
  const float STACKS = SLICES;

  GLUquadricObj* quad = gluNewQuadric();

  // Setup texture
  glEnable(GL_TEXTURE_2D);
  unsigned int _tex;
  glGenTextures(1, &_tex);
  glBindTexture(GL_TEXTURE_2D, _tex);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image->Width(), _image->Height(), 0,
               GL_RGB, GL_UNSIGNED_BYTE, _image->imageField());

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  gluQuadricDrawStyle(quad, GLU_FILL);
  gluQuadricTexture(quad, GL_TRUE);
  gluQuadricNormals(quad, GLU_SMOOTH);

  glPushMatrix();
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  // Rotate upright
  glPushMatrix();

  glRotatef(_angle, 0.0f, 0.0f, 1.0f);  // Perform rotation
  gluSphere(quad, RADIUS, SLICES, STACKS);

  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

  // Unbind texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

/**
 * @brief Draw the globe onto the scene.
 * 
 */
void Globe::drawGlobe() {
  const float COORD[3] = {4.0f, -1.8f, 3.0f};

  glPushMatrix();
  glTranslatef(COORD[0], COORD[1], COORD[2]);
  glPushMatrix();
  globe();
  glPopMatrix();
  glPopMatrix();

  updateAngle();
}

/**
 * @brief Updates the angle of the globe every tick.
 * 
 */
void Globe::updateAngle() { _angle += 5.0f; }

Globe::~Globe() { delete _image; }