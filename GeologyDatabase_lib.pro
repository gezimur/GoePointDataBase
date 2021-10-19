TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../PostgreSQL/14/include \
               $$PWD/include \
               $$PWD/src

LIBS += -L$$PWD/../PostgreSQL/14/lib/

LIBS += -lpq

SOURCES += \
            $$PWD/include/ConnectionParams.cpp \
            $$PWD/src/PGConnection.cpp \
            $$PWD/src/Customer.cpp \
            $$PWD/src/DataBaseCtrl.cpp \
            $$PWD/src/Order.cpp \
            $$PWD/src/User.cpp \
            $$PWD/include/IDataBaseCtrl.cpp \
            $$PWD/include/DataBaseResponce.cpp \
            $$PWD/src/DataBase_staff.cpp

HEADERS += \
    $$PWD/src/AuthClientWdg.h \
    $$PWD/include/ConnectionParams.h \
    $$PWD/src/PGConnection.h \
    $$PWD/src/Customer.h \
    $$PWD/src/DataBaseCtrl.h \
    $$PWD/src/IDataType.h \
    $$PWD/src/ManagerCtrl.h \
    $$PWD/src/Order.h \
    $$PWD/src/User.h \
    $$PWD/include/IDataBaseCtrl.h \
    $$PWD/include/DataBaseResponce.h \
    $$PWD/src/DataBase_staff.h


DESTDIR += $$PWD/lib
TARGET = GeologyDatabase_lib
