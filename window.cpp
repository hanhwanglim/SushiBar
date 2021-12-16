#include "window.h"

Window::Window(QWidget* parent) : QWidget(parent) {
  windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

  sushiBar = new SushiBar(this);
  windowLayout->addWidget(sushiBar);

  slider = new QSlider(Qt::Horizontal);
  windowLayout->addWidget(slider);
}

Window::~Window() {
  delete sushiBar;
}