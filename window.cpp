#include "window.h"

/**
 * @brief Construct a new Window:: Window object
 * 
 * @param parent parent widget
 */
Window::Window(QWidget* parent) : QWidget(parent) {
  windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

  sushiBar = new SushiBar(this);
  windowLayout->addWidget(sushiBar);

  trackSpeedSlider();
  pauseTrackButton();
  setupTimer();
}

/**
 * @brief Setting up speed slider
 * 
 */
void Window::trackSpeedSlider() {
  trackSpeed = new QSlider(Qt::Horizontal);

  trackSpeed->setRange(1, 10);
  trackSpeed->setSingleStep(1);

  for (Sushi* sushi : sushiBar->_sushis)
    connect(trackSpeed, SIGNAL(valueChanged(int)), sushi, SLOT(setSpeed(int)));

  connect(trackSpeed, SIGNAL(valueChanged(int)), sushiBar->_cat,
          SLOT(setSpeed(int)));

  windowLayout->addWidget(trackSpeed);
}

/**
 * @brief Setting up pause button
 * 
 */
void Window::pauseTrackButton() {
  pauseTrack = new QPushButton("Pause Track");

  for (Sushi* sushi : sushiBar->_sushis)
    connect(pauseTrack, SIGNAL(pressed()), sushi, SLOT(stopTrack()));

  connect(pauseTrack, SIGNAL(pressed()), sushiBar->_cat, SLOT(stopTrack()));

  windowLayout->addWidget(pauseTrack);
}

/**
 * @brief Setting up timer
 * 
 */
void Window::setupTimer() {
  timer = new QTimer(this);
  timer->start(50);

  connect(timer, SIGNAL(timeout()), sushiBar, SLOT(update()));
}

Window::~Window() {
  delete timer;
  delete windowLayout;
  delete trackSpeed;
  delete pauseTrack;
  delete sushiBar;
}
