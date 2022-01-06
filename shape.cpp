#include "shape.h"

#include <GL/glu.h>

/**
 * @brief Draws a cuboid onto the scene
 *
 * @param w width
 * @param h height
 * @param d depth
 * @param x centre x
 * @param y centre y
 * @param z centre z
 */
void Shape::drawCuboid(float w, float h, float d, float x, float y, float z) {
  // Centralise coordinates
  x = x - (w / 2.0f);
  y = y - (h / 2.0f);
  z = z - (d / 2.0f);

  GLfloat normals[6][3] = {{ 1.0f,  0.0f,  0.0f},    // Right
                           {-1.0f,  0.0f,  0.0f},   // Left
                           { 0.0f,  0.0f,  1.0f},    // Front
                           { 0.0f,  0.0f, -1.0f},   // Back
                           { 0.0f,  1.0f,  0.0f},    // Top
                           { 0.0f, -1.0f,  0.0f}};  // Bottom

  // Right
  glNormal3fv(normals[0]);
  glBegin(GL_POLYGON);
  glVertex3f(x + w, y + 0, z + d);
  glVertex3f(x + w, y + 0, z + 0);
  glVertex3f(x + w, y + h, z + 0);
  glVertex3f(x + w, y + h, z + d);
  glEnd();

  // Back
  glNormal3fv(normals[3]);
  glBegin(GL_POLYGON);
  glVertex3f(x + 0, y + 0, z + 0);
  glVertex3f(x + w, y + 0, z + 0);
  glVertex3f(x + w, y + h, z + 0);
  glVertex3f(x + 0, y + h, z + 0);
  glEnd();

  // Front
  glNormal3fv(normals[2]);
  glBegin(GL_POLYGON);
  glVertex3f(x + 0, y + 0, z + d);
  glVertex3f(x + w, y + 0, z + d);
  glVertex3f(x + w, y + h, z + d);
  glVertex3f(x + 0, y + h, z + d);
  glEnd();

  // Left
  glNormal3fv(normals[1]);
  glBegin(GL_POLYGON);
  glVertex3f(x + 0, y + 0, z + d);
  glVertex3f(x + 0, y + 0, z + 0);
  glVertex3f(x + 0, y + h, z + 0);
  glVertex3f(x + 0, y + h, z + d);
  glEnd();

  // Top
  glNormal3fv(normals[4]);
  glBegin(GL_POLYGON);
  glVertex3f(x + w, y + h, z + d);
  glVertex3f(x + w, y + h, z + 0);
  glVertex3f(x + 0, y + h, z + 0);
  glVertex3f(x + 0, y + h, z + d);
  glEnd();

  // Bottom
  glNormal3fv(normals[5]);
  glBegin(GL_POLYGON);
  glVertex3f(x + w, y + 0, z + d);
  glVertex3f(x + w, y + 0, z + 0);
  glVertex3f(x + 0, y + 0, z + 0);
  glVertex3f(x + 0, y + 0, z + d);
  glEnd();
}

/**
 * @brief Draws a closed cylinder
 *
 * @param radius radius
 * @param height height
 */
void Shape::drawClosedCylinder(float radius, float height) {
  float y = height / 2.0f;  // Centre coordinates for cylinder

  GLUquadricObj* quad = gluNewQuadric();
  GLUquadricObj* disk1 = gluNewQuadric();
  GLUquadricObj* disk2 = gluNewQuadric();

  GLdouble slices = 12.0;
  GLdouble stack = 1.0f;

  glPushMatrix();

  // Draw hollow cylinder
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
  glTranslatef(0.0f, 0.0f, -y);
  gluCylinder(quad, radius, radius, height, slices, stack);

  // Draw closing disks
  gluDisk(disk1, 0, radius, slices, stack);
  glTranslatef(0.0f, 0.0f, height);
  gluDisk(disk2, 0, radius, slices, stack);

  glPopMatrix();
}