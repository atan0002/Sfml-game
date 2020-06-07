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
        bullet.cpp \
        enemies.cpp \
        main.cpp \
        platform.cpp \
        player.cpp

DISTFILES += \
    ../../Desktop/ludzik.jpg

HEADERS += \
    background.h \
    bullet.h \
    enemies.h \
    platform.h \
    player.h
