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

  glColor3f(0.7254902f, 0.47843137f, 0.34117647f);  // Brown

  Material material = {{0.329412, 0.223529, 0.027451, 1},
                       {0.7254902f, 0.47843137f, 0.34117647f, 1},
                       {0.992157, 0.941176, 0.807843, 1},
                       27.897436};

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  // Top
  s.drawCuboid(tableTopWidth, tableTopHeight, tableTopDepth, tableTopCoord[0],
               tableTopCoord[1], tableTopCoord[2]);

  // Base
  s.drawCuboid(tableBaseWidth, tableBaseHeight, tableBaseDepth,
               tableBaseCoord[0], tableBaseCoord[1], tableBaseCoord[2]);
}

void Room::seat() {
  Shape s;
  Material material;

  glPushMatrix();
  glTranslatef(0, 3, 0);
  // Seat
  glColor3f(0.87843137, 0.06666667, 0.37254902);

  material = {{0.0, 0.0, 0.0, 1},
              {0.87843137, 0.06666667, 0.37254902, 1},
              {0.7, 0.6, 0.6, 1},
              32};  // Red plastic
  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  s.drawClosedCylinder(1, 0.6);

  // Rod
  glColor3f(0.75294118, 0.75294118, 0.75294118);

  material = {{0.19225, 0.19225, 0.19225, 1},
              {0.75294118, 0.75294118, 0.75294118, 1},
              {0.508273, 0.508273, 0.508273, 1},
              51.2};  // Silver

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);


  glTranslatef(0, -3, 0);
  s.drawClosedCylinder(0.2, 3);

  // Base
  s.drawClosedCylinder(0.8, 0.4);
  glPopMatrix();
}

void Room::dividor() {
  const float dividorCoord[4][3] = {
      {-9, 0.5, 0}, {4.5, 0.5, 0}, {-9, -1.5, 0}, {4.5, -1.5, 0}};
  glColor3f(0.65882353f, 0.8f, 0.84313725f);  // Frosted glass

  Material material = {{0.19225, 0.19225, 0.19225, 1},
              {0.65882353f, 0.8f, 0.84313725f, 1},
              {0.75294118, 0.75294118, 0.75294118, 1},
              51.2};  // Frosted glass

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  glNormal3f(0.0f, 0.0f, -1.0f);
  glBegin(GL_QUADS);

  glVertex3f(dividorCoord[3][0], dividorCoord[3][1], dividorCoord[3][2]);
  glVertex3f(dividorCoord[2][0], dividorCoord[2][1], dividorCoord[2][2]);
  glVertex3f(dividorCoord[0][0], dividorCoord[0][1], dividorCoord[0][2]);
  glVertex3f(dividorCoord[1][0], dividorCoord[1][1], dividorCoord[1][2]);
  glEnd();
}

void Room::room() {
  const float roomDimensions[4][2] = {
      //  Left (x)  ||   Right (x)
      {-9.0f, -7.0f},
      {9.0f, -7.0f},  // Up   (z)
      {-9.0f, 7.0f},
      {9.0f, 7.0f}  // Down (z)
  };

  const float roomFloor = -7.0f;
  const float roomCeil = 7.0f;  // y

  glColor3f(0.96078431f, 0.96078431f, 0.8627451f);  // Beige

  Material material = {{0.329412, 0.223529, 0.027451, 1},  // Brass
                       {0.96078431f, 0.96078431f, 0.8627451f, 1},
                       {0.992157, 0.941176, 0.807843, 1},
                       27.897436};

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  glBegin(GL_QUADS);
  // Front
  // glNormal3f(0.0f, 0.0f, 1.0f);
  // glVertex3f(roomDimensions[3][0],      roomFloor, roomDimensions[3][1]);
  // glVertex3f(roomDimensions[2][0],      roomFloor, roomDimensions[2][1]);
  // glVertex3f(roomDimensions[2][0], roomCeil, roomDimensions[2][1]);
  // glVertex3f(roomDimensions[3][0], roomCeil, roomDimensions[3][1]);

  // Back
  glNormal3f(0.0f, 0.0f, -1.0f);
  glVertex3f(roomDimensions[1][0], roomFloor, roomDimensions[1][1]);
  glVertex3f(roomDimensions[0][0], roomFloor, roomDimensions[0][1]);
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
  glVertex3f(roomDimensions[2][0], roomFloor, roomDimensions[2][1]);
  glVertex3f(roomDimensions[0][0], roomFloor, roomDimensions[0][1]);
  glVertex3f(roomDimensions[0][0], roomCeil, roomDimensions[0][1]);
  glVertex3f(roomDimensions[2][0], roomCeil, roomDimensions[2][1]);

  // Bottom
  glNormal3f(0.0f, -1.0f, 0.0f);
  glVertex3f(roomDimensions[3][0], roomFloor, roomDimensions[3][1]);
  glVertex3f(roomDimensions[2][0], roomFloor, roomDimensions[2][1]);
  glVertex3f(roomDimensions[0][0], roomFloor, roomDimensions[0][1]);
  glVertex3f(roomDimensions[1][0], roomFloor, roomDimensions[1][1]);

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
  Shape s;
  Material material;

  const float trackWidth = 14.9f;
  const float trackHeight = 0.1f;
  const float trackDepth = 3.0f;

  const float trackCoord[3] = {-1.55f, -1.7f, 0.0f};

  // Track
  glColor3f(0.04705882f, 0.03921569f, 0.0f);  // Carbon black
  material = {{0.02, 0.02, 0.02, 1},          // Black rubber
              {0.01, 0.01, 0.01, 1},
              {0.40, 0.40, 0.40, 1},
              10};

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
  s.drawCuboid(trackWidth, trackHeight, trackDepth, trackCoord[0],
               trackCoord[1], trackCoord[2]);

  // Track guard
  const float guardWidth = 15.0f;
  const float guardHeight = 0.2f;
  const float guardDepth = 0.2f;
  glColor3f(0.67843137f, 0.69803922f, 0.74117647f);  // Aluminium
  material = {{0.19225, 0.19225, 0.19225, 1},
              {0.50754, 0.50754, 0.50754, 1},
              {0.508273, 0.508273, 0.508273, 1},
              51.2};  // Silver

  glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);

  const float guardCoord1[3] = {-1.5f, -1.7f, 1.5f};
  const float guardCoord2[3] = {-1.5f, -1.7f, -1.5f};
  const float guardCoord3[3] = {5.9f, -1.7f, 0.0f};

  s.drawCuboid(guardWidth, guardHeight, guardDepth, guardCoord1[0],
               guardCoord1[1], guardCoord1[2]);
  s.drawCuboid(guardWidth, guardHeight, guardDepth, guardCoord2[0],
               guardCoord2[1], guardCoord2[2]);
  s.drawCuboid(guardDepth, guardHeight, trackDepth, guardCoord3[0],
               guardCoord3[1], guardCoord3[2]);

  dividor();
}

void Room::drawAll() {
  room();
  table();
  track();
  drawSeats();
}