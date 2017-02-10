#include "writethread.h"
#include <iostream>
#include <QDebug>
#include <QString>
#include <QDateTime>
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
writethread::writethread()
{
    stopped = false;
    file = new QFile("D://File/newSSI.txt");
        if (!file->open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
        {
            std::cerr << "Cannot open file for writing: "
                      << qPrintable(file->errorString()) << std::endl;
            return;
        }
    out = new QTextStream(file);
    isReading = 1;
}

writethread::~writethread()
{
    if (out != NULL){
        delete out;
        out = NULL;
    }
    file->close();
    delete file;
    file = NULL;
    mutex.lock();
    usbcond.wakeOne();
    mutex.unlock();
    wait();

}
void writethread::transaction(){
    isReading = 1;
    QMutexLocker locker(&mutex);
    if (!isRunning())
        start();
    else {
        usbcond.wakeOne();
    }
}

void writethread::run(){
    QString timepast;
    QDateTime currenttime;
    while(!stopped){
        while(isReading == 1){
//        currenttime = QDateTime::currentDateTime();
//        timepast.append(currenttime.toString());
        DWORD RxBytes = 4;
        DWORD TxBytes = 0;
        UCHAR RxBuffer[16]={0};
        UCHAR TxBuffer[1]={0};
        DWORD BytesWritten;
        DWORD BytesReceived;
        DWORD EventDWord;
        QString s;
        FT_STATUS ftStatus;
        if((*channel).contains("11")){
            TxBuffer[0]=0x20;
            currenttime = QDateTime::currentDateTime();
            timepast.append("Path one wr: ");
            timepast.append(currenttime.toString("hh:mm:ss.zzz"));
            timepast.append("    ");
            ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            while(RxBytes < 4){
                ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            }
            if((RxBytes >= 0)&&(ftStatus == FT_OK))
            {
                ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
                timepast.append("Before Path Two: ");
                currenttime = QDateTime::currentDateTime();
                timepast.append(currenttime.toString("hh:mm:ss.zzz"));
                timepast.append("    ");
                for(int i =0;i<4;i++){
                    s.append(tohex(RxBuffer[i]));
                }
                emit this->usbresponse(s, BytesReceived);

            }
        }
        s = "";
        if((*channel).contains("21")){
            TxBuffer[0]=0x24;
            timepast.append("Path Two wr: ");
            currenttime = QDateTime::currentDateTime();
            timepast.append(currenttime.toString("hh:mm:ss.zzz"));
            timepast.append("    ");
            ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
            ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            while(RxBytes < 4){
                ftStatus = FT_GetStatus(ftHandle, &RxBytes, &TxBytes, &EventDWord);
            }
            if ((RxBytes >= 0)&&(ftStatus == FT_OK))
            {
                ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
                timepast.append("Before Path One: ");
                currenttime = QDateTime::currentDateTime();
                timepast.append(currenttime.toString("hh:mm:ss.zzz"));
                timepast.append("    ");
                for(int i =0;i<4;i++){
                    s.append(tohex(RxBuffer[i]));
                }
                emit this->usbresponse2(s, BytesReceived);
            }
        }
    }
    mutex.lock();
    (*out)<<timepast<< '\n';
    out->flush();
    emit this->close_USBsignal();
    usbcond.wait(&mutex);
    mutex.unlock();
    }
}
void writethread::stop(){
    stopped = true;
}
void writethread::setUi(Ui::MainWindow *ui){
    this->ui = ui;
}
void writethread::setFtHandle(FT_HANDLE handle){
    ftHandle = handle;
}
void writethread::setReading(int isReading) {
    this->isReading = isReading;
}
void writethread::setChannel(QString *channel){
    this->channel = channel;
}

QString writethread::tohex(UCHAR number){
    QString str = QString::number(number&0xff,16);
    if(number<10){
        str.insert(0,"0");
    }
    return str;
}
