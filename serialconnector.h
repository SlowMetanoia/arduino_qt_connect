#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QThread>

class SerialConnector : public QObject
{
    Q_OBJECT
public:
    explicit SerialConnector(QString name, QObject *parent = nullptr);
    QSerialPort* arduino;
    int writeToChanel(char* data,int64_t size = -1);
public slots:
    void gotNewData();
signals:
    //todos: command
};

#endif // SERIALCONNECTOR_H
