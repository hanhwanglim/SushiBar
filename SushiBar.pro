TEMPLATE = app
TARGET = SushiBar
INCLUDEPATH += . /opt/local/include ./include

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -std=c++11

QT += widgets opengl gui 

HEADERS += \
    camera.h \
    globe.h \
    image.h \
    luckycat.h \
    material.h \
    model.h \
    picture.h \
    room.h \
    shape.h \
    sushi.h \
    sushibar.h \
    trackobject.h \
    window.h 

SOURCES += \
    camera.cpp
    globe.cpp \
    image.cpp \
    luckycat.cpp \
    main.cpp \
    model.cpp \
    picture.cpp \
    room.cpp \
    shape.cpp \
    sushi.cpp \
    sushibar.cpp \
    trackobject.cpp \
    window.cpp \

LIBS += -lGLU
