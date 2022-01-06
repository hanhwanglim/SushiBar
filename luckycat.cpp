#include "luckycat.h"
#include "material.h"

#include <GL/glu.h>

/**
 * @brief Construct a new Lucky Cat:: Lucky Cat object
 * 
 */
LuckyCat::LuckyCat() {
  _catBody = new Model("models/cat_body.obj");
  _catHand = new Model("models/cat_hand.obj");

  // Initialise at section 3 of the track

  _position = glm::vec3(0.0f, -1.7f, 0.7f);

  _angle = 90.0f;
  _section1 = false;
  _section2 = false;
  _section3 = true;
  _section4 = false;

  loadModel();
}

/**
 * @brief Draw the cat on the scene
 * 
 */
void LuckyCat::draw() {
  glPushMatrix();
  glTranslatef(_position.x, _position.y, _position.z);
  drawCat();
  glPopMatrix();

  updatePosition();
}

/**
 * @brief Draws a cat
 * 
 */
void LuckyCat::drawCat() {
  const float SCALE = 0.1f;
  glDisable(GL_LIGHTING);
  glColor3f(0.89f, 0.64f, 0.23f);
  glMaterialfv(GL_FRONT, GL_AMBIENT, GOLD.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, GOLD.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, GOLD.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, GOLD.shininess);

  // Draw body
  glRotatef(-_angle + 90.0f, 0.0f, 1.0f, 0.0f);
  glPushMatrix();
  glScalef(SCALE, SCALE, SCALE);
  drawBody();

  // Draw hand
  float angle =
      45.0f * glm::sin(_handAngle * glm::pi<float>() / 180.0f) + 45.0f;
  glColor3f(0.98f, 0.81f, 0.30f);
  glTranslatef(0.0f, 7.0f, 0.0f);      // Offset to hand position
  glRotatef(angle, 1.0f, 0.0f, 0.0f);  // Perform hand rotation
  glTranslatef(0.0f, -7.0f, 0.0f);     // Return back to original position

  drawHand();

  glPopMatrix();
  glEnable(GL_LIGHTING);

  updateAngle();
}

/**
 * @brief Draws the cat's body
 * 
 */
void LuckyCat::drawBody() {
  glBegin(GL_TRIANGLES);

  for (unsigned int i = 0; i < _vertexIndicesBody.size(); i++) {
    unsigned int normalIndex = _normalIndicesBody[i] - 1;
    unsigned int vertexIndex = _vertexIndicesBody[i] - 1;

    glm::vec3 normal = _normalBody[normalIndex];
    glm::vec3 vertex = _vertexBody[vertexIndex];

    glNormal3f(normal.x, normal.y, normal.z);
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }

  glEnd();
}

/**
 * @brief Draws the cat's hand
 * 
 */
void LuckyCat::drawHand() {
  glBegin(GL_TRIANGLES);

  for (unsigned int i = 0; i < _vertexIndicesHand.size(); i++) {
    unsigned int normalIndex = _normalIndicesHand[i] - 1;
    unsigned int vertexIndex = _vertexIndicesHand[i] - 1;

    glm::vec3 normal = _normalHand[normalIndex];
    glm::vec3 vertex = _vertexHand[vertexIndex];

    glNormal3f(normal.x, normal.y, normal.z);
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }

  glEnd();
}

/**
 * @brief Loads the cat's model data
 * 
 */
void LuckyCat::loadModel() {
  loadBody();
  loadHand();
}

/**
 * @brief Loads the cat's model's body data
 * 
 */
void LuckyCat::loadBody() {
  _vertexBody = _catBody->vertices();
  _normalBody = _catBody->normals();
  _textureBody = _catBody->texCoord();

  _vertexIndicesBody = _catBody->vertexIndices();
  _normalIndicesBody = _catBody->normalIndices();
  _textureIndicesBody = _catBody->textureIndices();
}

/**
 * @brief Loads the cat's model's hand data
 * 
 */
void LuckyCat::loadHand() {
  _vertexHand = _catHand->vertices();
  _normalHand = _catHand->normals();
  _textureHand = _catHand->texCoord();

  _vertexIndicesHand = _catHand->vertexIndices();
  _normalIndicesHand = _catHand->normalIndices();
  _textureIndicesHand = _catHand->textureIndices();
}

/**
 * @brief Updates the hand angle at each tick
 * 
 */
void LuckyCat::updateAngle() {
  _handAngle += 5.0f;

  if (_handAngle >= 360.0f) _handAngle = 0;
}

LuckyCat::~LuckyCat() {
  delete _catBody;
  delete _catHand;
}