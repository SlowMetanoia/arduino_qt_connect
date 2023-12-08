#include "mainwindow.h"

#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>

#include "serialconnector.h"
#include "data_payload.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug()<<"initializing connector...";

    //serial connector instance
    //tring to connect to serial port by name until succsessful
    SerialConnector connector("ttyUSB0",&a);

    w.setConnector(&connector);

    //connector.arduino->waitForReadyRead();
    //QThread::msleep(600);

    qDebug()<<"initializing application...";

    w.show();
    return a.exec();
}
