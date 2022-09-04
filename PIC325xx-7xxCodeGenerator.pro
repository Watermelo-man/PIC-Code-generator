QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chooseMC.cpp \
    csvhandler.cpp \
    main.cpp \
    mainwindow.cpp \
    qfilework.cpp \
    regexpcontrol.cpp \
    spiform.cpp

HEADERS += \
    chooseMC.h \
    csvhandler.h \
    mainwindow.h \
    qfilework.h \
    regexpcontrol.h \
    spiform.h

FORMS += \
    chooseMC.ui \
    mainwindow.ui \
    spiform.ui

TRANSLATIONS += \
    PIC325xx-7xxCodeGenerator_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
