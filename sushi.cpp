#include "sushi.h"

#include "shape.h"

Sushi::Sushi() {
  position = glm::vec3(-4.0f, -1.5f, 0.7f);

  this->radius = 0.7f;
  this->angle = 90.0f;

  section3 = true;
}

Sushi::Sushi(glm::vec3 position) {
  this->position = position;

  if (position.z < 0.0f) {
    section1 = true;
    this->angle = 270.0f;
    this->radius = 0.7f;
  } else {
    section2 = true;
    this->angle = 90.0f;
    this->radius = 0.7f;
  }
}

/**
 * @brief Draws a sushi on the scene
 *
 */
void Sushi::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  drawSushi();
  glPopMatrix();

  updatePosition();
}

/**
 * @brief Draw the 3 sushi on a plate
 *
 */
void Sushi::drawSushi() {
  glRotatef(-this->angle, 0.0f, 1.0f, 0.0f);

  glPushMatrix();

  plate();
  // Draw 3 individual sushi on the plate
  for (int i = 0; i < 3; i++) {
    float _angle = i * 120.0f;
    glPushMatrix();
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.17f, 0.0f, 0.0f);
    sushi();
    glPopMatrix();
  }

  glPopMatrix();
}

/**
 * @brief Create sushi object
 *
 */
void Sushi::sushi() {
  Shape s;
  Material material;

  // Seaweed
  glColor3f(0.376470f, 0.396078f, 0.180392f);
  material = {{0.317894f, 0.312565f, 0.175841f, 1},
              {0.376470f, 0.396078f, 0.180392f, 1},
              {0.376470f, 0.396078f, 0.180392f, 1},
              25.2199f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.15f, 0.15f);

  // Rice
  glColor3f(0.964705f, 0.972549f, 0.929411f);
  material = {{0.951280f, 0.051287f, 0.918591f, 1},
              {0.964705f, 0.972549f, 0.929411f, 1},
              {0.964705f, 0.972549f, 0.929411f, 1},
              25.1228f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.14f, 0.1501f);

  // Cucumber
  glColor3f(0.450980f, 0.686274f, 0.349019f);
  material = {{0.450980f, 0.686274f, 0.349019f, 1.0f},
              {0.450980f, 0.686274f, 0.349019f, 1.0f},
              {0.450980f, 0.686274f, 0.349019f, 1.0f},
              25.9125f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.05f, 0.1502f);
}

/**
 * @brief Draws a plate
 *
 */
void Sushi::plate() {
  static GLUquadricObj *quad_obj = gluNewQuadric();
  static GLUquadricObj *disk = gluNewQuadric();

  const float topRadius = 0.5f;
  const float baseRadius = 0.4f;
  const float height = 0.07f;

  // Cylinder settings
  GLdouble slices = 12.0f;
  GLdouble stack = 1.0f;

  glColor3f(0.968627f, 1.0f, 0.929411f);
  Material material = {{0.968627f, 1.0f, 0.929411f, 1.0f},
                       {0.968627f, 1.0f, 0.929411f, 1.0f},
                       {0.968627f, 1.0f, 0.929411f, 1.0f},
                       25.1232f};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  glPushMatrix();
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

  // Draw plate
  gluCylinder(quad_obj, baseRadius, topRadius, height, slices, stack);
  gluDisk(disk, 0.0, baseRadius, slices, stack);

  glPopMatrix();
}
