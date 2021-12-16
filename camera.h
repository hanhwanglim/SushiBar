#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera {
 public:
  Camera(glm::vec3 position);

  glm::vec3 position() { return _position; }
  glm::vec3 target() { return _position + _front; }
  glm::vec3 up() {return _worldUp; }

  void handleMouseEvent(float dx, float dy);

 private:
  glm::vec3 _position;
  glm::vec3 _front;
  glm::vec3 _up;
  glm::vec3 _right;
  glm::vec3 _worldUp;

  float _yaw;
  float _pitch;

  float _mouseSensitivity;

  void updateCameraVectors();
};

#endif
