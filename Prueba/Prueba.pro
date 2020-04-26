TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Bark.cpp \
    Manager.cpp \
    PrivateUserData.cpp \
    Publication.cpp \
    PublicUserData.cpp \
    Rebark.cpp \
    Reply.cpp \
    User.cpp

SUBDIRS += \
    Prueba.pro

DISTFILES +=

HEADERS += \
    Bark.hpp \
    Manager.hpp \
    PrivateUserData.hpp \
    Publication.hpp \
    PublicUserData.hpp \
    Rebark.hpp \
    Reply.hpp \
    User.hpp
