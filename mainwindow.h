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
    //void writeTwo();
    void on_buttonSelfWrite_clicked();
    void on_buttonSelfRead_clicked();
    void on_buttonAddWrite_clicked();
    //void on_buttonReadPathOne_clicked();
    //void on_buttonReadPathTwo_clicked();
    void on_buttonSelfWrite_2_clicked();
    void showResponse(const QString &s);

    void on_buttonSelfRead_2_clicked();

    void on_buttonAddWrite_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    FT_HANDLE ftHandle;
    QTimer timer;
    QTimer timer2;
    QTimer timerserial;
    bool flagOne = false;
    bool flagTwo = false;
    unsigned long count1 = 0;
    unsigned long count2 = 0;
    unsigned long serialcount1 = 0;
    unsigned long serialcount2 = 0;
    MasterThread serialthread;
    //writethread thread;
};

#endif // MAINWINDOW_H
