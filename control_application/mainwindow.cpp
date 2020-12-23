#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <QDebug>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <stdio.h>
QSerialPort *mSerial;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bt_connect->setStyleSheet("background-color:red");
    ui->bt_connect->setText("Connect");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_refresh_clicked()
{
    ui->com_list->clear();
    const auto list_of_port = QSerialPortInfo::availablePorts();
        for (const QSerialPortInfo &port : list_of_port)
            ui->com_list->addItem(port.portName());
}

void MainWindow::on_bt_connect_clicked()
{
    if (ui->bt_connect->text() == "Connect"){
        ui->bt_connect->setText("Disconnect");
        ui->bt_connect->setStyleSheet("background-color:green");
        mSerial = new QSerialPort(this);
        mSerial->setPortName(ui->com_list->currentText());
        mSerial->setBaudRate(QSerialPort::Baud115200);
        mSerial->setDataBits(QSerialPort::Data8);
        mSerial->setParity(QSerialPort::NoParity);
        mSerial->setStopBits(QSerialPort::OneStop);
        mSerial->setFlowControl(QSerialPort::NoFlowControl);
        mSerial->open(QIODevice::ReadWrite);
        Received_Thread = new ReceiveThread(this);
        Received_Thread->set_serial_object(mSerial);
        connect(Received_Thread, SIGNAL(packet_received(QByteArray)), this, SLOT(received_callback(QByteArray)));
        Received_Thread->start();

    }else if(ui->bt_connect->text() == "Disconnect"){
        ui->bt_connect->setText("Connect");
        ui->bt_connect->setStyleSheet("background-color:red");
        Received_Thread->stop = true;
        mSerial->close();
        delete mSerial;
        delete Received_Thread;
    }
}

void MainWindow::received_callback(QByteArray data)
{
    qDebug() << data;
}

void MainWindow::on_bt_robot_stop_clicked()
{
    QByteArray command;
    command[0] = 0x28;
    command[1] = '0';
    command.append(" STOP");
    int temper_length = command.length();
    command[temper_length] = 0x29;
    mSerial->write(command, temper_length + 1);
}



void MainWindow::on_bt_scan_limit_clicked()
{
    QByteArray command;
    command[0] = 0x28;
    command[1] = '1';
    command.append(" SCAN");
    int temper_length = command.length();
    command[temper_length] = 0x29;
    mSerial->write(command, temper_length + 1);
}

void MainWindow::on_bt_home_clicked()
{
    QByteArray command;
    command[0] = 0x28;
    command[1] = '3';
    command.append(" HOME");
    command.append(ui->tb_v_factor->text());
    command.append(ui->tb_a_factor->text());
    int temper_length = command.length();
    command[temper_length] = 0x29;
    mSerial->write(command, temper_length + 1);
}

void MainWindow::on_bt_movL_clicked()
{
    QByteArray command;
    command[0] = 0x28;
    command[1] = '4';
    command.append("MOVL");
    command.append(ui->tb_x_cor->text());
    command.append(ui->tb_y_cor->text());


}
