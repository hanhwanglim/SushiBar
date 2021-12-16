#ifndef WINDOW_H
#define WINDOW_H

#include "sushi_bar.h"

#include <QBoxLayout>
#include <QSlider>
#include <QWidget>

class Window : public QWidget {
 public:
  Window(QWidget* parent);
  ~Window();

  SushiBar* sushiBar;

  QBoxLayout* windowLayout;
  QSlider* slider;
};

#endif
