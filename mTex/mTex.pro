TEMPLATE = lib
CONFIG += c++11


HEADERS += $$PWD/include/*.h
INCLUDEPATH += $$PWD/include/
SOURCES += $$PWD/src/*.cpp


MOC_DIR = ./moc
TARGET = $$PWD/lib/mTex
OBJECTS_DIR=obj


INCLUDEPATH += ./include \
                $$PWD/lib

