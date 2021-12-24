#include "trackobject.h"

TrackObject::TrackObject() {}

/**
 * @brief Update the position of the sushi in the track
 *
 */
void TrackObject::updatePosition() {
  if (section1) {
    position += glm::vec3(speed, 0, 0);
  }
  if (section2) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = 4.7 + (radius * cos(angle * PI / 180.0f));
      position.z = 0 + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }
  if (section3) {
    position -= glm::vec3(speed, 0, 0);
  }
  if (section4) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = -7.5 + (radius * cos(angle * PI / 180.0f));
      position.z = 0 + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }

  checkPosition();
}

/**
 * @brief Checks the position of the sushi and updates the sections
 *
 */
void TrackObject::checkPosition() {
  if (section1) {
    angle = 270.0f;
    if (position.x >= 4.5) {
      section1 = false;
      section2 = true;
    }
  }
  if (section2) {
    if (this->angle >= 90 && this->angle < 270) {
      section2 = false;
      section3 = true;
    }
  }
  if (section3) {
    angle = 90.0f;
    if (position.x <= -7.5) {
      section3 = false;
      section4 = true;
    }
  }
  if (section4) {
    if (this->angle >= 270.0f) {
      section4 = false;
      section1 = true;
    }
  }

  if (angle >= 360) angle = 0;
}

/**
 * @brief Slot to set the speed of the sushi on the track
 *
 * @param speed speed
 */
void TrackObject::setSpeed(int speed) {
  this->speed = (float)speed * 0.1f;
  this->angularSpeed = (float)speed * 8.0f;
}

/**
 * @brief Slot to stop the sushi on the track
 *
 */
void TrackObject::stopTrack() {
  if (speed > 0) {
    oldSpeed = speed;
    oldAngularSpeed = angularSpeed;
    speed = 0.0f;
  } else {
    speed = oldSpeed;
    angularSpeed = oldAngularSpeed;
  }
}

TrackObject::~TrackObject() {}