#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->Click,SIGNAL(clicked()),this,SLOT(click_clicked()));
}

void MainWindow::setConnector(SerialConnector *connector)
{
    this->connector= connector;
    connect(this->ui->disconnect,SIGNAL(clicked()),connector,SLOT(disconnectForced()));
}

void MainWindow::printText(QString text){
    ui->textBrowser->append(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_clicked(){
    piece_data pd = piece_data{121,37.8,"Hollow world"};
    piece_data def_msg = piece_data{127,0.01,"default sage"};
    int r = this->connector->writeToChanel((char*)&def_msg, sizeof(piece_data));
    //QThread::sleep(1);
}

void MainWindow::disconnect_clicked(){

}

