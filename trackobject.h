#ifndef TRACK_OBJECT_H
#define TRACK_OBJECT_H

#include <QOpenGLFunctions>
#include <QGLWidget>
#include <glm/glm.hpp>

#include "model.h"
#include "material.h"

class TrackObject : public QGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  TrackObject();
  ~TrackObject();

  void draw();

 protected:
  glm::vec3 position;

  float angle;
  float radius;
  float speed = 0.1;
  float angularSpeed = 8.0f;

  // Saving speeds if the track is paused
  float oldSpeed = 0;
  float oldAngularSpeed = 0;

  // Sections on the track
  bool section1;
  bool section2;
  bool section3;
  bool section4;

  void updatePosition();
  void checkPosition();

 public slots:
  void setSpeed(int speed);
  void stopTrack();
};

#endif  // TRACK_OBJECT_H
