#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T16:30:15
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}


TARGET = trySSIupper
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    writethread.cpp \
    masterthread.cpp

HEADERS  += mainwindow.h \
    writethread.h \
    masterthread.h

FORMS    += mainwindow.ui
