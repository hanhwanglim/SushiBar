#ifndef LUCKY_CAT_H
#define LUCKY_CAT_H

#include "model.h"
#include "trackobject.h"

#include <QGLWidget>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <vector>

class LuckyCat : public TrackObject {
  Q_OBJECT

 public:
  LuckyCat();
  ~LuckyCat();

  void draw();

 private:
  Model* _catBody;  // Model of the cat's body
  Model* _catHand;  // Model of the cat's hand

  // Body

  std::vector<glm::vec3> _vertexBody;
  std::vector<glm::vec3> _normalBody;
  std::vector<glm::vec2> _textureBody;

  std::vector<unsigned int> _vertexIndicesBody;
  std::vector<unsigned int> _normalIndicesBody;
  std::vector<unsigned int> _textureIndicesBody;

  // Hand

  std::vector<glm::vec3> _vertexHand;
  std::vector<glm::vec3> _normalHand;
  std::vector<glm::vec2> _textureHand;

  std::vector<unsigned int> _vertexIndicesHand;
  std::vector<unsigned int> _normalIndicesHand;
  std::vector<unsigned int> _textureIndicesHand;

  float _handAngle = 0.0f;  // Angle to swing the hand

  void loadModel();
  void loadBody();
  void loadHand();

  void drawCat();
  void drawBody();
  void drawHand();

  void updateAngle();
};

#endif