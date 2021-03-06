#pragma comment(lib, "D:\\Qt\\USB2.0uppermachine-master\\ftd2xx.lib")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <iostream>
#include <QDebug>
#define TxSector (1024*64)
#define RxSector (1024*64)

using namespace std;
inline string i2s(int number)
{
    //new code
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
    channel = new QString;
    *channel = "";
    qRegisterMetaType<DWORD>("DWORD");
    connect(&serialthread, SIGNAL(response(QString)),
            this, SLOT(showResponse(QString)));
    connect(&serialthread, SIGNAL(responserial(QString)),
            this,SLOT(showserial(QString)));
    connect(&serialthread, SIGNAL(responserial2(QString)),
            this,SLOT(showserial2(QString)));
    connect(&serialthread, SIGNAL(pathtwosend()),
            this,SLOT(pathtwosenddata()));
    connect(&thread, SIGNAL(usbresponse(QString, DWORD)),
            this,SLOT(usbresponsedata(QString,DWORD)));
    connect(&thread, SIGNAL(usbresponse2(QString,DWORD)),
            this,SLOT(usbresponsedata2(QString,DWORD)));
    connect(&thread, SIGNAL(close_USBsignal()),
            this, SLOT(close_USB()));
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->serialPortComboBox->addItem(info.portName());
    ui->serialPortComboBox->setFocus();
}
MainWindow::~MainWindow()
{
    delete ui;
    if(serialthread.isRunning()){
        serialthread.stop();
    }
    if(thread.isRunning()){
        thread.stop();
    }
    if(USBcomm == true){
        FT_Close(ftHandle);
    }
    if (channel != NULL){
        delete channel;
        channel = NULL;
    }
}
void MainWindow::pathtwosenddata(){
    int writeread = 9;
    int timeout = 1000;
    if(ui->serialPortComboBox->currentText()!=""){
        currentBaudRate = ui->comboBoxBaud->currentIndex();
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                                 ui->comboBoxBaud->currentIndex(),
                                 timeout,
                                 "88",
                                 writeread);
    }
}

void MainWindow::on_radioButtonSerial_clicked(){
    //delete current item
    for(int i =0;i < ui->serialPortComboBox->count();i++){
        ui->serialPortComboBox->removeItem(0);
    }
    //Get current available COM port
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->serialPortComboBox->addItem(info.portName());
    ui->serialPortComboBox->setFocus();
    int writeread = 9;
    int timeout = 1000;
    if(ui->serialPortComboBox->currentText()!=""){
        currentBaudRate = ui->comboBoxBaud->currentIndex();
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                                 ui->comboBoxBaud->currentIndex(),
                                 timeout,
                                 "FF",
                                 writeread);
    }
}
void MainWindow::on_radioButtonUSB_clicked(){
    USBcomm = true;
    UCHAR LatencyTimer = 1;
    UCHAR Mode = 0x40;//Set single chanel synchronous FT245 mode
    UCHAR Mask = 0xff;//written to device
    FT_STATUS ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus == FT_OK)
    {
        ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
    }
    if (ftStatus == FT_OK)
    {
        ftStatus = FT_SetLatencyTimer(ftHandle, LatencyTimer);
        ftStatus = FT_SetUSBParameters(ftHandle, RxSector, TxSector); // (64KB, 512B)
        ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, 0, 0);
        ftStatus = FT_Purge(ftHandle, FT_PURGE_RX);
        // access data from here
    }
}

void MainWindow::on_radioButtonUSBStop_clicked()
{
    flagOne = false;
    if(thread.isRunning()){
        thread.setReading(0);
    }
    if(USBstatus == 1 || USBstatus == 2){
        FT_Close(ftHandle);
    }
//    if(USBcomm == true){
//        timer.stop();
//        FT_Close(ftHandle);
//    }
}
void MainWindow::on_radioButtonreadstop_clicked()
{
    serialthread.setReading(0);
    if(serialthread.getState()!=12){
        int writeread = 9;
        int timeout = 1000;
        if(ui->serialPortComboBox->currentText()!=""){
            currentBaudRate = ui->comboBoxBaud->currentIndex();
            serialthread.transaction(ui->serialPortComboBox->currentText(),
                                     ui->comboBoxBaud->currentIndex(),
                                     timeout,
                                     "88",
                                     writeread);
        }
    }
}
void MainWindow::on_buttonSelfWrite_clicked()
{
    USBstatus = 1;
    BYTE TxBufferAdd[2]={0};
    DWORD BytesWritten;
    TxBufferAdd[0]=0x01;
    TxBufferAdd[1]=(ui->textSelfWrite->text()).toInt();
    FT_STATUS ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
    if(ftStatus == FT_OK){
        QMessageBox::information(this, "Message", "自检数据已经写入硬件");
    }
}

