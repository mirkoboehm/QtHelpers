QT       += testlib
QT       -= gui

TARGET = tst_OptionalValueTests
CONFIG   += console testcase
CONFIG   -= app_bundle
INCLUDEPATH += ../
DEPENDPATH  += ../
TEMPLATE = app

SOURCES += tst_OptionalValueTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
