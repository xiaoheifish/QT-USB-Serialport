#include <QtCore>
#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <masterthread.h>


//QMutex newmutex;
//QWaitCondition countIsZero;
//QWaitCondition countNotZero;
//int count = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
