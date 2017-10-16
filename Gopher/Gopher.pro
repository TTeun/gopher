#-------------------------------------------------
#
# Project created by QtCreator 2017-10-12T13:31:47
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gopher
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
    renderable/axis.cpp \
    renderable/renderable.cpp \
    renderable/surfacerenderable.cpp \
    parser/parser.cpp \
    parser/print.cpp \
    shaderhandler/shaderhandler.cpp \
    gldisplay.cpp \
    shaderhandler/shaderprogram.cpp \
    parser/collapse.cpp \
    parser/partialcollapse.cpp \
    glscene.cpp \
    surfacewidget.cpp \
    equationwidget.cpp

HEADERS += \
    mainwindow.h \
    renderable/axis.h \
    renderable/renderable.h \
    renderable/surfacerenderable.h \
    parser/parser.h \
    parser/print.h \
    shaderhandler/shaderhandler.h \
    gldisplay.h \
    shaderhandler/shaderprogram.h \
    parser/collapse.h \
    parser/partialcollapse.h \
    glscene.h \
    surfacewidget.h \
    equationwidget.h


FORMS += \
        mainwindow.ui \
    equationwidget.ui

RESOURCES += \
      resources.qrc
