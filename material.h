#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glu.h>

struct Material {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
};

#endif  // MATERIAL_H
