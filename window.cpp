#include "window.h"

Window::Window(QWidget* parent) : QWidget(parent) {
  windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

  sushiBar = new SushiBar(this);
  windowLayout->addWidget(sushiBar);

  trackSpeedSlider();
  pauseTrackButton();
}

void Window::trackSpeedSlider() {
  trackSpeed = new QSlider(Qt::Horizontal);

  trackSpeed->setRange(1, 10);
  trackSpeed->setSingleStep(1);

  for (Sushi* _sushi : this->sushiBar->sushis)
    connect(trackSpeed, SIGNAL(valueChanged(int)),
            _sushi, SLOT(setSpeed(int)));

  connect(trackSpeed, SIGNAL(valueChanged(int)),
          this->sushiBar->cat, SLOT(setSpeed(int)));
  windowLayout->addWidget(trackSpeed);
}

void Window::pauseTrackButton() {
  pauseTrack = new QPushButton("Pause Track");

  for (Sushi* _sushi : this->sushiBar->sushis)
    connect(pauseTrack, SIGNAL(pressed()),
            _sushi, SLOT(stopTrack()));


  connect(pauseTrack, SIGNAL(pressed()), this->sushiBar->cat,
          SLOT(stopTrack()));

  windowLayout->addWidget(pauseTrack);
}

Window::~Window() {
  delete sushiBar;
  delete windowLayout;
  delete trackSpeed;
  delete pauseTrack;
}