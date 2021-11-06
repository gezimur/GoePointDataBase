TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../PostgreSQL/14/include \
               $$PWD/include \
               $$PWD/src

LIBS += -L$$PWD/../PostgreSQL/14/lib/ \
        -L$$PWD/lib

LIBS += -lpq -lGeologyDatabase_lib

SOURCES += \
            $$PWD/src/main.cpp

DESTDIR += $$PWD/test
TARGET = GeoPointDataBase_test_app
