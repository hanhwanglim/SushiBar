#include "camera.h"

Camera::Camera(glm::vec3 position) {
  this->_position = position;
  this->_front = glm::vec3(0.0f, 0.0f, -1.0f);
  this->_up = glm::vec3(0.0f, 1.0f, 0.0f);
  this->_worldUp = _up;

  this->_yaw = -90.0f;
  this->_pitch = 0.0f;

  updateCameraVectors();
}

void Camera::handleMouseEvent(float dx, float dy) {
  dx *= mouseSensitivity;
  dy *= mouseSensitivity;

  this->_yaw += dx;
  this->_pitch += dy;

  // Fix the camera when looking directly up so it does not over rotate
  if (this->_pitch >  89.0f) this->_pitch =  89.0f;
  if (this->_pitch < -89.0f) this->_pitch = -89.0f;

  updateCameraVectors();
}

void Camera::updateCameraVectors() {
  // Update the front vector
  glm::vec3 front;
  front.x = cos(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
  front.y = sin(glm::radians(this->_pitch));
  front.z = sin(glm::radians(this->_yaw)) * cos(glm::radians(this->_yaw));
  this->_front = glm::normalize(front);

  // Update the right and up vector
  this->_right = glm::normalize(glm::cross(this->_front, this->_worldUp));
  this->_up    = glm::normalize(glm::cross(this->_right, this->_front));
}