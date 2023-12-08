#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include "serialconnector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SerialConnector connector("ttyUSB0");

    QSerialPort* arduino = connector.arduino;

    char* x = "110a";

    QByteArray data((char*)x);
    QThread::sleep(1);
    arduino->write(data);
    QThread::sleep(1);
    qDebug()<<"data wrote:"<<data;

    return a.exec();
}
