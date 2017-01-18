#ifndef WRITETHREAD_H
#define WRITETHREAD_H
#include <QThread>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "ui_mainwindow.h"
#include "ftd2xx.h"
#include <string>
class writethread : public QThread
{
    Q_OBJECT
public:
    writethread();
    ~writethread();
    void setUi(Ui::MainWindow *ui);
    void setFtHandle(FT_HANDLE handle);
    void stop();
protected:
    void run();


<<<<<<< HEAD
private slots:

=======
>>>>>>> 1f55b256b6ee6ae379dd9bbdf7ebd6318d7b8866
private:

    volatile bool stopped;
    Ui::MainWindow *ui;
    FT_HANDLE ftHandle;
};

#endif // WRITETHREAD_H
