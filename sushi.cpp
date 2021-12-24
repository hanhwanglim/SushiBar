#include "shape.h"
#include "sushi.h"

Sushi::Sushi()
{
    position = glm::vec3(-4, -1.5f, 0.7f);

      this->radius = 0.7f;
      this->angle = 90.0f;

      section3 = true;
}

Sushi::Sushi(glm::vec3 position) {
  this->position = position;

  if (position.z < 0) {
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
  glRotatef(-this->angle, 0, 1, 0);
  glPushMatrix();
  plate();
  for (int i = 0; i < 3; i++) {
    float _angle = i * 120.0f;
    glPushMatrix();
    glRotatef(_angle, 0, 1, 0);
    glTranslatef(0.17, 0, 0);
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
  glColor3f(0.37647059, 0.39607843, 0.18039216);
  material = {{0.37647059, 0.39607843, 0.18039216, 1},
              {0.37647059, 0.39607843, 0.18039216, 1},
              {0.37647059, 0.39607843, 0.18039216, 1},
              25};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.15, 0.15);

  // Rice
  glColor3f(0.96470588, 0.97254902, 0.92941176);
  material = {{0.96470588, 0.97254902, 0.92941176, 1},
              {0.96470588, 0.97254902, 0.92941176, 1},
              {0.96470588, 0.97254902, 0.92941176, 1},
              25};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.14, 0.1501);

  // Cucumber
  glColor3f(0.45098039, 0.68627451, 0.34901961);
  material = {{0.45098039, 0.68627451, 0.34901961, 1},
              {0.45098039, 0.68627451, 0.34901961, 1},
              {0.45098039, 0.68627451, 0.34901961, 1},
              25};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawClosedCylinder(0.05, 0.1502);
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

  glColor3f(0.96862745, 1.0, 0.92941176);
  Material material = {{0.96862745, 1.0, 0.92941176, 1},
              {0.96862745, 1.0, 0.92941176, 1},
              {0.96862745, 1.0, 0.92941176, 1},
              25};
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  glPushMatrix();
  glRotatef(-90, 1, 0, 0);
  
  // Draw plate
  gluCylinder(quad_obj, baseRadius, topRadius, height, slices, stack);
  gluDisk(disk, 0, baseRadius, slices, stack);

  glPopMatrix();
}
