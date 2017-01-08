#pragma comment(lib, "D:\\Qt\\Project\\trySSIupper\\ftd2xx.lib")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>
#include <QDebug>
using namespace std;
inline string i2s(int number)
{
    string s;
    if(number == 0){
        s = (char)(0 + '0');
    }
    while(number != 0)
    {
        s = (char)(number % 10 + '0') + s;
        number = number / 10;
    }
    return s;
}
inline QString s2q(const string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}
inline QByteArray intToByte(int i)
{
    QByteArray abyte0;
    abyte0.resize(4);
    abyte0[0] = (uchar)  (0x000000ff & i);
    abyte0[1] = (uchar) ((0x0000ff00 & i) >> 8);
    abyte0[2] = (uchar) ((0x00ff0000 & i) >> 16);
    abyte0[3] = (uchar) ((0xff000000 & i) >> 24);
    return abyte0;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Set tabWidget background transparent
    ui->tabWidget->setStyleSheet("QTabWidget:pane{border-top:0px solid #e8f3f9;background:transparent;}");
    //Get current available COM port
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->serialPortComboBox->addItem(info.portName());
    ui->serialPortComboBox->setFocus();
    connect(&serialthread, SIGNAL(response(QString)),
            this, SLOT(showResponse(QString)));
    connect(&serialthread, SIGNAL(responserial(QString)),
            this,SLOT(showserial(QString)));
    connect(&serialthread, SIGNAL(responserial2(QString)),
            this,SLOT(showserial2(QString)));
    UCHAR Mode = 0x40;//Set single chanel synchronous FT245 mode
    UCHAR Mask = 0xff;//written to device
    FT_STATUS ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus == FT_OK)
    {
        ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    }
    FT_Close(ftHandle);
    Sleep(2);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(serialthread.isRunning()){
        serialthread.stop();
    }

    /*if(thread.isRunning()){
        thread.stop();
    }*/
    //FT_Close(ftHandle);
}

void MainWindow::on_buttonSelfWrite_clicked()
{
    //thread.setFtHandle(ftHandle);
    //thread.setUi(ui);
    //thread.start();

    //UCHAR Mode = 0x40;//Set single chanel synchronous FT245 mode
    //UCHAR Mask = 0x00;//written to device
    BYTE TxBufferAdd[2]={0};
    DWORD BytesWritten;
    //FT_STATUS ftStatus = FT_Open(0, &ftHandle);
    //if(ftStatus != FT_OK)
    //{//FT_Open failed
      //return;
    //}
    //ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    //Sleep(2);
    TxBufferAdd[0]=0x01;
    TxBufferAdd[1]=(ui->textSelfWrite->text()).toInt();
    FT_STATUS ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
    if(ftStatus == FT_OK){
        QMessageBox::information(this, "Message", "自检数据已经写入硬件");
    }
    //FT_Close(ftHandle);
    //Mode = 0x0;
    //ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    //ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    //Sleep(2);
}

void MainWindow::on_buttonSelfRead_clicked()
{
    BYTE TxBufferSelf[1]={0};
    BYTE RxBuffer[4]={0};
    DWORD BytesReceived;
    DWORD BytesWritten;
    DWORD RxBytes=0;
    DWORD TxBytes=0;
    DWORD EventDWord;
    //UCHAR Mode = 0x40;//Set single chanel synchronous FT245 mode
    //UCHAR Mask = 0x00;//written to device
    TxBufferSelf[0]=0x08;
    FT_STATUS ftStatus = FT_Write(ftHandle, TxBufferSelf, 1, &BytesWritten);
    //cout<<"WRITE:"<<ftStatus<<"\n";
    //ftStatus = FT_Close(ftHandle);
    //Sleep(1);
    //FT_STATUS ftStatus = FT_Open(0, &ftHandle);
    //Sleep(1);
    //ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
    if(RxBytes!=0){
        cout<<"RxBytes:"<<RxBytes<<"\n";
        cout.flush();
    }
    if ((RxBytes >= 0)&&(ftStatus == FT_OK))
    {
        ftStatus = FT_Read(ftHandle,RxBuffer,4,&BytesReceived);
        cout<<"READ:"<<BytesReceived<<"\n";
        //for(int i = 0; i < )
        for(int i =0; i < BytesReceived; i++){
            if (RxBuffer[i]!=0 ){
                cout<<"i:"<<i<<"\n";
                ui->textSelfRead->setText(QString::number(RxBuffer[i],10));
            }
        }
    }

}
void MainWindow::on_buttonAddWrite_clicked()
{
    BYTE TxBufferAdd[2]={0};
    DWORD BytesWritten;
    FT_STATUS ftStatus;
    if(ui->checkBoxPathOne->isChecked()){
        TxBufferAdd[0]=0x10;
        TxBufferAdd[1]=ui->textPathOne->text().toInt();
        cout<<i2s(TxBufferAdd[1])<<"\n";
        ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
        cout<<BytesWritten<<"\n";
    }
    if(ui->checkBoxPathTwo->isChecked()){
        TxBufferAdd[0]=0x11;
        TxBufferAdd[1]=ui->textPathTwo->text().toInt();
        ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
        //timer2.start(20);
        //connect(&timer2,SIGNAL(timeout()),this,SLOT(writeTwo()));
    }
    timer.start(1);
    connect(&timer,SIGNAL(timeout()),this,SLOT(writeOne()));
    //QMessageBox::information(this, "Message", "位宽数据已经写入硬件");
}

