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

void MainWindow::addspace(QByteArray *obj)
{
    obj->append(" ");
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
    command.append(0x28);
    command.append('0');
    addspace(&command);
    command.append("STOP");
    command.append(0x29);
    mSerial->write(command, command.length());
}



void MainWindow::on_bt_scan_limit_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append('1');
    addspace(&command);
    command.append("SCAN");
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_home_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append('2');
    addspace(&command);
    command.append("HOME");
    addspace(&command);
    command.append(ui->tb_v_factor->text());
    addspace(&command);
    command.append(ui->tb_a_factor->text());
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_movL_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append('3');
    addspace(&command);
    command.append("MOVL");
    addspace(&command);
    command.append(ui->tb_x_cor->text());
    addspace(&command);
    command.append(ui->tb_y_cor->text());
    addspace(&command);
    command.append(ui->tb_z_cor->text());
    addspace(&command);
    command.append(ui->tb_roll_ang->text());
    addspace(&command);
    command.append(ui->tb_v_factor->text());
    addspace(&command);
    if(ui->rb_qva->isChecked() == true) {
        command.append('0');
        addspace(&command);
        command.append(ui->tb_a_factor->text());
    }else if(ui->rb_qvt->isChecked() == true){
        command.append('1');
        addspace(&command);
        command.append(ui->tb_time->text());
    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_model_setting_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append("10");
    addspace(&command);
    command.append("SETT");
    addspace(&command);
    if(ui->rb_abs->isChecked() == true){
        command.append('0');
    }else if(ui->rb_inc->isChecked() == false){
        command.append('1');
    }
    addspace(&command);
    if(ui->rb_lspb->isChecked() == true){
        command.append('0');
    }else if(ui->rb_scur->isChecked() == false){
        command.append('1');
    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_on_magnet_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append('7');
    addspace(&command);
    command.append("OUTP");
    addspace(&command);
    command.append("1");
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_off_magnet_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append('7');
    addspace(&command);
    command.append("OUTP");
    addspace(&command);
    command.append("0");
    command.append(0x29);
    mSerial->write(command, command.length());
}
