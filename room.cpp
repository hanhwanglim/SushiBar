#include "material.h"
#include "room.h"
#include "shape.h"

#include <GL/glu.h>


Room::Room() {
  _globe = new Globe();
  _marc = new Picture("textures/Marc_Dekamps.ppm");
  _markus = new Picture("textures/markus.ppm");
}

/**
 * @brief Draws a table
 * 
 */
void Room::table() {
  // Top
  const float WIDTH = 15.0f;
  const float HEIGHT = 0.4f;
  const float DEPTH = 8.0f;
  const float COORD[3] = {-1.5f, -2.0f, 0.0f};

  // Base
  const float BASE_WIDTH = WIDTH;
  const float BASE_HEIGHT = 5.0f;
  const float BASE_DEPTH = 4.0f;
  const float BASE_COORD[3] = {-1.5f, -4.5f, 0.0f};

  Shape s;

  glMaterialfv(GL_FRONT, GL_AMBIENT, WOOD.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, WOOD.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WOOD.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, WOOD.shininess);

  s.drawCuboid(WIDTH, HEIGHT, DEPTH,  // Top
               COORD[0], COORD[1], COORD[2]);
  s.drawCuboid(BASE_WIDTH, BASE_HEIGHT, BASE_DEPTH,  // Base
               BASE_COORD[0], BASE_COORD[1], BASE_COORD[2]);
}

/**
 * @brief Draws a seat
 * 
 */
void Room::seat() {
  // Dimensions
  const float SEAT_RADIUS = 1.0f;
  const float SEAT_HEIGHT = 0.6f;

  const float ROD_RADIUS = 0.2f;
  const float ROD_HEIGHT = 3.0f;

  const float BASE_RADIUS = 0.8f;
  const float BASE_HEIGHT = 0.09f;

  Shape s;

  glPushMatrix();

  glTranslatef(0.0f, ROD_HEIGHT, 0.0f);

  // Seat
  glMaterialfv(GL_FRONT, GL_AMBIENT, RED_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, RED_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, RED_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, RED_PLASTIC.shininess);

  s.drawClosedCylinder(SEAT_RADIUS, SEAT_HEIGHT);

  // Rod
  glMaterialfv(GL_FRONT, GL_AMBIENT, SILVER.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, SILVER.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, SILVER.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, SILVER.shininess);

  glTranslatef(0.0f, -ROD_HEIGHT / 2.0f, 0.0f);
  s.drawClosedCylinder(ROD_RADIUS, ROD_HEIGHT);

  // Base
  glTranslatef(0.0f, -ROD_HEIGHT / 2.0f, 0.0f);
  s.drawClosedCylinder(BASE_RADIUS, BASE_HEIGHT);

  glPopMatrix();
}

/**
 * @brief Draws a divider
 * 
 */
void Room::divider() {
  // Dimensions
  const float WIDTH = 12.0f;
  const float HEIGHT = 2.0f;
  const float DEPTH = 0.1f;
  const float COORD[3] = {-1.5f, -0.7f, 0.0f};

  glMaterialfv(GL_FRONT, GL_AMBIENT, CYAN_PLASTIC.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, CYAN_PLASTIC.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, CYAN_PLASTIC.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, CYAN_PLASTIC.shininess);

  Shape s;
  s.drawCuboid(WIDTH, HEIGHT, DEPTH, COORD[0], COORD[1], COORD[2]);
}

/**
 * @brief Draws the room
 * 
 */
void Room::room() {
  float WIDTH = 18.1f;
  float HEIGHT = 14.1f;
  float DEPTH = 14.0f;
  float COORD[3] = {0.0f, 0.0f, 0.0f};

  float w = COORD[0] + (WIDTH / 2.0f);
  float h = COORD[1] + (HEIGHT / 2.0f);
  float d = COORD[2] + (DEPTH / 2.0f);

  glMaterialfv(GL_FRONT, GL_AMBIENT, BRASS.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, BRASS.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, BRASS.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, BRASS.shininess);

  glBegin(GL_QUADS);

  // Back
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(COORD[0] - w, COORD[1] - h, COORD[2] - d);
  glVertex3f(COORD[0] + w, COORD[1] - h, COORD[2] - d);
  glVertex3f(COORD[0] + w, COORD[1] + h, COORD[2] - d);
  glVertex3f(COORD[0] - w, COORD[1] + h, COORD[2] - d);

  // Left
  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(COORD[0] - w, COORD[1] - h, COORD[2] + d);
  glVertex3f(COORD[0] - w, COORD[1] - h, COORD[2] - d);
  glVertex3f(COORD[0] - w, COORD[1] + h, COORD[2] - d);
  glVertex3f(COORD[0] - w, COORD[1] + h, COORD[2] + d);

  // Bottom
  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(COORD[0] + w, COORD[1] - h, COORD[2] + d);
  glVertex3f(COORD[0] + w, COORD[1] - h, COORD[2] - d);
  glVertex3f(COORD[0] - w, COORD[1] - h, COORD[2] - d);
  glVertex3f(COORD[0] - w, COORD[1] - h, COORD[2] + d);

  glEnd();
}

