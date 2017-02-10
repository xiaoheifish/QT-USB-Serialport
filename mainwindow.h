#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ftd2xx.h"
#include <QMessageBox>
#include <QTimer>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "writethread.h"
#include "masterthread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void writeOne();
    void writeserial();
    void showserial(const QString &s);
    void showserial2(const QString &s);
    void pathtwosenddata();
    void usbresponsedata(const QString &s, DWORD bytesreceived);
    void usbresponsedata2(const QString &s, DWORD bytesreceived);
    void on_buttonSelfWrite_clicked();
    void on_buttonSelfRead_clicked();
    void on_buttonAddWrite_clicked();
    void on_buttonSelfWrite_2_clicked();
    void showResponse(const QString &s);
    void on_buttonSelfRead_2_clicked();
    void on_buttonAddWrite_2_clicked();
    //void on_pushButton_clicked();
    void on_radioButtonUSB_clicked();
    void on_radioButtonSerial_clicked();
    //void on_buttonReadStop_clicked();
    void on_radioButtonUSBStop_clicked();
    void on_radioButtonreadstop_clicked();
    void on_buttonUSBStart_clicked();
    void close_USB();
private:
    Ui::MainWindow *ui;
    QString *channel;
    FT_HANDLE ftHandle;
    QTimer timer;
    QTimer timer2;
    QTimer timerserial;
    int currentBaudRate;
    int baudCount = 0;
    int USBstatus = 0;
    bool flagOne = true;
    bool flagTwo = false;
    bool USBcomm = false;
    unsigned long count1 = 0;
    unsigned long count2 = 0;
    unsigned long serialcount1 = 0;
    unsigned long serialcount2 = 0;
    MasterThread serialthread;
    MasterThread serialthread1;
    MasterThread *myserial;
    writethread thread;
};

#endif // MAINWINDOW_H
