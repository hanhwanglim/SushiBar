#include "lighting.h"
#include "shape.h"
Lighting::Lighting()
{

}

void Lighting::lightModel(const float lightPos[4]) {
  Shape s;
  glPushMatrix();
  glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
  s.drawClosedCylinder(2, 2);
  glTranslatef(0, 2, 0);
  s.drawClosedCylinder(0.5, 1);
  glPopMatrix();
}

void Lighting::setup() {
  initializeOpenGLFunctions();

  glEnable(GL_LIGHTING);

  const float lightDir[3] = {0.0f, -1.0f, 0.0f};

  glEnable(GL_LIGHT0);
  const float lightPos0[4] = {-6.0f, 4.0f, 0.0f, 0.0f};
  lightModel(lightPos0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDir);

  glEnable(GL_LIGHT1);
  const float lightPos1[4] = {0.0f, 4.0f, 0.0f, 0.0f};
  lightModel(lightPos1);
  glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDir);

  glEnable(GL_LIGHT2);
  const float lightPos2[4] = {6.0f, 4.0f, 0.0f, 0.0f};
  lightModel(lightPos2);
  glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
  glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180);
  glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightDir);
}