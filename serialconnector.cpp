#include "serialconnector.h"

SerialConnector::SerialConnector(QString name, QObject *parent)
    : QObject{parent}{
    arduino = new QSerialPort();


    //arduino init
    arduino->setPortName(name);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    //connection opening
    while(!arduino->open(QSerialPort::ReadWrite)){
        qDebug()<<"error occured while openning serial port";
        QThread::sleep(1);
    }
    //arduino->setDataTerminalReady(true);
    qDebug()<<"port opened";
    QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(gotNewData()));
    qDebug()<<"connector connected";
}
void SerialConnector::gotNewData(){
    char* line = new char[256];
    int length = arduino->readLine(line,256);

    qDebug()<<line;
}
