#include "luckycat.h"

#include <GL/glu.h>

#include <iostream>

LuckyCat::LuckyCat() {
  // Load model
  _cat_body = new Model("./models/cat_body.obj");
  _cat_hand = new Model("./models/cat_hand.obj");

  // Setup position in the scene
  position = glm::vec3(0.0f, -1.7f, 0.7f);

  this->radius = 0.7f;
  this->angle = 90.0f;
  section3 = true;

  // Material properties
  material = {{0.0f, 0.0f, 0.0f, 1.0f},
              {0.0, 0.0, 0.0, 1.0f},
              {0.6f, 0.6f, 0.5f, 1.0f},
              32.0f};
}

/**
 * @brief Draw the cat on the scene
 * 
 */
void LuckyCat::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  drawCat();
  glPopMatrix();

  updatePosition();
}

/**
 * @brief Draws the cat on the scene
 * 
 */
void LuckyCat::drawCat() {
  initializeOpenGLFunctions();
  glDisable(GL_LIGHTING);

  // Color and material properties
  glColor3f(0.89019608f, 0.63921569f, 0.23137255f);
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  // Draw body
  glRotatef(-angle + 90.0f, 0, 1, 0);
  glPushMatrix();
  glScalef(0.1, 0.1, 0.1);
  drawBody();

  // Draw hand
  glColor3f(0.98039216f, 0.81176471f, 0.30588235f);
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  // Calculate hand rotation angle
  const float PI = 3.141593;
  float handAngle = 90.0f * sin(_handAngle * PI / 180.0f);

  glTranslatef(0, 7, 0);
  glRotatef(handAngle, 1, 0, 0);
  glTranslatef(0, -7, 0);

  drawHand();

  glPopMatrix();

  // Update hand angle
  _handAngle += 5.0f;

  if (_handAngle >= 180) _handAngle = 0;

  glEnable(GL_LIGHTING);
}

void LuckyCat::drawBody() {
  // Load vertices data
  std::vector<glm::vec3> vertices = _cat_body->vertices;
  std::vector<glm::vec3> normals = _cat_body->normals;
  std::vector<unsigned int> vertexIndice = _cat_body->vertexIndices;
  std::vector<unsigned int> normalIndice = _cat_body->normalIndices;
  std::vector<unsigned int> textureIndice = _cat_body->textureIndices;

  // Draw shape
  glBegin(GL_TRIANGLES);

  for (unsigned int i = 0; i < vertexIndice.size(); i++) {
    int normalIndex = normalIndice[i] - 1;
    glm::vec3 normal = normals[normalIndex];
    glNormal3f(normal.x, normal.y, normal.z);

    int vertexIndex = vertexIndice[i] - 1;
    glm::vec3 vertex = vertices[vertexIndex];
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }

  glEnd();
}

void LuckyCat::drawHand() {
  // Load vertices data
  std::vector<glm::vec3> vertices = _cat_hand->vertices;
  std::vector<glm::vec3> normals = _cat_hand->normals;
  std::vector<unsigned int> vertexIndice = _cat_hand->vertexIndices;
  std::vector<unsigned int> normalIndice = _cat_hand->normalIndices;
  std::vector<unsigned int> textureIndice = _cat_hand->textureIndices;

  // Draw shape
  glBegin(GL_TRIANGLES);

  for (unsigned int i = 0; i < vertexIndice.size(); i++) {
    int normalIndex = normalIndice[i] - 1;
    glm::vec3 normal = normals[normalIndex];
    glNormal3f(normal.x, normal.y, normal.z);

    int vertexIndex = vertexIndice[i] - 1;
    glm::vec3 vertex = vertices[vertexIndex];
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }

  glEnd();
}

LuckyCat::~LuckyCat() {
  delete _cat_hand;
  delete _cat_body;
}