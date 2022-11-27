#-------------------------------------------------
#
# Project created by QtCreator 2022-11-08T20:37:06
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grademanagement
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    sysmysql.cpp \
    studentinfo.cpp \
    stuupdate.cpp \
    course.cpp \
    couupdate.cpp \
    grade.cpp \
    gradeupdate.cpp \
    login.cpp \
    student.cpp \
    teacher.cpp \
    taestu.cpp \
    admin.cpp \
    user.cpp \
    userupdate.cpp \
    teainfo.cpp \
    teaupdata.cpp

HEADERS += \
        mainwindow.h \
    sysmysql.h \
    studentinfo.h \
    stuupdate.h \
    course.h \
    couupdate.h \
    grade.h \
    gradeupdate.h \
    login.h \
    student.h \
    teacher.h \
    taestu.h \
    admin.h \
    user.h \
    userupdate.h \
    teainfo.h \
    teaupdata.h

FORMS += \
        mainwindow.ui \
    studentinfo.ui \
    stuupdate.ui \
    course.ui \
    couupdate.ui \
    grade.ui \
    gradeupdate.ui \
    login.ui \
    student.ui \
    teacher.ui \
    taestu.ui \
    admin.ui \
    user.ui \
    userupdate.ui \
    teainfo.ui \
    teaupdata.ui
