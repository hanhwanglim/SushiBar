#include "shape.h"

#include <gl/GLU.h>

void Shape::drawCuboid(float width, float height, float breadth, float centreX,
                       float centreY, float centreZ) {
  float w = width;
  float h = height;
  float b = breadth;

  float x = centreX - (w / 2.0);
  float y = centreY - (h / 2.0);
  float z = centreZ - (b / 2.0);

  glBegin(GL_QUADS);
  // Front
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(x + w, y, z + b);
  glVertex3f(x + w, y + h, z + b);
  glVertex3f(x, y + h, z + b);
  glVertex3f(x, y, z + b);

  // Back
  glNormal3f(0.0f, 0.0f, -1.0f);
  glVertex3f(x + w, y, z);
  glVertex3f(x + w, y + h, z);
  glVertex3f(x, y + h, z);
  glVertex3f(x, y, z);

  // Right
  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(x + w, y, z);
  glVertex3f(x + w, y + h, z);
  glVertex3f(x + w, y + h, z + b);
  glVertex3f(x + w, y, z + b);

  // Left
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(x, y, z);
  glVertex3f(x, y + h, z);
  glVertex3f(x, y + h, z + b);
  glVertex3f(x, y, z + b);

  // Bottom
  glNormal3f(0.0f, -1.0f, 0.0f);
  glVertex3f(x + w, y, z);
  glVertex3f(x, y, z);
  glVertex3f(x, y, z + b);
  glVertex3f(x + w, y, z + b);

  // Top
  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(x + w, y + h, z);
  glVertex3f(x, y + h, z);
  glVertex3f(x, y + h, z + b);
  glVertex3f(x + w, y + h, z + b);
  glEnd();
}

void Shape::drawClosedCylinder(float radius, float height) {
  // TODO: use gluDisk
  static GLUquadricObj *quad_obj = gluNewQuadric();
  static GLUquadricObj *disk1 = gluNewQuadric();
  static GLUquadricObj *disk2 = gluNewQuadric();
  

  // Cylinder settings
  GLdouble slices = 12.0f;
  GLdouble stack = 1.0f;

  glPushMatrix();
  glRotatef(-90, 1, 0, 0);
  // Draw cylinder
  gluCylinder(quad_obj, radius, radius, height, slices, stack);

  gluDisk(disk1, 0, radius, slices, stack);
  glTranslatef(0, 0, height);
  gluDisk(disk2, 0, radius, slices, stack);
  
  glPopMatrix();
}
