#ifndef TRACK_OBJECT_H
#define TRACK_OBJECT_H

#include "material.h"
#include "model.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <QGLWidget>

class TrackObject : public QGLWidget {
  Q_OBJECT

 public:
  TrackObject();
  ~TrackObject();

  void draw();

 protected:
  glm::vec3 _position;

  float _angle;
  float _radius;
  float _speed;
  float _angularSpeed;

  // Saving previous speeds if the track is paused
  float _oldSpeed;
  float _oldAngularSpeed;

  // Sections on the track
  bool _section1;
  bool _section2;
  bool _section3;
  bool _section4;

  void section1();
  void section2();
  void section3();
  void section4();

  void checkSection1();
  void checkSection2();
  void checkSection3();
  void checkSection4();

  void updatePosition();
  void checkPosition();
  void resetAngle();

 public slots:
  void setSpeed(int speed);
  void stopTrack();
};

#endif