void MainWindow::writeOne(){
    DWORD RxBytes = 4;
    DWORD TxBytes = 0;
    UCHAR RxBuffer[16]={0};
    UCHAR TxBuffer[1]={0};
    DWORD BytesWritten;
    DWORD BytesReceived;
    DWORD EventDWord;
    QString numberRec = "";
    QString numberRec2 = "";
    FT_STATUS ftStatus;
    if(ui->checkBoxPathOne->isChecked()){
        TxBuffer[0]=0x20;
        ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
        ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        while(RxBytes < 4){
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        }
        if((RxBytes >= 0)&&(ftStatus == FT_OK))
        {
            ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
            ui->labelPath11->setText(QString::number(RxBuffer[0],10));
            //cout<<i2s(RxBuffer[0])<<"\n";
            ui->labelPath12->setText(QString::number(RxBuffer[1],10));
            //cout<<i2s(RxBuffer[1])<<"\n";
            count1 += 1;
            ui->labelCount1->setText(QString::number(count1,10));
            ui->labelPath13->setText(QString::number(RxBuffer[2],10));
            //cout<<i2s(RxBuffer[2])<<"\n";
            ui->labelPath14->setText(QString::number(RxBuffer[3],10));
            //cout<<i2s(RxBuffer[3])<<"\n";
            ui->totalCount1->setText(QString::number(BytesReceived,10));
            for(int i = 0; i < BytesReceived; i++)
            {
                numberRec.append(s2q(i2s(RxBuffer[i])));
                numberRec.append(" ");
            }
            ui->textBrowserPathOne->append(numberRec);
        }
    }
    if(ui->checkBoxPathTwo->isChecked()){
        TxBuffer[0]=0x24;
        ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
        ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        while(RxBytes < 4){
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        }
        if ((RxBytes >= 0)&&(ftStatus == FT_OK))
        {
            ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
            ui->labelPath21->setText(QString::number(RxBuffer[0],10));
            ui->labelPath22->setText(QString::number(RxBuffer[1],10));
            if(BytesReceived != 0){
                count2 += 1;
            }
            ui->labelCount2->setText(QString::number(count2,10));
            ui->labelPath23->setText(QString::number(RxBuffer[2],10));
            ui->labelPath24->setText(QString::number(RxBuffer[3],10));
            ui->totalCount2->setText(QString::number(BytesReceived,10));
            for(int i = 0; i < BytesReceived; i++)
            {
                numberRec2.append(s2q(i2s(RxBuffer[i])));
                numberRec2.append(" ");
            }
            ui->textBrowserPathTwo->append(numberRec2);
        }
    }
}

void MainWindow::showResponse(const QString &s)
{
    ui->textSelfRead_2->setText(tr("Data:%1").arg(s));
}

void MainWindow::on_buttonSelfWrite_2_clicked()
{
    int writeread = 10;
    int timeout = 1000;
    serialthread.transaction(ui->serialPortComboBox->currentText(),
                       timeout,
                       "01" + ui->textSelfWrite_2->text(),
                       writeread);
}

void MainWindow::on_buttonSelfRead_2_clicked()
{
    int writeread = 11;
    int timeout = 1000;
    serialthread.transaction(ui->serialPortComboBox->currentText(),
                       timeout,
                       "08",
                       writeread);
}

