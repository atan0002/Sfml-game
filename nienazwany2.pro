TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        background.cpp \
        bird.cpp \
        bullet.cpp \
        enemies.cpp \
        life.cpp \
        main.cpp \
        monkey.cpp \
        platform.cpp \
        player.cpp \
        startend.cpp

DISTFILES += \
    ../../Desktop/ludzik.jpg

HEADERS += \
    background.h \
    bird.h \
    bullet.h \
    enemies.h \
    life.h \
    monkey.h \
    platform.h \
    player.h \
    startend.h
