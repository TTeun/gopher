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
    RenderableObjects/axis.cpp \
    RenderableObjects/renderable.cpp \
    RenderableObjects/surfacerenderable.cpp \
    parser/parser.cpp \
    parser/print.cpp \
    ShaderHandler/shaderhandler.cpp \
    gldisplay.cpp \
    RenderableObjects/displayobjects.cpp \
    ShaderHandler/Implementations/shaderprogram.cpp \
    parser/collapse.cpp \
    parser/partialcollapse.cpp \
    parser/equalityvisitor.cpp

HEADERS += \
    mainwindow.h \
    RenderableObjects/axis.h \
    RenderableObjects/renderable.h \
    RenderableObjects/surfacerenderable.h \
    parser/parser.h \
    parser/print.h \
    ShaderHandler/shaderhandler.h \
    gldisplay.h \
    RenderableObjects/displayobjects.h \
    ShaderHandler/Implementations/shaderprogram.h \
    parser/collapse.h \
    parser/partialcollapse.h \
    parser/equalityvisitor.h


FORMS += \
        mainwindow.ui

RESOURCES += \
      resources.qrc
