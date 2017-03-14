TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test-mytime.cpp \
    mytime.cpp

HEADERS += \
    doctest.h \
    mytime.h
