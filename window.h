#ifndef WINDOW_H
#define WINDOW_H

#include <QBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

#include "sushibar.h"

class Window : public QWidget {
 public:
  Window(QWidget* parent);
  ~Window();

  SushiBar* sushiBar;

  QBoxLayout* windowLayout;

  QSlider* trackSpeed;
  QPushButton* pauseTrack;

 private:
  bool trackPaused = false;

  void trackSpeedSlider();
  void pauseTrackButton();
};

#endif
