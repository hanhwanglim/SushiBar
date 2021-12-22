#include "sushi.h"

#include <gl/GLU.h>

#include <iostream>

#include "shape.h"

Sushi::Sushi() {
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

void Sushi::draw() {
  if (section1 || section3) {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    drawSushi();
    glPopMatrix();

  } else if (section2 || section4) {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    drawSushi();
    glPopMatrix();
  }

  updatePosition();
}

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

void Sushi::updatePosition() {
  if (section1) {
    position += glm::vec3(speed, 0, 0);
  }
  if (section2) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = 4.7 + (radius * cos(angle * PI / 180.0f));
      position.z = 0 + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }
  if (section3) {
    position -= glm::vec3(speed, 0, 0);
  }
  if (section4) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = -9 + (radius * cos(angle * PI / 180.0f));
      position.z = 0 + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }

  checkPosition();
}

void Sushi::checkPosition() {
  if (section1) {
    if (position.x >= 4.5) {
      section1 = false;
      section2 = true;
    }
  }
  if (section2) {
    if (this->angle >= 90 && this->angle < 270) {
      section2 = false;
      section3 = true;
    }
  }
  if (section3) {
    if (position.x <= -9.0) {
      section3 = false;
      section4 = true;
    }
  }
  if (section4) {
    if (this->angle >= 270.0f) {
      section4 = false;
      section1 = true;
    }
  }

  if (angle >= 360) angle = 0;
}

void Sushi::sushi() {
  Shape s;

  // Seaweed
  glColor3f(0.37647059, 0.39607843, 0.18039216);
  s.drawClosedCylinder(0.15, 0.15);

  // Rice
  glColor3f(0.96470588, 0.97254902, 0.92941176);
  s.drawClosedCylinder(0.14, 0.1501);

  // Cucumber
  glColor3f(0.45098039, 0.68627451, 0.34901961);
  s.drawClosedCylinder(0.05, 0.1502);
}

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

  glPushMatrix();
  glRotatef(-90, 1, 0, 0);
  // Draw cylinder
  gluCylinder(quad_obj, baseRadius, topRadius, height, slices, stack);

  gluDisk(disk, 0, baseRadius, slices, stack);

  glPopMatrix();
}

void Sushi::setSpeed(int speed) {
  this->speed = (float)speed * 0.1f;
  this->angularSpeed = (float)speed * 8.0f;
}

void Sushi::stopTrack() {
  if (speed > 0) {
    oldSpeed = speed;
    oldAngularSpeed = angularSpeed;
    speed = 0.0f;
  } else {
    speed = oldSpeed;
    angularSpeed = oldAngularSpeed;
  }
}