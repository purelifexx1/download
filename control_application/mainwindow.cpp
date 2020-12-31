#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <QDebug>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QSerialPort *mSerial;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bt_connect->setStyleSheet("background-color:red");
    ui->bt_connect->setText("Connect");
    connect(_packet_handler, SIGNAL(on_display_event(Display_packet)), this, SLOT(display_event(Display_packet)));
    QString temp = "bt_inc_";
    for(int i = 1; i <= 6; i++){
        QPushButton *object_bt = this->findChild<QPushButton*>(temp + QString::number(i));
        connect(object_bt, SIGNAL(clicked()), this, SLOT(on_bt_keycommand()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_event(Display_packet data)
{
    switch (data.action_id) {
        case DISPLAY_POSITION:
            ui->tb_x_cur_cor->setText(QString::number(data.Scara_position.x));
            ui->tb_y_cur_cor->setText(QString::number(data.Scara_position.y));
            ui->tb_z_cur_cor->setText(QString::number(data.Scara_position.z));
            ui->tb_roll_cur_cor->setText(QString::number(data.Scara_position.roll));
            ui->tb_theta1_cur_val->setText(QString::number(data.Scara_position.theta1));
            ui->tb_theta2_cur_val->setText(QString::number(data.Scara_position.theta2));
            ui->tb_theta4_cur_val->setText(QString::number(data.Scara_position.theta4));
            ui->tb_d3_cur_val->setText(QString::number(data.Scara_position.D3));
        break;
        case DISPLAY_ERROR:
            ui->tb_console->append("RPD_ERROR | Command ID: " + system_parameter->COMMAND_STRING[data.Command_ID] + " | " + "Detail: " + system_parameter->DETAIL_STATUS[data.Respond_Type]);
        break;
    }
}

void MainWindow::QbyteArray_AddValue(QByteArray *object_array, QVariant convert_object, TypeDef_Conversion input_type)
{
    system_parameter->Convert_And_Append(object_array, convert_object, input_type);
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
    _packet_handler->categorize(data);
}

void MainWindow::on_bt_robot_stop_clicked()
{
//    QByteArray command;
//    command.append(0x28);
//    command.append(COMMAND_TRANSMISION);
//    command.append(CMD_STOPNOW);
//    command.append(0x29);
//    mSerial->write(command, command.length());
    int32_t testing = 1234;
    QByteArray tt;
    tt.append(reinterpret_cast<const char*>(&testing), 4);
    qDebug()<<tt;
}


void MainWindow::on_bt_scan_limit_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_SCAN_LIMIT);
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_home_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_MOVE_HOME);
    QbyteArray_AddValue(&command, ui->tb_v_factor->text(), DOUBLE_STRING_VALUE);
    QbyteArray_AddValue(&command, ui->tb_a_factor->text(), DOUBLE_STRING_VALUE);
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_movL_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_MOVE_LINE);
    QbyteArray_AddValue(&command, ui->tb_x_cor->text(), DOUBLE_STRING_VALUE);
    QbyteArray_AddValue(&command, ui->tb_y_cor->text(), DOUBLE_STRING_VALUE);
    QbyteArray_AddValue(&command, ui->tb_z_cor->text(), DOUBLE_STRING_VALUE);
    QbyteArray_AddValue(&command, ui->tb_roll_ang->text(), DOUBLE_STRING_VALUE);
    QbyteArray_AddValue(&command, ui->tb_v_factor->text(), DOUBLE_STRING_VALUE);
    if(ui->rb_qva->isChecked() == true) {
        command.append(DUTY_MODE_INIT_QVA);
        QbyteArray_AddValue(&command, ui->tb_a_factor->text(), DOUBLE_STRING_VALUE);
    }else if(ui->rb_qvt->isChecked() == true){
        command.append(DUTY_MODE_INIT_QVT);
        QbyteArray_AddValue(&command, ui->tb_time->text(), DOUBLE_STRING_VALUE);
    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_model_setting_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_SETTING);
    if(ui->rb_abs->isChecked() == true){
        command.append(DUTY_COORDINATES_ABS);
    }else if(ui->rb_inc->isChecked() == false){
        command.append(DUTY_COORDINATES_REL);
    }

    if(ui->rb_lspb->isChecked() == true){
        command.append(DUTY_TRAJECTORY_LSPB);
    }else if(ui->rb_scur->isChecked() == false){
        command.append(DUTY_TRAJECTORY_SCURVE);
    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_on_magnet_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_OUTPUT);
    command.append('\1');
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_off_magnet_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_OUTPUT);
    command.append('\0');
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_read_position_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_READ_POSITION);
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_keycommand()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_KEYBOARD);
    QPushButton *obj_sender = (QPushButton*)sender();
    uint8_t selection = (uint8_t)obj_sender->objectName().split('_')[2].toInt();
    command.append(selection);
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_key_setsp_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_KEY_SPEED);
    uint8_t key_speed = (uint8_t)ui->tb_key_setsp->text().toInt();
    key_speed = (key_speed > 7)?7:key_speed;
    key_speed = (key_speed < 1)?1:key_speed;
    command.append(key_speed);
    command.append(0x29);
    mSerial->write(command, command.length());
}
