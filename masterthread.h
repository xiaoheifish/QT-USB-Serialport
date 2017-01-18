#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMainWindow>
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include <QtSerialPort/QSerialPort>
=======
>>>>>>> 1f55b256b6ee6ae379dd9bbdf7ebd6318d7b8866
class MasterThread : public QThread
{
    Q_OBJECT

public:
    MasterThread(QObject *parent = 0);
    ~MasterThread();

    void transaction(const QString &portName, int waitTimeout, const QString &request, int writeread);
    void run();
    void stop();
<<<<<<< HEAD
    void setReading(int isReading);
=======

>>>>>>> 1f55b256b6ee6ae379dd9bbdf7ebd6318d7b8866
signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
    void responserial(const QString &s);
    void responserial2(const QString &s);
private:
    QString portName;
    QString request;
    int waitTimeout;
    int writeread;
<<<<<<< HEAD
    int isReading;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
=======
    QMutex mutex;
    QWaitCondition cond;
    bool quit;

>>>>>>> 1f55b256b6ee6ae379dd9bbdf7ebd6318d7b8866
    bool working;
};


#endif // MASTERTHREAD_H
