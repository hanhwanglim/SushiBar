#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera {
 public:
  Camera();
  explicit Camera(glm::vec3 position);

  /**
   * @brief Returns the position vector
   *
   * @return glm::vec3 position
   */
  glm::vec3 position() { return _position; }

  /**
   * @brief Returns the target vector
   *
   * @return glm::vec3 target
   */
  glm::vec3 target() { return _position + _front; }

  /**
   * @brief Returns the up vector
   *
   * @return glm::vec3 up
   */
  glm::vec3 up() { return _worldUp; }

  void handleMouseEvent(float dx, float dy);

 private:
  // Camera properties
  glm::vec3 _position;  // Position vector
  glm::vec3 _front;     // Front vector
  glm::vec3 _up;        // Up vector
  glm::vec3 _right;     // Right vector
  glm::vec3 _worldUp;   // World up vector

  // Euler angles
  float _yaw;   // Yaw
  float _pitch; // Pitch

  // Mouse properties
  float _mouseSensitivity;  // Mouse sensitivity

  void updateCameraVectors();
};

#endif