void MainWindow::on_buttonAddWrite_2_clicked()
{
    int writeread = 10;
    int timeout = 1000;
    QString requestdata="";
    if(ui->checkBoxPathOne_2->isChecked()&&(ui->checkBoxPathTwo_2->checkState()==Qt::Unchecked)){
        requestdata = "16" + ui->textPathOne_2->text();
    }
    if(ui->checkBoxPathTwo_2->isChecked()&&(ui->checkBoxPathOne_2->isChecked()==false)){
        requestdata = "17" + ui->textPathTwo_2->text();
    }
    if(ui->checkBoxPathOne_2->isChecked()&&ui->checkBoxPathTwo_2->isChecked()){
        requestdata = "16" + ui->textPathOne_2->text() + "17" + ui->textPathTwo_2->text();
    }
    serialthread.transaction(ui->serialPortComboBox->currentText(),
                       timeout,
                       requestdata,
                       writeread);
    //timerserial.start(2000);
    //connect(&timerserial,SIGNAL(timeout()),this,SLOT(writeserial()));
}
void MainWindow::writeserial()
{
    int writeread = 12;
    int timeout = 1000;
    if(ui->checkBoxPathOne_2->isChecked()){
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                           timeout,
                           "20212223",
                           writeread);
    }
    if(ui->checkBoxPathTwo_2->isChecked()){
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                           timeout,
                           "24252627",
                           writeread);
    }
}
void MainWindow::on_pushButton_clicked()
{
    int writeread = 12;
    int timeout = 1000;
    if(ui->checkBoxPathOne_2->isChecked()){
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                           timeout,
                           "20212223",
                           writeread);
    }
    if(ui->checkBoxPathTwo_2->isChecked()){
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                           timeout,
                           "24252627",
                           writeread);
    }
}

