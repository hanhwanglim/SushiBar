#include "lighting.h"
#include "shape.h"
Lighting::Lighting() {}

/**
 * @brief Setup lighting in the scene
 * 
 */
void Lighting::setup() {
  initializeOpenGLFunctions();

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
}
