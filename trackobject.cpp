#include "trackobject.h"

/**
 * @brief Construct a new Track Object:: Track Object object
 * 
 */
TrackObject::TrackObject() {
  _position = glm::vec3(-4.0f, -1.5f, 0.7f);

  _angle = 90.0f;
  _radius = 0.7f;
  _speed = 0.1f;
  _angularSpeed = _speed / _radius * 180.0f / glm::pi<float>();

  _oldSpeed = 0.0f;
  _oldAngularSpeed = 0.0f;

  _section1 = false;
  _section2 = false;
  _section3 = true;
  _section4 = false;
}

/**
 * @brief Updates the position at each tick
 * 
 */
void TrackObject::updatePosition() {
  if (_section1) section1();
  if (_section2) section2();
  if (_section3) section3();
  if (_section4) section4();

  checkPosition();
}

/**
 * @brief Updates position if object is in section 1
 * 
 */
void TrackObject::section1() { _position += glm::vec3(_speed, 0.0f, 0.0f); }

/**
 * @brief Updates position if object is in section 2
 * 
 */
void TrackObject::section2() {
  const float TURNING_POINT[2] = {4.7f, 0.0f};
  if (_speed > 0) {
    float theta = _angle * glm::pi<float>() / 180.0f;
    _position.x = TURNING_POINT[0] + (_radius * glm::cos(theta));
    _position.z = TURNING_POINT[1] + (_radius * glm::sin(theta));

    _angle += _angularSpeed;
  }
}

/**
 * @brief Updates position if object is in section 3
 * 
 */
void TrackObject::section3() { _position -= glm::vec3(_speed, 0.0f, 0.0f); }

/**
 * @brief Updates position if the object is in section 4
 * 
 */
void TrackObject::section4() {
  const float TURNING_POINT[2] = {-7.5f, 0.0f};
  if (_speed > 0) {
    float theta = _angle * glm::pi<float>() / 180.0f;
    _position.x = TURNING_POINT[0] + (_radius * glm::cos(theta));
    _position.z = TURNING_POINT[1] + (_radius * glm::sin(theta));

    _angle += _angularSpeed;
  }
}

/**
 * @brief Checking position of the object at each tick
 * 
 */
void TrackObject::checkPosition() {
  if (_section1) checkSection1();
  if (_section2) checkSection2();
  if (_section3) checkSection3();
  if (_section4) checkSection4();

  resetAngle();
}

/**
 * @brief Updating parameters if object changes from section 1 to 2
 * 
 */
void TrackObject::checkSection1() {
  const float ANGLE_DIRECTION = 270.0f;
  const float TURNING_POINT = 4.5f;
  _angle = ANGLE_DIRECTION;
  if (_position.x >= TURNING_POINT) {
    _section1 = false;
    _section2 = true;
  }
}

/**
 * @brief Updating parameters if object changes from section 2 to 3
 * 
 */
void TrackObject::checkSection2() {
  const float CRITICAL_ANGLE[2] = {90.0f, 270.0f};
  if (_angle >= CRITICAL_ANGLE[0] && _angle < CRITICAL_ANGLE[1]) {
    _section2 = false;
    _section3 = true;
  }
}

/**
 * @brief Updating parameters if object changes from section 3 to 4
 * 
 */
void TrackObject::checkSection3() {
  const float ANGLE_DIRECTION = 90.0f;
  const float TURNING_POINT = -7.5f;
  _angle = ANGLE_DIRECTION;
  if (_position.x <= TURNING_POINT) {
    _section3 = false;
    _section4 = true;
  }
}

/**
 * @brief Updating parameters if object changes from section 4 to 1
 * 
 */
void TrackObject::checkSection4() {
  const float CRITICAL_ANGLE = 270.0f;
  if (_angle >= CRITICAL_ANGLE) {
    _section4 = false;
    _section1 = true;
  }
}

/**
 * @brief resets angle when overflow
 * 
 */
void TrackObject::resetAngle() {
  if (_angle >= 360.0f) _angle = 0.0f;
}

/**
 * @brief Slot to change the speed of the track
 * 
 * @param speed 
 */
void TrackObject::setSpeed(int speed) {
  _speed = (float)speed * 0.05f;
  _angularSpeed = _speed / _radius * 180.0f / glm::pi<float>();
}

/**
 * @brief Slot to stop the track
 * 
 */
void TrackObject::stopTrack() {
  if (_speed > 0.0f) {
    _oldSpeed = _speed;
    _oldAngularSpeed = _angularSpeed;
    _speed = 0.0f;
  } else {
    _speed = _oldSpeed;
    _angularSpeed = _oldAngularSpeed;
  }
}

TrackObject::~TrackObject() {}