#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QDebug>
#include <QString>
#include <string>
#include <QDataStream>
#include <queue>
#include "task.h"
using namespace std;
Task::Task(const QString &portName, int waitTimeout, const QString &request, int writeread)
{
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->request = request;
    this->writeread = writeread;
}

Task::~Task()
{

}

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

void Task::run() {
    bool currentPortNameChanged = false;

    QString currentPortName;
    if (currentPortName != portName) {
        currentPortName = portName;
        currentPortNameChanged = true;
    }
    int currentWaitTimeout = waitTimeout;
    QString currentRequest = request;
    QSerialPort serial;

        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);
            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }
        }
        // write request
        if(writeread == 10){
            serial.setBaudRate(QSerialPort::Baud115200);
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
            //mutex.lock();
            //cond.wait(&mutex);
        }
        if(writeread == 11){
            serial.setBaudRate(QSerialPort::Baud115200);
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
            //mutex.lock();
            //cond.wait(&mutex);
        }
        if(writeread == 12){
            serial.setBaudRate(QSerialPort::Baud115200);
            if(currentRequest == "20212223"){
                QByteArray requestData2;
                requestData2.resize(4);
                requestData2[0] = 0x20;
                requestData2[1] = 0x21;
                requestData2[2] = 0x22;
                requestData2[3] = 0x23;
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
            if(currentRequest == "24252627"){
                QByteArray requestData3;
                requestData3.resize(4);
                requestData3[0] = 0x24;
                requestData3[1] = 0x25;
                requestData3[2] = 0x26;
                requestData3[3] = 0x27;
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
        }
        if (currentPortName != portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = waitTimeout;
        currentRequest = request;

}

