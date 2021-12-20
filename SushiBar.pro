QT       += core gui opengl
LIBS     += -lglu32 -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    main.cpp \
    model.cpp \
    room.cpp \
    shape.cpp \
    sushi_bar.cpp \
    window.cpp

HEADERS += \
    camera.h \
    model.h \
    room.h \
    shape.h \
    sushi_bar.h \
    window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ./include /opt/local/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lassimp-vc142-mt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lassimp-vc142-mtd
else:unix: LIBS += -L$$PWD/lib/ -lassimp-vc142-mt

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

DISTFILES += \
    model.frag \
    model.vert
