QT       += testlib
QT       -= gui

TARGET = tst_SafeConnectTests
CONFIG   += console testcase
CONFIG   -= app_bundle
INCLUDEPATH += ../
DEPENDPATH  += ../
TEMPLATE = app


SOURCES += tst_SafeConnectTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
