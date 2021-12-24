TEMPLATE = app
TARGET = SushiBar
INCLUDEPATH += . /opt/local/include ./include

QT       += widgets core gui opengl
LIBS     += -lGLU

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    camera.cpp \
    globe.cpp \
    image.cpp \
    lighting.cpp \
    luckycat.cpp \
    main.cpp \
    model.cpp \
    picture.cpp \
    room.cpp \
    shape.cpp \
    sushi.cpp \
    sushibar.cpp \
    trackobject.cpp \
    window.cpp

HEADERS += \
    camera.h \
    globe.h \
    image.h \
    lighting.h \
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
