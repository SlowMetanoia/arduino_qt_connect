#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QThread>
#include <QElapsedTimer>

#include <data_payload.h>

class SerialConnector : public QObject
{
    Q_OBJECT
public:
    explicit SerialConnector(QString name, QObject *parent = nullptr);
    QSerialPort* arduino;
    int writeToChanel(char* data,int64_t size = -1);
    template <typename T>int writeToChanel(T data);
    void forceDisconnect();
    QElapsedTimer* timer;
public slots:
    void gotNewData();
    void disconnectForced();
signals:
    //todos: command
    void disconnect();
};

#endif // SERIALCONNECTOR_H
