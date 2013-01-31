QT       -= gui
TARGET = QtHelpers
TEMPLATE = lib

DEFINES += QTHELPERS_LIBRARY

HEADERS += QtHelpers_global.h \
    TempVal.h \
    Optional.h \
    SafeConnect.h\
    QObjectDescription.h \
    DelayedSignalEmitter.h

SOURCES += \
    DelayedSignalEmitter.cpp
