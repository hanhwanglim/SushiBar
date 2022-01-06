#include "material.h"
#include "sushi.h"

#include <GL/glu.h>

/**
 * @brief Construct a new Sushi:: Sushi object
 * 
 * @param position 
 */
Sushi::Sushi(glm::vec3 position) {
  _position = position;

  if (position.z < 0) {
    _angle = 270.0f;
    _section1 = true;
    _section2 = false;
    _section3 = false;
    _section4 = false;
  } else {
    _angle = 90.0f;
    _section1 = false;
    _section2 = false;
    _section3 = true;
    _section4 = false;
  }
}

/**
 * @brief Draws the sushi in the scene
 * 
 */
void Sushi::draw() {
  glPushMatrix();
  glTranslatef(_position.x, _position.y, _position.z);
  drawSushi();
  glPopMatrix();

  updatePosition();
}

/**
 * @brief Draws 3 sushi on a plate
 * 
 */
void Sushi::drawSushi() {
  glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
  glPushMatrix();

  plate();

  // Draw 3 sushi on the plate
  for (int i = 0; i < 3; i++) {
    float angle = i * 120.0f;
    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.17f, 0.0f, 0.0f);
    sushi();
    glPopMatrix();
  }

  glPopMatrix();
}

/**
 * @brief Draws an individual sushi
 * 
 */
void Sushi::sushi() {
  const float SUSHI_RADIUS = 0.15f;
  const float SUSHI_HEIGHT = 0.15f;

  // Seaweed
  glMaterialfv(GL_FRONT, GL_AMBIENT, GREEN_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, GREEN_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, GREEN_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, GREEN_PLASTIC.shininess);
  s.drawClosedCylinder(SUSHI_RADIUS, SUSHI_HEIGHT);

  // Rice
  glMaterialfv(GL_FRONT, GL_AMBIENT, WHITE_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, WHITE_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, WHITE_PLASTIC.shininess);
  s.drawClosedCylinder(SUSHI_RADIUS - 0.01, SUSHI_HEIGHT + 0.001f);

  glMaterialfv(GL_FRONT, GL_AMBIENT, YELLOW_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, YELLOW_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, YELLOW_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, YELLOW_PLASTIC.shininess);
  s.drawClosedCylinder(SUSHI_RADIUS / 3.0f, SUSHI_HEIGHT + 0.001f);
}

/**
 * @brief Draws a plate
 * 
 */
void Sushi::plate() {
  GLUquadricObj* quad = gluNewQuadric();
  GLUquadricObj* disk = gluNewQuadric();

  const float TOP_RADIUS = 0.5f;
  const float BASE_RADIUS = 0.4f;
  const float HEIGHT = 0.07f;

  GLdouble slices = 12.0f;
  GLdouble stack = 1.0f;

  glMaterialfv(GL_FRONT, GL_AMBIENT, RED_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, RED_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, RED_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, RED_PLASTIC.shininess);

  // Draw cylinder
  glPushMatrix();
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
  gluCylinder(quad, BASE_RADIUS, TOP_RADIUS, HEIGHT, slices, stack);
  gluDisk(disk, 0.0, BASE_RADIUS, slices, stack);
  glPopMatrix();
}

Sushi::~Sushi() {}