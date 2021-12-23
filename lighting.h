#ifndef LIGHTING_H
#define LIGHTING_H

#include <QOpenGLFunctions>

class Lighting : protected QOpenGLFunctions {
 public:
  Lighting();

  void setup();
};

#endif  // LIGHTING_H
