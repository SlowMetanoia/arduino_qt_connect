#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "serialconnector.h"
#include "data_payload.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    SerialConnector* connector;
    void setConnector(SerialConnector* connector);
    void printText(QString text);
    ~MainWindow();
public slots:
    void click_clicked();
    void disconnect_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
