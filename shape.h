#ifndef SHAPE_H
#define SHAPE_H

class Shape {
 public:
  void drawCuboid(float w, float h, float d, float x, float y, float z);
  void drawClosedCylinder(float radius, float height);
};

#endif