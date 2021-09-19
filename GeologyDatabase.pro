TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../PostgreSQL/include

LIBS += -L$$PWD/../PostgreSQL/lib/

LIBS += -lpq

SOURCES += $$PWD/src/main.cpp

SOURCES += \
        $$PWD/src/ConnectionParams.cpp \
        $$PWD/src/PGConnection.cpp \
        $$PWD/src/PGConnectionCtrl.cpp \


HEADERS += \
    $$PWD/src/ConnectionParams.h \
    $$PWD/src/PGConnection.h \
    $$PWD/src/PGConnectionCtrl.h


DESTDIR += $$PWD/bin
