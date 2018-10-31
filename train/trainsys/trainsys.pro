#-------------------------------------------------
#
# Project created by QtCreator 2017-05-20T13:46:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trainsys
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    adminfunc.cpp \
    adminwindows.cpp \
    adregister.cpp \
    findtrain.cpp \
    initopt.cpp \
    loginwindows.cpp \
    mydialog.cpp \
    normalwindows.cpp \
    notmatchdialog.cpp \
    regdialog.cpp \
    registerwindows.cpp \
    toolSet.cpp \
    userfunc.cpp \
    refund.cpp

HEADERS  += \
    adminwindows.h \
    adregister.h \
    classSet2.hpp \
    exceptions.hpp \
    initopt.hpp \
    logclass.h \
    loginwindows.h \
    map.hpp \
    mydialog.h \
    normalwindows.h \
    notmatchdialog.h \
    RB_Tree.hpp \
    regdialog.h \
    registerwindows.h \
    TicketClass.hpp \
    toolSet.hpp \
    TrainClass.hpp \
    UserClass.hpp \
    utility.hpp \
    varset.h \
    refund.h \
    vipfunc.h

FORMS += \
    adminwindows.ui \
    adregister.ui \
    loginwindows.ui \
    mydialog.ui \
    normalwindows.ui \
    notmatchdialog.ui \
    regdialog.ui \
    registerwindows.ui \
    refund.ui
