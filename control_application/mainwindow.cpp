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
    connect(ui->bt_start_test, SIGNAL(clicked()), this, SLOT(on_bt_testmt()));
    connect(ui->bt_stop_test, SIGNAL(clicked()), this, SLOT(on_bt_testmt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_event(Display_packet data)
{
    switch (data.action_id) {
        case DISPLAY_POSITION:
            ui->tb_x_cur_cor->setText(QString::number(data.RealData.x));
            ui->tb_y_cur_cor->setText(QString::number(data.RealData.y));
            ui->tb_z_cur_cor->setText(QString::number(data.RealData.z));
            ui->tb_roll_cur_cor->setText(QString::number(data.RealData.roll*180.0f/3.141592f));
            ui->tb_theta1_cur_val->setText(QString::number(data.RealData.theta1));
            ui->tb_theta2_cur_val->setText(QString::number(data.RealData.theta2));
            ui->tb_theta4_cur_val->setText(QString::number(data.RealData.theta4));
            ui->tb_d3_cur_val->setText(QString::number(data.RealData.D3));
            ui->tb_console->append("Position data received");
            ui->tb_console->append("--------------------------");
        break;
        case DISPLAY_RPD_DETAIL:
            if(_packet_handler->number_of_packet != 0){
                _packet_handler->number_of_packet--;
            }
            QString detail_string;
            for(int t = 0; t < data.Reference_String.length(); t++){
                detail_string += system_parameter->DETAIL_STATUS[data.Reference_String.at(t)] + "; ";
            }
            ui->tb_console->append(system_parameter->RDP_String[data.Respond_Type]
                    + " | Command ID: " + system_parameter->COMMAND_STRING[data.Command_ID]
                    + " | Detail: " + detail_string);
            if(_packet_handler->number_of_packet == 0){
                ui->tb_console->append("--------------------------");
            }
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
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_STOPNOW);
    command.append(0x29);
    mSerial->write(command, command.length());
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
    QbyteArray_AddValue(&command, ui->tb_v_factor->text(), SCARA_COR_VALUE);
    QbyteArray_AddValue(&command, ui->tb_a_factor->text(), SCARA_COR_VALUE);
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_movL_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_MOVE_LINE);
    QbyteArray_AddValue(&command, ui->tb_x_cor->text(), SCARA_COR_VALUE);
    QbyteArray_AddValue(&command, ui->tb_y_cor->text(), SCARA_COR_VALUE);
    QbyteArray_AddValue(&command, ui->tb_z_cor->text(), SCARA_COR_VALUE);
    QbyteArray_AddValue(&command, ui->tb_roll_ang->text(), SCARA_COR_VALUE);
    QbyteArray_AddValue(&command, ui->tb_v_factor->text(), SCARA_COR_VALUE);
    if(ui->rb_qva->isChecked() == true) {
        command.append(DUTY_MODE_INIT_QVA);
        QbyteArray_AddValue(&command, ui->tb_a_factor->text(), SCARA_COR_VALUE);
    }else if(ui->rb_qvt->isChecked() == true){
        command.append(DUTY_MODE_INIT_QVT);
        QbyteArray_AddValue(&command, ui->tb_time->text(), SCARA_COR_VALUE);
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
    uint8_t selection = (uint8_t)obj_sender->objectName().split('_')[2].toInt() - 1;
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

void MainWindow::on_bt_set_method_clicked()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_METHOD_CHANGE);
    if(ui->rb_manual->isChecked() == true){
        command.append(SCARA_METHOD_MANUAL);
    }else if(ui->rb_semi_auto->isChecked() == true){
        command.append(SCARA_METHOD_SEMI_AUTO);
    }else if(ui->rb_auto->isChecked() == true){
        command.append(SCARA_METHOD_AUTO);
    }else{
        ui->tb_console->append("Please select method");
        ui->tb_console->append("--------------------------");
        return;
    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_bt_clear_console_clicked()
{
    ui->tb_console->clear();
}

void MainWindow::on_bt_testmt()
{
    QByteArray command;
    command.append(0x28);
    command.append(COMMAND_TRANSMISION);
    command.append(CMD_MOTOR_TEST);
    uint8_t sign = (ui->hs_testmt_sign->value() == 1)?1:0;
    uint8_t pos = (ui->rb_test_mt1->isChecked()==true)?0:
                  (ui->rb_test_mt2->isChecked()==true)?1:
                  (ui->rb_test_mt3->isChecked()==true)?2:
                  (ui->rb_test_mt4->isChecked()==true)?3:0;
    SCARA_TestMode test_mode = SCARA_TestMode(pos*2 + sign);
    command.append(test_mode);
    QPushButton *obj_sender = (QPushButton*)sender();
    if(obj_sender->objectName() == "bt_start_test"){

    }else if(obj_sender->objectName() == "bt_stop_test"){

    }
    command.append(0x29);
    mSerial->write(command, command.length());
}

void MainWindow::on_testing_clicked()
{
    double current_theta2;
    double d1, d4, a4, a1, a2;
    double x, y, z, roll;
    double s1, c1, s2, s2_positive, s2_negative, c2 , temp;
    double theta1, theta2, theta2_positive, theta2_negative, d3, theta4 , pWx, pWy;
    x = 120.0f; y = -20.23f; z = 5.23; roll = 2.23;
    current_theta2 = 2.473f;
    d1	=			211.0f   ;
    a1	=			197.0f   ;
    a2	=			160.0f   ;
    d4	=			77.674f  ;
    a4	=			32.36f   ;
    d3  = d1 - d4 - z;
    pWx = x - a4*cos(roll);
    pWy = y - a4*sin(roll);
    c2  = (pWx*pWx + pWy*pWy - a1*a1 - a2*a2) / (2*a1*a2);
    temp = 1 - c2*c2;
//    if ( temp < 0 ) {
//        return false;
//    }
    s2_positive  = sqrt(temp); // Note that there are 2 solution: elbow up & elbow down
    s2_negative	 = -s2_positive;

    theta2_positive = atan2(s2_positive,c2);
    theta2_negative = atan2(s2_negative,c2);
    // Choose relevant situation : nearest
    if ( fabs( theta2_positive - current_theta2) <= fabs( theta2_negative - current_theta2)) {
        s2 		= s2_positive;
        theta2 	= theta2_positive;
    } else {
        s2 		= s2_negative;
        theta2 	= theta2_negative;
    }

    s1 = ((a1 + a2*c2)*pWy - a2*s2*pWx) / (pWx*pWx + pWy*pWy);
    c1 = ((a1 + a2*c2)*pWx + a2*s2*pWy) / (pWx*pWx + pWy*pWy);
    theta1 = atan2(s1,c1);
    theta4 = theta1 + theta2 - roll;
    qDebug() << "end";
}

