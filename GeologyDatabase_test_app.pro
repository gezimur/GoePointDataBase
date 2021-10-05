TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=  $$PWD/../PostgreSQL/include \
                $$PWD/include \
                $$PWD/src

LIBS += -L$$PWD/../PostgreSQL/lib/ \
        -L$$PWD/lib

LIBS += -lpq -lGeologyDatabase_lib

SOURCES += \
            $$PWD/src/main.cpp

DESTDIR += $$PWD/bin
