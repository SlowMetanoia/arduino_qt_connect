//todo: data type matching and split.

#include "serialconnector.h"
#include "data_payload.h"
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
        QThread::sleep(1);
        qDebug()<<"error occured while openning serial port, trying again...";
    }
    //arduino->setDataTerminalReady(true);
    qDebug()<<"port opened";
    QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(gotNewData()));
    qDebug()<<"connector connected";
}

int SerialConnector::writeToChanel(char *data, int64_t size){
    //QByteArray dat(data);
    int result;
    if(size == -1)
        result = arduino->write(data);
    else
        result = arduino->write(data,size);
    qDebug()<<"Wrote to chanel"<<result<<"bytes:"<<data;
    return result;
}/*
SerialConnector::~SerialConnector(){
    arduino->close();
    delete arduino;
}*/
void SerialConnector::gotNewData(){
    char* line = new char[256];
    int length = arduino->readLine(line,256);
    piece_data* pd = (piece_data*)line;
    qDebug()<<"#########################################";
    qDebug()<<length<<"chars:"<<line;
    qDebug()<<"pd formated:"<<"piece_data{"<<pd->n<<pd->x<<pd->msg<<"}";
    qDebug()<<"#########################################";
    delete[] line;
}

