#include "masterthread.h"
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QDebug>
#include <QString>
#include <string>
#include <QDataStream>
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
inline int bytesToInt(QByteArray bytes) {
    int addr = bytes[0] & 0x000000FF;
    addr |= ((bytes[1] << 8) & 0x0000FF00);
    addr |= ((bytes[2] << 16) & 0x00FF0000);
    addr |= ((bytes[3] << 24) & 0xFF000000);
    return addr;
}
inline QString s2q(const string &s) {
    return QString(QString::fromLocal8Bit(s.c_str()));
}
MasterThread::MasterThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false)
{
    working = false;
    hash[0] = QSerialPort::Baud115200;
    hash[1] = QSerialPort::Baud57600;
    hash[2] = QSerialPort::Baud38400;
    hash[3] = QSerialPort::Baud19200;
    hash[4] = QSerialPort::Baud9600;
}

MasterThread::~MasterThread()
{
    mutex.lock();
    isReading = 0;
    cond.wakeOne();
    mutex.unlock();
    wait();
}

void MasterThread::transaction(const QString &portName, int baudRate, int waitTimeout, const QString &request, int writeread)
{

    isReading = 1;
    quit = false;
    QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->baudRate = hash[baudRate];
    this->request = request;
    this->writeread = writeread;
    if (!isRunning())
        start();
    else {
        cond.wakeOne();
    }
}
void MasterThread::run()
{
    bool currentPortNameChanged = false;
    mutex.lock();
    QString currentPortName;
    if (currentPortName != portName) {
        currentPortName = portName;
        currentPortNameChanged = true;
    }
    int currentWaitTimeout = waitTimeout;
    QString currentRequest = request;

    QSerialPort serial;
    mutex.unlock();
    while(!quit){
        working = true;
        serial.setPortName(currentPortName);
        if(!serial.open(QIODevice::ReadWrite)){
            emit error(tr("Can't open %1, error code %2")
                       .arg(portName).arg(serial.error()));
            return;
        }
        serial.setBaudRate(baudRate,QSerialPort::AllDirections);
        serial.setDataBits(QSerialPort::Data8);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);

        if(writeread == 9){
            QByteArray requestData1;
            StringToHex(currentRequest.mid(0,2),requestData1);
            serial.write(requestData1);
            if (serial.waitForBytesWritten(waitTimeout)) {
            } else {
                emit timeout(tr("Wait write request timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
        }
        if(writeread == 10){
            QByteArray requestData = intToByte(currentRequest.mid(0,2).toInt());
            qDebug()<<currentRequest.length();
            if(currentRequest.length()==4){
                requestData.resize(2);
                requestData[1]=currentRequest.mid(2,2).toInt();
            }
            if(currentRequest.length()==8){
                requestData.resize(4);
                requestData[1]=currentRequest.mid(2,2).toInt();
                requestData[2]=currentRequest.mid(4,2).toInt();
                requestData[3]=currentRequest.mid(6,2).toInt();
            }
            qDebug()<<"data"+currentRequest;
            serial.write(requestData);
            if (serial.waitForBytesWritten(waitTimeout)) {
            }else{
                emit timeout(tr("Wait write request timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
        }
        if(writeread == 11){
            QByteArray requestData1 = intToByte(currentRequest.mid(0,2).toInt());
            requestData1.resize(1);
            serial.write(requestData1);
            if (serial.waitForBytesWritten(waitTimeout)) {
                // read response
                if(serial.waitForReadyRead(currentWaitTimeout)) {
                    QByteArray responseData = serial.readAll();
                    while (serial.waitForReadyRead(1000))
                        responseData += serial.readAll();
                    int a = bytesToInt(responseData);
                    QString responseint = s2q(i2s(a));
                    QString response(responseint);
                    emit this->response(response);
                }else {
                    emit timeout(tr("Wait read response timeout %1")
                                 .arg(QTime::currentTime().toString()));
                }
            } else {
                emit timeout(tr("Wait write request timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
        }
        while(writeread == 12 && isReading == 1){
            serial.setBaudRate(baudRate);
            if(currentRequest == "20"){
                QByteArray requestData2;
                requestData2.resize(1);
                requestData2[0] = 0x20;
                serial.write(requestData2);
                if (serial.waitForBytesWritten(waitTimeout)) {
                    // read response
                    if(serial.waitForReadyRead(currentWaitTimeout)) {
                        while(serial.bytesAvailable()<4);
                        QByteArray responseData = serial.readAll();
                        while (serial.waitForReadyRead(10))
                            responseData += serial.readAll();
                        QString responseint="";
                        for(int i = 0;i < 4;i++){
                            unsigned char iTemp = responseData.at(i);
                            QString str = QString::number(iTemp&0xff,16);
                            if(iTemp<10){
                                str.insert(0,"0");
                            }
                            responseint += str;
                        }
                        QString response(responseint);
                        emit this->responserial(response);
                    }else {
                        emit timeout(tr("Wait read response timeout %1")
                                     .arg(QTime::currentTime().toString()));
                    }
                } else {
                    emit timeout(tr("Wait write request timeout %1")
                                 .arg(QTime::currentTime().toString()));
                }

            }
            if(currentRequest == "24"){
                QByteArray requestData3;
                requestData3.resize(1);
                requestData3[0] = 0x24;
                serial.write(requestData3);
                if (serial.waitForBytesWritten(waitTimeout)) {
                    // read response
                    if(serial.waitForReadyRead(currentWaitTimeout)) {
                        while(serial.bytesAvailable()<4);
                        QByteArray responseData = serial.readAll();
                        while (serial.waitForReadyRead(10))
                            responseData += serial.readAll();
                        QString responseint="";
                        for(int i = 0;i < 4;i++){
                            unsigned char iTemp = responseData.at(i);
                            QString str = QString::number(iTemp&0xff,16);
                            if(iTemp<10){
                                str.insert(0,"0");
                            }
                            responseint += str;
                        }
                        QString response(responseint);
                        emit this->responserial2(response);
                    }else {
                        emit timeout(tr("Wait read response timeout %1")
                                     .arg(QTime::currentTime().toString()));
                    }
                } else {
                    emit timeout(tr("Wait write request timeout %1")
                                 .arg(QTime::currentTime().toString()));
                }

            }
            if(currentRequest == "2024"){
                QByteArray requestData2;
                requestData2.resize(1);
                requestData2[0] = 0x20;
                serial.write(requestData2);
                if (serial.waitForBytesWritten(waitTimeout)) {
                    // read response
                    if(serial.waitForReadyRead(currentWaitTimeout)) {
                        while(serial.bytesAvailable()<4);
                        QByteArray responseData = serial.readAll();
                        while (serial.waitForReadyRead(10))
                            responseData += serial.readAll();
                        QString responseint="";
                        for(int i = 0;i < 4;i++){
                            unsigned char iTemp = responseData.at(i);
                            QString str = QString::number(iTemp&0xff,16);
                            if(iTemp<10){
                                str.insert(0,"0");
                            }
                            responseint += str;
                        }
                        QString response(responseint);
                        emit this->responserial(response);
                    }else {
                        emit timeout(tr("Wait read response timeout %1")
                                     .arg(QTime::currentTime().toString()));
                    }
                } else {
                    emit timeout(tr("Wait write request timeout %1")
                                 .arg(QTime::currentTime().toString()));
                }
                if(baudRate == 19200 || baudRate == 9600){
                    msleep(5);
                }
                QByteArray requestData3;
                requestData3.resize(1);
                requestData3[0] = 0x24;
                serial.write(requestData3);
                if (serial.waitForBytesWritten(waitTimeout)) {
                    // read response
                    if(serial.waitForReadyRead(currentWaitTimeout)) {
                        while(serial.bytesAvailable()<4);
                        QByteArray responseData = serial.readAll();
                        while (serial.waitForReadyRead(10))
                            responseData += serial.readAll();
                        QString responseint="";
                        for(int i = 0;i < 4;i++){
                            unsigned char iTemp = responseData.at(i);
                            QString str = QString::number(iTemp&0xff,16);
                            if(iTemp<10){
                                str.insert(0,"0");
                            }
                            responseint += str;
                        }
                        QString response(responseint);
                        emit this->responserial2(response);
                    }else {
                        emit timeout(tr("Wait read response timeout %1")
                                     .arg(QTime::currentTime().toString()));
                    }
                } else {
                    emit timeout(tr("Wait write request timeout %1")
                                 .arg(QTime::currentTime().toString()));
                }

            }
            if(baudRate == 19200 || baudRate == 9600){
                msleep(5);
            }
        }
        mutex.lock();
        msleep(5);
        serial.close();
        if(writeread == 12 && isReading == 0){
            emit this->pathtwosend();
        }
        cond.wait(&mutex);
        if (currentPortName != portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = waitTimeout;
        currentRequest = request;
        mutex.unlock();
    }
}

void MasterThread::stop(){
    quit = true;
}

void MasterThread::StringToHex(QString str, QByteArray &senddata) //字符串转换为十六进制数据0-F
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;

    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}

char MasterThread::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return ch-ch;//不在0-f范围内的会发送成0
}
void MasterThread::setReading(int isReading) {
    this->isReading = isReading;
}

int MasterThread::getState(){
    return this->writeread;
}
