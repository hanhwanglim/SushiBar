#ifndef ROOM_H
#define ROOM_H

#include "shape.h"

#include <QOpenGLFunctions>

class Room : protected QOpenGLFunctions {
 public:
  Room();

  void table();

  void seat();

  void dividor();

  void room();

  void track();

  void paintings();

  void drawTable();

  void drawSeats();

  void drawDividor();

  void drawRoom();

  void drawAll();
};

#endif  // ROOM_H
