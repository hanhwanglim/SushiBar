#include <QApplication>

#include "window.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  Window* window = new Window(NULL);
  window->resize(800, 800);
  window->show();
  return a.exec();
}
