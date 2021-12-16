#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
 public:
  Camera(glm::vec3 position);

  glm::vec3 position() { return this->_position; }
  glm::vec3 front()    { return this->_front; }
  glm::vec3 up()       { return this->_up; }
  glm::vec3 target()   { return this->_position + this->_front; }

  void handleMouseEvent(float dx, float dy);

 private:
  glm::vec3 _position;
  glm::vec3 _front;
  glm::vec3 _up;
  glm::vec3 _right;
  glm::vec3 _worldUp;

  float _yaw;
  float _pitch;

  float mouseSensitivity = 0.1f;

  void updateCameraVectors();
};

#endif