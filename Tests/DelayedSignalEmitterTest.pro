QT       += testlib
QT       -= gui

TARGET = tst_DelayedSignalEmitterTest
CONFIG   += console
CONFIG   -= app_bundle
INCLUDEPATH += ../
DEPENDPATH  += ../
TEMPLATE = app


SOURCES += tst_DelayedSignalEmitterTest.cpp \
    ../QtHelpers/DelayedSignalEmitter.cpp
HEADERS += ../QtHelpers/DelayedSignalEmitter.h
DEFINES += SRCDIR=\\\"$$PWD/\\\"
