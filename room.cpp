#include "room.h"

Room::Room() {}

void Room::table() {
  const float tableTopWidth = 15.0f;
  const float tableTopHeight = 0.4f;
  const float tableTopDepth = 8.0f;
  const float tableTopCoord[3] = {-1.5f, -2.0f, 0.0f};

  const float tableBaseWidth = tableTopWidth;
  const float tableBaseHeight = 5.0f;
  const float legRoom = 4.0f;
  const float tableBaseDepth = tableTopDepth - legRoom;
  const float tableBaseCoord[3] = {-1.5f, -4.5f, 0.0f};

  Shape s;

  glColor3f(0.7254902f , 0.47843137f, 0.34117647f); // Brown

  // Top
  s.drawCuboid(tableTopWidth, tableTopHeight, tableTopDepth,
               tableTopCoord[0], tableTopCoord[1], tableTopCoord[2]);

  // Base
  s.drawCuboid(tableBaseWidth, tableBaseHeight, tableBaseDepth,
               tableBaseCoord[0], tableBaseCoord[1], tableBaseCoord[2]);
}

void Room::seat() {
  Shape s;
    glPushMatrix();
    glTranslatef(0, 4, 0);
    // Seat
    glColor3f(0.87843137, 0.06666667, 0.37254902);
    s.drawClosedCylinder(1, 0.6);

    // Rod
    glColor3f(0.75294118, 0.75294118, 0.75294118);
    glTranslatef(0, -4, 0);
    s.drawClosedCylinder(0.2, 4);

    // Base
    s.drawClosedCylinder(0.8, 0.4);
    glPopMatrix();
}

// void Room::dividor() {}

void Room::room() {

  const float roomDimensions[4][2] = {
    //  Left (x)  ||   Right (x)
    {-9.0f, -7.0f}, {9.0f, -7.0f},  // Up   (z)
    {-9.0f,  7.0f}, {9.0f,  7.0f}   // Down (z)
  };

  const float roomFloor = -7.0f;
  const float roomCeil = 7.0f;  // y

  glColor3f(0.96078431f, 0.96078431f, 0.8627451f); // Beige 

  glBegin(GL_QUADS);
  // Front
  // glNormal3f(0.0f, 0.0f, 1.0f);
  // glVertex3f(roomDimensions[3][0],      roomFloor, roomDimensions[3][1]);
  // glVertex3f(roomDimensions[2][0],      roomFloor, roomDimensions[2][1]);
  // glVertex3f(roomDimensions[2][0], roomCeil, roomDimensions[2][1]);
  // glVertex3f(roomDimensions[3][0], roomCeil, roomDimensions[3][1]);

  // Back
  glNormal3f(0.0f, 0.0f, -1.0f);
  glVertex3f(roomDimensions[1][0],      roomFloor, roomDimensions[1][1]);
  glVertex3f(roomDimensions[0][0],     roomFloor, roomDimensions[0][1]);
  glVertex3f(roomDimensions[0][0], roomCeil, roomDimensions[0][1]);
  glVertex3f(roomDimensions[1][0], roomCeil, roomDimensions[1][1]);

  // Right
  // glNormal3f(1.0f, 0.0f, 0.0f);
  // glVertex3f(roomDimensions[1][0],    roomFloor, roomDimensions[1][1]);
  // glVertex3f(roomDimensions[3][0],   roomFloor, roomDimensions[3][1]);
  // glVertex3f(roomDimensions[3][0], roomCeil, roomDimensions[3][1]);
  // glVertex3f(roomDimensions[1][0], roomCeil, roomDimensions[1][1]);

  // Left
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(roomDimensions[2][0],     roomFloor, roomDimensions[2][1]);
  glVertex3f(roomDimensions[0][0],      roomFloor, roomDimensions[0][1]);
  glVertex3f(roomDimensions[0][0], roomCeil, roomDimensions[0][1]);
  glVertex3f(roomDimensions[2][0], roomCeil, roomDimensions[2][1]);

  // Bottom
  glNormal3f(0.0f, -1.0f, 0.0f);
  glVertex3f(roomDimensions[3][0],   roomFloor, roomDimensions[3][1]);
  glVertex3f(roomDimensions[2][0],   roomFloor, roomDimensions[2][1]);
  glVertex3f(roomDimensions[0][0],   roomFloor, roomDimensions[0][1]);
  glVertex3f(roomDimensions[1][0],    roomFloor, roomDimensions[1][1]);

  glEnd();
}

// void Room::paintings() {}

// void Room::drawTable() {}

void Room::drawSeats() {
  const float y = -7.0f;

  for (float x = -7.5f; x <= 6.0f; x += 3.0f) {
    for (float z = -4.0f; z <= 4.0f; z += 8.0f) {
      glPushMatrix();
      glTranslatef(x, y, z);
      seat();
      glPopMatrix();
    }
  }
}

// void Room::drawDividor() {}

// void Room::drawRoom() {}

void Room::track() {
  glBegin(GL_QUADS);
  // Front
  glColor3f(0.81960784f, 0.87058824f, 0.87058824f);  // Frosted glass

  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-4, 2.2, 0);
  glVertex3f(3, 2.2, 0);
  glVertex3f(3, 2, 0);
  glVertex3f(-4, 2, 0);

  glEnd();
}

void Room::drawAll() {
  room();
  table();
  // track();
  // seat();
  drawSeats();
}