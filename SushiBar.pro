TEMPLATE = app
TARGET = SushiBar
INCLUDEPATH += . /opt/local/include

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -std=c++11

QT += widgets opengl gui 

HEADERS += window.h sushibar.h image.h room.h shape.h material.h globe.h picture.h trackobject.h model.h luckycat.h sushi.h camera.h
SOURCES += main.cpp sushibar.cpp window.cpp image.cpp room.cpp shape.cpp globe.cpp picture.cpp trackobject.cpp model.cpp luckycat.cpp sushi.cpp camera.cpp

LIBS += -lglut -lGLU