void MainWindow::showserial(const QString &s)
{
    serialcount1 += 1;
    ui->labelPath14_2->setText(s.mid(0,2));
    ui->labelPath13_2->setText(s.mid(2,2));
    ui->labelPath12_2->setText(s.mid(4,2));
    ui->labelPath11_2->setText(s.mid(6,2));
    ui->labelCount1_2->setText(QString::number(serialcount1,10));
    ui->textBrowserPathOne_2->append(s);
    ui->totalCount1_2->setText(QString::number(s.length(),10));
}
void MainWindow::showserial2(const QString &s)
{
    serialcount2 += 1;
    ui->labelPath24_2->setText(s.mid(0,2));
    ui->labelPath23_2->setText(s.mid(2,2));
    ui->labelPath22_2->setText(s.mid(4,2));
    ui->labelPath21_2->setText(s.mid(6,2));
    ui->labelCount2_2->setText(QString::number(serialcount2,10));
    ui->textBrowserPathTwo_2->append(s);
    ui->totalCount2_2->setText(QString::number(s.length(),10));
}
/*
void MainWindow::writeTwo(){
    DWORD RxBytes = 4;
    DWORD TxBytes = 0;
    UCHAR RxBuffer[4]={0};
    UCHAR TxBuffer[1]={0};
    DWORD BytesWritten;
    DWORD EventDWord;
    DWORD BytesReceived;
    FT_STATUS ftStatus;
    if(ui->checkBoxPathTwo->isChecked()){
        TxBuffer[0]=0x24;
        ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
        ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        if ((RxBytes >= 0)&&(ftStatus == FT_OK))
        {
            ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
            ui->labelPath21->setText(QString::number(RxBuffer[0],10));
            ui->labelPath22->setText(QString::number(RxBuffer[1],10));
            count2 += 1;
            ui->labelCount2->setText(QString::number(count2,10));
            ui->labelPath23->setText(QString::number(RxBuffer[2],10));
            ui->labelPath24->setText(QString::number(RxBuffer[3],10));
        }
    }
}

void MainWindow::on_buttonReadPathOne_clicked(){
    DWORD RxBytes = 4;
    DWORD TxBytes = 0;
    UCHAR RxBuffer[65536]={0};
    UCHAR TxBuffer[1]={0};
    DWORD BytesWritten;
    DWORD BytesReceived;
    DWORD EventDWord;
    QString numberRec = "";
    QString numberRec2 = "";
    FT_STATUS ftStatus;
    int j = 0;
    while(j<65536)
    {
        if(ui->checkBoxPathOne->isChecked()){
            TxBuffer[0]=0x20;
            ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            while(RxBytes < 4){
                ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            }
            if((RxBytes >= 0)&&(ftStatus == FT_OK))
            {
                ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
                ui->labelPath11->setText(QString::number(RxBuffer[0],10));
                //cout<<i2s(RxBuffer[0])<<"\n";
                ui->labelPath12->setText(QString::number(RxBuffer[1],10));
                //cout<<i2s(RxBuffer[1])<<"\n";
                count1 += 1;
                ui->labelCount1->setText(QString::number(count1,10));
                ui->labelPath13->setText(QString::number(RxBuffer[2],10));
                //cout<<i2s(RxBuffer[2])<<"\n";
                ui->labelPath14->setText(QString::number(RxBuffer[3],10));
                //cout<<i2s(RxBuffer[3])<<"\n";
                ui->totalCount1->setText(QString::number(BytesReceived,10));
                for(int i = 0; i < BytesReceived; i++)
                {
                    numberRec.append(s2q(i2s(RxBuffer[i])));
                    numberRec.append(" ");
                }
                ui->textBrowserPathOne->append(numberRec);
            }
        }
        if(ui->checkBoxPathTwo->isChecked()){
            TxBuffer[0]=0x24;
            ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            while(RxBytes < 4){
                ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            }
            if ((RxBytes >= 0)&&(ftStatus == FT_OK))
            {
                ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
                ui->labelPath21->setText(QString::number(RxBuffer[0],10));
                ui->labelPath22->setText(QString::number(RxBuffer[1],10));
                if(BytesReceived != 0){
                    count2 += 1;
                }
                ui->labelCount2->setText(QString::number(count2,10));
                ui->labelPath23->setText(QString::number(RxBuffer[2],10));
                ui->labelPath24->setText(QString::number(RxBuffer[3],10));
                ui->totalCount2->setText(QString::number(BytesReceived,10));
                for(int i = 0; i < BytesReceived; i++)
                {
                    numberRec2.append(s2q(i2s(RxBuffer[i])));
                    numberRec2.append(" ");
                }
                ui->textBrowserPathTwo->append(numberRec2);
            }
        }
    }
}

void MainWindow::on_buttonReadPathOne_clicked()
{
    DWORD RxBytes = 4;
    DWORD TxBytes = 0;
    UCHAR RxBuffer[4]={0};
    UCHAR TxBuffer[1]={0};
    DWORD BytesWritten;
    DWORD BytesReceived;
    DWORD EventDWord;
    FT_STATUS ftStatus;
    if(ui->checkBoxPathOne->isChecked()){
        TxBuffer[0]=0x20;
        ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
        ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        if(RxBytes!=0){
            cout<<"RxBytes:"<<RxBytes<<"\n";
            cout.flush();
        }
        if ((RxBytes >= 0)&&(ftStatus == FT_OK))
        {
            ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
            ui->labelPath11->setText(QString::number(RxBuffer[0],10));
            cout<<i2s(RxBuffer[0])<<"\n";
            ui->labelPath12->setText(QString::number(RxBuffer[1],10));
            cout<<i2s(RxBuffer[1])<<"\n";
            ui->labelPath13->setText(QString::number(RxBuffer[2],10));
            cout<<i2s(RxBuffer[2])<<"\n";
            ui->labelPath14->setText(QString::number(RxBuffer[3],10));
            cout<<i2s(RxBuffer[3])<<"\n";
        }
    }
}

void MainWindow::on_buttonReadPathTwo_clicked()
{
    DWORD RxBytes = 4;
    DWORD TxBytes = 0;
    UCHAR RxBuffer[4]={0};
    UCHAR TxBuffer[1]={0};
    DWORD BytesWritten;
    DWORD EventDWord;
    DWORD BytesReceived;
    FT_STATUS ftStatus;
    if(ui->checkBoxPathTwo->isChecked()){
        TxBuffer[0]=0x24;
        ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
        ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
        if ((RxBytes >= 0)&&(ftStatus == FT_OK))
        {
            ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
            ui->labelPath21->setText(QString::number(RxBuffer[0],10));
            ui->labelPath22->setText(QString::number(RxBuffer[1],10));
            ui->labelPath23->setText(QString::number(RxBuffer[2],10));
            ui->labelPath24->setText(QString::number(RxBuffer[3],10));
        }
    }
}
*/



