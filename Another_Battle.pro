#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T19:52:28
#
#-------------------------------------------------

QT       += core gui
QT       += phonon

TARGET = Another_Battle
TEMPLATE = app


SOURCES += main.cpp \
    warrior.cpp \
    war_abstr_factory.cpp \
    tutorial.cpp \
    startwindow.cpp \
    sound_file.cpp \
    hit.cpp \
    gamesettings.cpp \
    fieldview.cpp \
    fieldelement.cpp \
    field.cpp \
    battle_scene.cpp \
    unitinfo.cpp \
    turns_left_wnd.cpp

HEADERS  += \
    warrior.h \
    war_abstr_factory.h \
    voices.h \
    tutorial.h \
    startwindow.h \
    sound_file.h \
    hit.h \
    gamesettings.h \
    fieldview.h \
    fieldelement.h \
    field.h \
    battle_scene.h \
    player.h \
    unitinfo.h \
    turns_left_wnd.h \
    weapons_delta.h \
    all_defines.h

RESOURCES += \
    fonts.qrc \
    images.qrc
