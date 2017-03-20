TEMPLATE = lib
CONFIG += c++11

# core Qt Libs to use add more here if needed.
QT+=gui opengl core
# as I want to support 4.8 and 5 this will set a flag for some of the mac stuff
# mainly in the types.h file for the setMacVisual which is native in Qt5
isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}
# where to put moc auto generated files
MOC_DIR=./moc

# File paths
INCLUDEPATH += $$PWD/include/

HEADERS += $$PWD/include/*.h

SOURCES += $$PWD/src/*.cpp\
                glew/glew.c

# Library target directory
TARGET = $$PWD/lib/mTex
OBJECTS_DIR=obj


INCLUDEPATH += ./include \
                $$PWD/lib


# NGL inludes
NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){ # note brace must be here
        message("including $HOME/NGL")
        include($(HOME)/NGL/UseNGL.pri)
}
else{ # note brace must be here
        message("Using custom NGL location")
        include($(NGLDIR)/UseNGL.pri)
}