void MainWindow::on_buttonSelfRead_clicked()
{
    USBstatus = 2;
    BYTE TxBufferSelf[1]={0};
    BYTE RxBuffer[4]={0};
    DWORD BytesReceived;
    DWORD BytesWritten;
    DWORD RxBytes=0;
    DWORD TxBytes=0;
    DWORD EventDWord;
    TxBufferSelf[0]=0x08;
    FT_STATUS ftStatus = FT_Write(ftHandle, TxBufferSelf, 1, &BytesWritten);
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
    USBstatus = 3;
    BYTE TxBufferAdd[2]={0};
    DWORD BytesWritten;
    FT_STATUS ftStatus;
    if(ui->checkBoxPathOne->isChecked()){
        TxBufferAdd[0]=0x10;
        TxBufferAdd[1]=ui->textPathOne->text().toInt();
        cout<<i2s(TxBufferAdd[1])<<"\n";
        ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
        cout<<BytesWritten<<"\n";
        channel->append("11");
    }
    if(ui->checkBoxPathTwo->isChecked()){
        TxBufferAdd[0]=0x11;
        TxBufferAdd[1]=ui->textPathTwo->text().toInt();
        ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
        channel->append("21");
    }
    //timer.start(1);
    //connect(&timer,SIGNAL(timeout()),this,SLOT(writeOne()));
    //QMessageBox::information(this, "Message", "位宽数据已经写入硬件");
    thread.setChannel(channel);
    thread.setFtHandle(ftHandle);
    thread.transaction();
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
void MainWindow::usbresponsedata(const QString &s, DWORD bytesreceived){
    QString numberRec = "";
    ui->labelPath11->setText(s.mid(0,2));
    //cout<<i2s(RxBuffer[0])<<"\n";
    //qDebug()<<s.mid(0,2);
    ui->labelPath12->setText(s.mid(2,2));
    //qDebug()<<s.mid(2,2);
    //cout<<i2s(RxBuffer[1])<<"\n";
    count1 += 1;
    ui->labelCount1->setText(QString::number(count1,10));
    ui->labelPath13->setText(s.mid(4,2));
    //cout<<i2s(RxBuffer[2])<<"\n";
    //qDebug()<<s.mid(4,2);
    ui->labelPath14->setText(s.mid(6,2));
    //cout<<i2s(RxBuffer[3])<<"\n";
    //qDebug()<<s.mid(6,2);
    ui->totalCount1->setText(QString::number(bytesreceived,10));
    for(int i = 0; i < bytesreceived; i++)
    {
        numberRec.append(s.mid(2*i,2));
        numberRec.append(" ");
    }
    ui->textBrowserPathOne->append(numberRec);
}
void MainWindow::usbresponsedata2(const QString &s, DWORD bytesreceived){
    QString numberRec = "";
    ui->labelPath21->setText(s.mid(0,2));
    ui->labelPath22->setText(s.mid(2,2));
    if(bytesreceived != 0){
        count2 += 1;
    }
    ui->labelCount2->setText(QString::number(count2,10));
    ui->labelPath23->setText(s.mid(4,2));
    ui->labelPath24->setText(s.mid(6,2));
    ui->totalCount2->setText(QString::number(bytesreceived,10));
    for(int i = 0; i < bytesreceived; i++)
    {
        numberRec.append(s.mid(2*i,2));
        numberRec.append(" ");
    }
    ui->textBrowserPathTwo->append(numberRec);
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
                             ui->comboBoxBaud->currentIndex(),
                             timeout,
                             "01" + ui->textSelfWrite_2->text(),
                             writeread);
    //QMessageBox::information(this, "Message", "自检数据已经写入硬件");
}

void MainWindow::on_buttonSelfRead_2_clicked()
{
    int writeread = 11;
    int timeout = 1000;
    serialthread.transaction(ui->serialPortComboBox->currentText(),
                             ui->comboBoxBaud->currentIndex(),
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
                             ui->comboBoxBaud->currentIndex(),
                             timeout,
                             requestdata,
                             writeread);
}
void MainWindow::on_buttonUSBStart_clicked()
{
    writeserial();
}

void MainWindow::close_USB()
{
    FT_Close(ftHandle);
}
void MainWindow::writeserial()
{
    int writeread = 12;
    int timeout = 1000;
    flagOne = true;
    QString requestdata="";
    if(ui->checkBoxPathOne_2->isChecked()&&(ui->checkBoxPathTwo_2->checkState()==Qt::Unchecked)){
        requestdata = "20";
    }
    if(ui->checkBoxPathTwo_2->isChecked()&&(ui->checkBoxPathOne_2->isChecked()==false)){
        requestdata = "24";
    }
    if(ui->checkBoxPathOne_2->isChecked()&&ui->checkBoxPathTwo_2->isChecked()){
        requestdata = "2024";
    }
    if(ui->checkBoxPathOne_2->isChecked()){
        serialthread.transaction(ui->serialPortComboBox->currentText(),
                                 ui->comboBoxBaud->currentIndex(),
                                 timeout,
                                 requestdata,
                                 writeread);
    }
}

//void MainWindow::on_pushButton_clicked()
//{
//    //    int writeread = 12;
//    //    int timeout = 1000;
//    //    if(ui->checkBoxPathOne_2->isChecked()){
//    //        serialthread.transaction(ui->serialPortComboBox->currentText(),
//    //                                 timeout,
//    //                                 "20212223",
//    //                                 writeread);
//    //    }
//    //    if(ui->checkBoxPathTwo_2->isChecked()){
//    //        serialthread.transaction(ui->serialPortComboBox->currentText(),
//    //                                 timeout,
//    //                                 "24252627",
//    //                                 writeread);
//    //    }
//    QSerialPort newserial;
//    newserial.setPortName(ui->serialPortComboBox->currentText());
//    if (!newserial.open(QIODevice::ReadWrite)) {
//        qDebug()<<"wrong";
//    }
//    newserial.setBaudRate(QSerialPort::Baud115200);
//    QByteArray requestData1 = intToByte(int(rand()*25));
//    requestData1.resize(1);
//    newserial.write(requestData1);
//    if (newserial.waitForBytesWritten(1000)){
//        qDebug()<<"timeout";
//    }
//    else{
//        qDebug()<<"fsggs";
//    }
//    newserial.close();
//}

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
