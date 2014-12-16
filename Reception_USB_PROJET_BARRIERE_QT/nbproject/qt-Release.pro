# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW-Windows
TARGET = Reception_USB_PROJET_BARRIERE_QT
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += C_CADRE.cpp C_COMMUNICATION_USB.cpp C_COMMUNICATION_USB_ECRIRE.cpp C_COMMUNICATION_USB_LIRE.cpp C_THREAD.cpp main.cpp
HEADERS += C_CADRE.h C_COMMUNICATION_USB.h C_COMMUNICATION_USB_ECRIRE.h C_COMMUNICATION_USB_LIRE.h C_THREAD.h
FORMS += C_CADRE.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
