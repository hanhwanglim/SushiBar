#ifndef LUCKYCAT_H
#define LUCKYCAT_H

#include <QOpenGLFunctions>
#include <QGLWidget>

#include <glm/glm.hpp>

#include "model.h"
#include "material.h"
#include "trackobject.h"

class LuckyCat : public TrackObject {
  Q_OBJECT

 public:
  LuckyCat();
  ~LuckyCat();

  void draw();

 private:
  Model* _cat_hand;
  Model* _cat_body;

  Material material;

  float _handAngle = 0.0f;

  void drawCat();
  void drawBody();
  void drawHand();

};

#endif  // LUCKYCAT_H
