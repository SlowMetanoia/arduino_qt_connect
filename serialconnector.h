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
public slots:
    void gotNewData();
signals:

};

#endif // SERIALCONNECTOR_H
