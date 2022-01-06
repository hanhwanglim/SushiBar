#include <QApplication>
#include <QVBoxLayout>

#include "window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Window* window = new Window(NULL);
    window->resize(800, 800);
    window->show();
    return app.exec();
}
