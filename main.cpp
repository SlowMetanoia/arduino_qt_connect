#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include "serialconnector.h"
#include "data_payload.h"

void dieAfterNine(){
    QThread::sleep(9);

    exit(0);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"initializing connector...";
    qDebug()<<sizeof(int);
    qDebug()<<sizeof(float);
    qDebug()<<sizeof(char[20]);
    qDebug()<<sizeof(piece_data);

    SerialConnector connector("ttyUSB0",&a);


    piece_data pd = piece_data{121,37.8,"Hollow world"};


    QThread::sleep(1);
    connector.writeToChanel((char*)&pd, sizeof(piece_data));
    QThread::sleep(1);

    qDebug()<<"initializing application...";
    //(QThread::create)->start();
    return a.exec();
}
