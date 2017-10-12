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
    RenderableObjects/ballrenderable.cpp \
    RenderableObjects/renderable.cpp \
    RenderableObjects/surfacerenderable.cpp \
    ShaderHandler/Implementations/blackshader.cpp \
    ShaderHandler/Implementations/flatshader.cpp \
    ShaderHandler/Implementations/mainshader.cpp \
    ShaderHandler/Implementations/normalshader.cpp \
    parser/parser.cpp \
    parser/simplify.cpp \
    parser/print.cpp \
    equationhandler.cpp \
    ShaderHandler/shaderhandler.cpp \
    globjects.cpp

HEADERS += \
    mainwindow.h \
    RenderableObjects/axis.h \
    RenderableObjects/ballrenderable.h \
    RenderableObjects/renderable.h \
    RenderableObjects/surfacerenderable.h \
    ShaderHandler/Implementations/blackshader.h \
    ShaderHandler/Implementations/flatshader.h \
    ShaderHandler/Implementations/mainshader.h \
    ShaderHandler/Implementations/normalshader.h \
    parser/parser.h \
    parser/simplify.h \
    parser/print.h \
    equationhandler.h \
    ShaderHandler/shaderhandler.h \
    globjects.h


FORMS += \
        mainwindow.ui
