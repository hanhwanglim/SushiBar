#ifndef ROOM_H
#define ROOM_H

#include <QOpenGLFunctions>

#include "globe.h"
#include "image.h"
#include "material.h"
#include "picture.h"
#include "shape.h"

class Room : protected QOpenGLFunctions {
 public:
  Room();

  void table();
  void seat();
  void dividor();
  void room();
  void track();
  void pictures();

  void drawTable();
  void drawSeats();
  void drawDividor();
  void drawRoom();
  void drawGlobe();
  void drawPictures();

  void drawAll();

 private:
  Picture* marc;
  Picture* markus;

  Globe* globe;
};

#endif  // ROOM_H
