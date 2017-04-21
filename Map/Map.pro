TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    menu.c \
    readFile.c \
    list.c \
    saveFile.c \
    updateInfo.c \
    table.c

HEADERS += \
    Macro.h \
    menu.h \
    listHeader.h \
    tableHeader.h

OTHER_FILES +=

