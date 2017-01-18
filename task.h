#ifndef TASK_H
#define TASK_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMainWindow>
#include <queue>
#include "ui_mainwindow.h"
class Task : QObject
{
    Q_OBJECT
private:
    QString portName;
    int waitTimeout;
    QString request;
    int writeread;
signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
    void responserial(const QString &s);
    void responserial2(const QString &s);
public:
    Task(const QString &portName, int waitTimeout, const QString &request, int writeread);
    void run();
    ~Task();
};

#endif // TASK_H