/**
 * @brief Draws the track
 * 
 */
void Room::track() {
  Shape s;

  const float TRACK_WIDTH = 14.9f;
  const float TRACK_HEIGHT = 0.1f;
  const float TRACK_DEPTH = 3.0f;
  const float TRACK_COORD[3] = {-1.55f, -1.7f, 0.0f};

  // Track
  glMaterialfv(GL_FRONT, GL_AMBIENT, BLACK_RUBBER.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, BLACK_RUBBER.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, BLACK_RUBBER.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, BLACK_RUBBER.shininess);

  s.drawCuboid(TRACK_WIDTH, TRACK_HEIGHT, TRACK_DEPTH, TRACK_COORD[0],
               TRACK_COORD[1], TRACK_COORD[2]);

  // Track guard
  const float GUARD_WIDTH = 15.0f;
  const float GUARD_HEIGHT = 0.2f;
  const float GUARD_DEPTH = 0.2;

  const float GUARD_COORD_1[3] = {-1.5f, -1.7f, 1.5f};
  const float GUARD_COORD_2[3] = {-1.5f, -1.7f, -1.5f};
  const float GUARD_COORD_3[3] = {5.9f, -1.7f, 0.0f};

  glMaterialfv(GL_FRONT, GL_AMBIENT, SILVER.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, SILVER.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, SILVER.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, SILVER.shininess);

  s.drawCuboid(GUARD_WIDTH, GUARD_HEIGHT, GUARD_DEPTH, 
               GUARD_COORD_1[0], GUARD_COORD_1[1], GUARD_COORD_1[2]);
  s.drawCuboid(GUARD_WIDTH, GUARD_HEIGHT, GUARD_DEPTH, 
               GUARD_COORD_2[0], GUARD_COORD_2[1], GUARD_COORD_2[2]);
  s.drawCuboid(GUARD_DEPTH, GUARD_HEIGHT, TRACK_DEPTH, 
               GUARD_COORD_3[0], GUARD_COORD_3[1], GUARD_COORD_3[2]);

  divider();
}

/**
 * @brief Draws the table in the scene
 * 
 */
void Room::drawTable() { table(); }

/**
 * @brief Draws some seats in the scene
 * 
 */
void Room::drawSeats() {
  const float y = -7.0f;

  const float X_INTERVAL = 3.0f;
  const float Z_INTERVAL = 8.0f;

  const float X_RANGE[2] = {-7.5f, 6.0f};
  const float Z_RANGE[2] = {-4.0f, 4.0f};

  for (float x = X_RANGE[0]; x <= X_RANGE[1]; x += X_INTERVAL) {
    for (float z = Z_RANGE[0]; z <= Z_RANGE[1]; z += Z_INTERVAL) {
      glPushMatrix();
      glTranslatef(x, y, z);
      seat();
      glPopMatrix();
    }
  }
}

/**
 * @brief Draws the track in the scene
 * 
 */
void Room::drawTrack() { track(); }

/**
 * @brief Draws the room in the scene
 * 
 */
void Room::drawRoom() { room(); }

/**
 * @brief Draws the pictures in the room
 * 
 */
void Room::drawPicture() {
  glPushMatrix();
  glTranslatef(0.0f, 1.0f, -6.9);
  _marc->draw();
  glTranslatef(4.0f, 0.0f, 0.0f);
  _markus->draw();
  glPopMatrix();
}

/**
 * @brief Draws all object in the room
 * 
 */
void Room::drawAll() {
  drawTable();
  drawSeats();
  drawPicture();
  drawTrack();
  drawRoom();

  _globe->drawGlobe();
}

Room::~Room() { 
    delete _globe;
    delete _marc;
    delete _markus;
}