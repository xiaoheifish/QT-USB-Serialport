#ifndef WRITETHREAD_H
#define WRITETHREAD_H
#include <QThread>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QWaitCondition>
#include "ui_mainwindow.h"
#include "ftd2xx.h"
#include <string>
#include <QFile>
#include <QTextStream>
class writethread : public QThread
{
    Q_OBJECT
public:
    writethread();
    ~writethread();
    void transaction();
    void setUi(Ui::MainWindow *ui);
    void setFtHandle(FT_HANDLE handle);
    void setChannel(QString *channel);
    void stop();
    QString tohex(UCHAR number);
    void setReading(int isReading);
protected:
    void run();
signals:
    void usbresponse(const QString &s, DWORD bytesreceived);
    void usbresponse2(const QString &s, DWORD bytesreceived);
    void close_USBsignal();
private:
    volatile bool stopped;
    Ui::MainWindow *ui;
    QString *channel;
    QFile *file;
    QTextStream *out;
    FT_HANDLE ftHandle;
    QMutex mutex;
    QWaitCondition usbcond;
    int isReading;
};

#endif // WRITETHREAD_H
