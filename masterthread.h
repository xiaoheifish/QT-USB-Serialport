#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
class MasterThread : public QThread
{
    Q_OBJECT

public:
    MasterThread(QObject *parent = 0);
    ~MasterThread();

    void transaction(const QString &portName, int waitTimeout, const QString &request, int writeread);
    void run();
    void stop();
    void setReading(int isReading);
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
    int isReading;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
    bool working;
};


#endif // MASTERTHREAD_H
