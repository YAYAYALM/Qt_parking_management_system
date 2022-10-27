QT       += core gui network sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogwin.cpp \
    adminone.cpp \
    admintwo.cpp \
    adminwin.cpp \
    formpark.cpp \
    main.cpp \
    mycamera.cpp \
    parkonewin.cpp \
    parktwowin.cpp \
    parkwin.cpp \
    rfid.cpp

HEADERS += \
    adminlogwin.h \
    adminone.h \
    admintwo.h \
    adminwin.h \
    formpark.h \
    mycamera.h \
    parkonewin.h \
    parktwowin.h \
    parkwin.h \
    rfid.h

FORMS += \
    adminlogwin.ui \
    adminone.ui \
    admintwo.ui \
    adminwin.ui \
    formpark.ui \
    parkonewin.ui \
    parktwowin.ui \
    parkwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    map.qrc
