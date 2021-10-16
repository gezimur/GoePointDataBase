TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../PostgreSQL/include \
               $$PWD/include \
               $$PWD/src

LIBS += -L$$PWD/../PostgreSQL/lib/

LIBS += -lpq

SOURCES += \
            $$PWD/include/ConnectionParams.cpp \
            $$PWD/src/PGConnection.cpp \
            $$PWD/src/Customer.cpp \
            $$PWD/src/DataBaseCtrl.cpp \
            $$PWD/src/Order.cpp \
            $$PWD/src/User.cpp \
            $$PWD/include/IDataBaseCtrl.cpp \
            include/DataBaseResponce.cpp \
            src/DataBase_staff.cpp

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
    include/DataBaseResponce.h \
    src/DataBase_staff.h

DESTDIR += $$PWD/lib
TARGET = GeologyDatabase_lib
