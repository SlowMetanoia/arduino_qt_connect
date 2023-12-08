//todo: data type matching and split.

#include "serialconnector.h"

SerialConnector::SerialConnector(QString name, QObject *parent)
    : QObject{parent}{

    arduino = new QSerialPort();
    timer = new QElapsedTimer;

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
        qDebug()<<"error"<<arduino->error()<<"occured while openning serial port, trying again...";
    }
    //arduino->setDataTerminalReady(true);
    qDebug()<<"port opened";
    arduino->flush();
    QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(gotNewData()));
    QObject::connect(this,SIGNAL(disconnect()),this,SLOT(disconnectForced()));
    qDebug()<<"connector connected";
}

int SerialConnector::writeToChanel(char *data, int64_t size){
    timer->restart();
    int result;
    if(size == -1)
        result = arduino->write(data);
    else
        result = arduino->write(data,size);
    qDebug()<<"Wrote to chanel"<<result<<"bytes:"<<data;
    return result;
}

template<typename T>
int SerialConnector::writeToChanel(T data){
    timer->restart();
    int result;
    result = arduino->write(&data,sizeof(T));
    qDebug()<<"Wrote to chanel"<<result<<"bytes:"<<data;
    return result;
}

void SerialConnector::forceDisconnect(){
    emit disconnect();
}

void SerialConnector::gotNewData(){
    char* line = new char[256];
    int length = arduino->read(line,256);
    piece_data* pd = (piece_data*)line;
    qDebug()<<"#########################################";
    qDebug()<<length<<"chars:"<<line;
    qDebug()<<"pd formated:"<<"piece_data{"<<pd->n<<pd->x<<pd->msg<<"}";
    qDebug()<<"#########################################";
    delete[] line;
    qDebug()<<timer->elapsed()<<"ms since last write";
    //forceDisconnect();
    //QThread::msleep(100);
    //exit(0);
}

void SerialConnector::disconnectForced(){
    arduino->close();
    qDebug()<<"connect closed";
}
