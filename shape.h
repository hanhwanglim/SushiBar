#ifndef SHAPE_H
#define SHAPE_H

#include <QOpenGLFunctions>

class Shape : protected QOpenGLFunctions {
 public:
  void drawCuboid(float width, float height, float breadth, float centreX,
                  float centreY, float centreZ);

  void drawClosedCylinder(float radius, float height);
};

#endif  // SHAPE_H
