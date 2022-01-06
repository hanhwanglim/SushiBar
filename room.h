#ifndef ROOM_H
#define ROOM_H

#include "globe.h"
#include "picture.h"

#include <string>

class Room {
 public:
  Room();
  ~Room();

  void table();
  void seat();
  void divider();
  void room();
  void track();

  void drawTable();
  void drawSeats();
  void drawTrack();
  void drawRoom();
  void drawPicture();

  void drawAll();

 private:
  Globe* _globe;
  Picture* _marc;
  Picture* _markus;
};

#endif