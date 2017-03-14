TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    time.cpp \
    test-time.cpp

HEADERS += \
    time.h \
    doctest.h
