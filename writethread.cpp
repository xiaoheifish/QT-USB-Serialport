#include "writethread.h"
#include <iostream>
using namespace std;
writethread::writethread()
{
    stopped = false;
}

writethread::~writethread()
{

}
void writethread::run(){
    if(stopped == false){
        UCHAR Mode = 0x40;//Set single chanel synchronous FT245 mode
        UCHAR Mask = 0xff;//written to device
        BYTE TxBufferAdd[2]={0};
        DWORD BytesWritten;
        FT_STATUS ftStatus = FT_Open(0, &ftHandle);
        if(ftStatus != FT_OK)
        {//FT_Open failed
            return;
        }
        ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
        Sleep(5);
        TxBufferAdd[0]=0x01;
        TxBufferAdd[1]=(ui->textSelfWrite->text()).toInt();
        ftStatus = FT_Write(ftHandle, TxBufferAdd, 2, &BytesWritten);
        BYTE TxBufferSelf[1]={0};
        BYTE RxBuffer[1]={0};
        DWORD BytesReceived;
        TxBufferSelf[0]=0x08;
        Sleep(5);
        ftStatus = FT_Write(ftHandle, TxBufferSelf, 1, &BytesWritten);
        cout<<"WRITE:"<<ftStatus<<"\n";
        Sleep(1);
        ftStatus = FT_Read(ftHandle,RxBuffer,1,&BytesReceived);
        cout<<"READ:"<<ftStatus<<"\n";
        ui->textSelfRead->setText(QString::number(RxBuffer[0],10));
        FT_Close(ftHandle);
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

