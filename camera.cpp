#include "camera.h"

Camera::Camera(glm::vec3 position) {
  _position = position;
  _front = glm::vec3(0.0f, 0.0f, -1.0f);
  _worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

  _yaw = -90.0f;
  _pitch = 0.0f;

  _mouseSensitivity = 0.1f;
  
  updateCameraVectors();
}

void Camera::handleMouseEvent(float dx, float dy) {
  dx *= _mouseSensitivity;
  dy *= _mouseSensitivity;

  _yaw += dx;
  _pitch += dy;

  if (_pitch > 89.0f) _pitch = 89.0f;
  if (_pitch < -89.0f) _pitch = -89.0f;

  updateCameraVectors();
}

void Camera::updateCameraVectors() {
  glm::vec3 front;
  front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
  front.y = sin(glm::radians(_pitch));
  front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
  _front = glm::normalize(front);
  
  _right = glm::normalize(glm::cross(_front, _worldUp));
  _up = glm::normalize(glm::cross(_right, _front));
}