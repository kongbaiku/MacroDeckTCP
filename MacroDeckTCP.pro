#-------------------------------------------------
#
# Project created by QtCreator 2022-12-13W10:00:00
#
#-------------------------------------------------

QT -= gui
QT += network

CONFIG += c++11
#CONFIG += console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

TARGET = MacroDeckTCP
TEMPLATE = app
VERSION = 0.0.0.1
RC_ICONS = ico.ico
RC_LANG = 0x0004

QMAKE_TARGET_COMPANY = LONY
QMAKE_TARGET_PRODUCT = MacroDeckTCP
QMAKE_TARGET_DESCRIPTION = MacroDeckTCP
QMAKE_TARGET_COPYRIGHT = Copyright(C) 2021-2077 LONY

SOURCES += \
        main.cpp

CONFIG(release, debug|release){
    DESTDIR = ./release/bin
}else{
    DESTDIR = ./debug/bin
}
