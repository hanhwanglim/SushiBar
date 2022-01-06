#ifndef WINDOW_H
#define WINDOW_H

#include "sushibar.h"

#include <QBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QWidget>

class Window : public QWidget {
 public:
  Window(QWidget* parent);
  ~Window();

  QBoxLayout* windowLayout;
  SushiBar* sushiBar;
  QSlider* trackSpeed;
  QPushButton* pauseTrack;
  QTimer* timer;

 private:
  void trackSpeedSlider();
  void pauseTrackButton();
  void setupTimer();
};

#endif
