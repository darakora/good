#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T03:06:07
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shop_test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        agewindow.cpp \
        authorization.cpp \
        baselistmodel.cpp \
        categorywindow.cpp \
        comboboxmodel.cpp \
        database.cpp \
        goodswindow.cpp \
        kindnew.cpp \
        logic.cpp \
        main.cpp \
        password.cpp \
        unitswindow.cpp

HEADERS += \
        agewindow.h \
        authorization.h \
        baselistmodel.h \
        categorywindow.h \
        comboboxmodel.h \
        database.h \
        goodswindow.h \
        kindnew.h \
        logic.h \
        password.h \
        queries.h \
        unitswindow.h \
        util.h

FORMS += \
        agewindow.ui \
        authorization.ui \
        category.ui \
        goods.ui \
        kindnew.ui \
        password.ui \
        unitswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
