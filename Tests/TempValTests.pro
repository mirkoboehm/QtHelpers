QT       += testlib
QT       -= gui

TARGET = tst_TempValTests
CONFIG   += console testcase
CONFIG   -= app_bundle
INCLUDEPATH += ../
TEMPLATE = app


SOURCES += tst_TempValTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
