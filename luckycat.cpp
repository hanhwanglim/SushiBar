#include "luckycat.h"

#include <gl/GLU.h>

LuckyCat::LuckyCat() {
  // Load model
  cat_body = new Model(
      "C:\\Users\\hanhw\\Desktop\\Computer "
      "Graphics\\SushiBar\\models\\cat_body.obj");
  cat_hand = new Model(
      "C:\\Users\\hanhw\\Desktop\\Computer "
      "Graphics\\SushiBar\\models\\cat_hand.obj");

  // Setup position in the scene
  position = glm::vec3(0, -1.5f, 0.7f);

  this->radius = 0.7f;
  this->angle = 0.0f;
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
 * @brief Updates the position ofo the cat
 * 
 */
void LuckyCat::updatePosition() {
  if (section1) {
    position += glm::vec3(speed, 0, 0);
  }
  if (section2) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = 4.7f + (radius * cos(angle * PI / 180.0f));
      position.z = 0.0f + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }
  if (section3) {
    position -= glm::vec3(speed, 0, 0);
  }
  if (section4) {
    if (speed > 0) {
      const float PI = 3.1415f;
      position.x = -9.0f + (radius * cos(angle * PI / 180.0f));
      position.z = 0.0f + (radius * sin(angle * PI / 180.0f));

      angle += angularSpeed;
    }
  }

  checkPosition();
}

/**
 * @brief Checks the position of the cat and update the sections
 * 
 */
void LuckyCat::checkPosition() {
  if (section1) {
    if (position.x >= 4.5) {
      section1 = false;
      section2 = true;
    }
  }
  if (section2) {
    if (this->angle >= 90 && this->angle <= 270) {
      section2 = false;
      section3 = true;
    }
  }
  if (section3) {
    if (position.x <= -9.0) {
      section3 = false;
      section4 = true;
    }
  }
  if (section4) {
    if (this->angle >= 270.0f) {
      section4 = false;
      section1 = true;
    }
  }

  if (angle >= 360) angle = 0;
}

/**
 * @brief Draws the cat on the scene
 * 
 */
void LuckyCat::drawCat() {
  // Draw body
  glRotatef(-angle + 90, 0, 1, 0);
  glPushMatrix();
  glScalef(0.1, 0.1, 0.1);
  drawBody();

  // Draw hand
  const float PI = 3.1415;
  float _handAngle = 90.0f * sin(handAngle * PI / 180.0f);

  glTranslatef(0, 7, 0);
  glRotatef(_handAngle, 1, 0, 0);
  glTranslatef(0, -7, 0);

  drawHand();

  glPopMatrix();

  // Update hand angle
  handAngle += 5.0f;

  if (handAngle >= 180) handAngle = 0;
}

void LuckyCat::drawBody() {
  // Load vertices data
  std::vector<glm::vec3> vertices = cat_body->vertices;
  std::vector<glm::vec3> normals = cat_body->normals;
  std::vector<unsigned int> vertexIndice = cat_body->vertexIndices;
  std::vector<unsigned int> normalIndice = cat_body->normalIndices;
  std::vector<unsigned int> textureIndice = cat_body->textureIndices;

  // Draw shape
  glBegin(GL_TRIANGLES);

  // Color and material properties
  glColor3f(0.69411765, 0.59607843, 0.34901961);
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  for (int i = 0; i < vertexIndice.size(); i++) {
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
  std::vector<glm::vec3> vertices = cat_hand->vertices;
  std::vector<glm::vec3> normals = cat_hand->normals;
  std::vector<unsigned int> vertexIndice = cat_hand->vertexIndices;
  std::vector<unsigned int> normalIndice = cat_hand->normalIndices;
  std::vector<unsigned int> textureIndice = cat_hand->textureIndices;

  // Draw shape
  glBegin(GL_TRIANGLES);

  // Color and material properties
  glColor3f(0.69411765, 0.0, 0.34901961);
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  for (int i = 0; i < vertexIndice.size(); i++) {
    int normalIndex = normalIndice[i] - 1;
    glm::vec3 normal = normals[normalIndex];
    glNormal3f(normal.x, normal.y, normal.z);

    int vertexIndex = vertexIndice[i] - 1;
    glm::vec3 vertex = vertices[vertexIndex];
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }

  glEnd();
}

/**
 * @brief Slot to change the speed of the cat on the track
 * 
 * @param speed 
 */
void LuckyCat::setSpeed(int speed) {
  this->speed = (float)speed * 0.1f;
  this->angularSpeed = (float)speed * 8.0f;
}

/**
 * @brief Slot to pause the track
 * 
 */
void LuckyCat::stopTrack() {
  if (speed > 0) {
    oldSpeed = speed;
    oldAngularSpeed = angularSpeed;
    speed = 0.0f;
  }
  else {
    speed = oldSpeed;
    angularSpeed = oldAngularSpeed;
  }
}

LuckyCat::~LuckyCat() {
  delete cat_hand;
  delete cat_body;
}