#include "camera.h"

Camera::Camera() {
  // Camera properties
  _position = glm::vec3(0.0f,  0.0f,  0.0f);
  _front    = glm::vec3(0.0f,  0.0f, -1.0f);
  _worldUp  = glm::vec3(0.0f,  1.0f,  0.0f);

  // Euler angles
  _yaw = -90.0f;
  _pitch = 0.0f;

  // Mouse properties
  _mouseSensitivity = 0.1f;

  updateCameraVectors();
}

Camera::Camera(glm::vec3 position) {
  // Camera properties
  _position = position;
  _front   = glm::vec3(0.0f, 0.0f, -1.0f);
  _worldUp = glm::vec3(0.0f, 1.0f,  0.0f);

  // Euler angles
  _yaw = -90.0f;
  _pitch = 0.0f;

  // Mouse properties
  _mouseSensitivity = 0.1f;

  updateCameraVectors();
}

/**
 * @brief Updates the camera based on the previous mouse position and current
 * mouse position
 *
 * @param dx x offset
 * @param dy y offset
 */
void Camera::handleMouseEvent(float dx, float dy) {
  // Adjust offset based on mouse sensitivity
  dx *= _mouseSensitivity;
  dy *= _mouseSensitivity;

  // Update yaw and pitch
  _yaw += dx;
  _pitch += dy;

  // Prevent the camera from over rotating
  if (_pitch > 89.0f) _pitch = 89.0f;
  if (_pitch < -89.0f) _pitch = -89.0f;

  updateCameraVectors();
}

/**
 * @brief Updates the front, right and up vector based on the current
 * values of yaw and pitch
 *
 */
void Camera::updateCameraVectors() {
  // Update front vector
  glm::vec3 front;
  front.x = (float)(cos(glm::radians(_yaw)) * cos(glm::radians(_pitch)));
  front.y = (float)(sin(glm::radians(_pitch)));
  front.z = (float)(sin(glm::radians(_yaw)) * cos(glm::radians(_pitch)));
  _front = glm::normalize(front);

  // Update right and up vector
  _right = glm::normalize(glm::cross(_front, _worldUp));
  _up = glm::normalize(glm::cross(_right, _front));
}
