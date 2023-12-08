#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include "serialconnector.h"
#include "data_payload.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"initializing connector...";
    qDebug()<<sizeof(int);
    qDebug()<<sizeof(float);
    qDebug()<<sizeof(char[20]);
    qDebug()<<sizeof(piece_data);

    SerialConnector connector("ttyUSB0",&a);


    QThread::sleep(1);
    connector.writeToChanel("110a423789");
    QThread::sleep(1);

    qDebug()<<"initializing application...";
    return a.exec();
}
