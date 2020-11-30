#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QString>
#include <iostream>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_connect->setAutoFillBackground(true);
    pal_green.setColor(QPalette::Button,QColor(Qt::green));
    pal_red.setColor(QPalette::Button,QColor(Qt::red));

    connect(&yrc100micro_com, SIGNAL(dataUIRecieveSiUIgnal()), this, SLOT(updateUICallback()));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerCallback()));

    //map twelve buttons to one slot
    connect(ui->t1_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t2_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t3_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t4_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t5_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t6_inc, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t1_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t2_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t3_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t4_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t5_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
    connect(ui->t6_dec, SIGNAL(clicked()), this, SLOT(inc_dec_bt_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked()
{
    if(ui->btn_connect->text() == "Connect"){
//      UDP connect
        QHostAddress udp_address;
        quint16 udp_port;
        quint16 udp_file_port;
        QString ip_string = ui->txt_ip->text();
        QStringList ip_list = ip_string.split(".");
        quint32 ip_int32 = (ip_list.at(0).toUInt() << 24) | (ip_list.at(1).toUInt() << 16)
                            | (ip_list.at(2).toUInt() << 8) | ip_list.at(3).toUInt();
        udp_address.setAddress(ip_int32);
        udp_port = ui->txt_port->text().toUShort();
        udp_file_port = ui->txt_filePort->text().toUShort();

        yrc100micro_com.YRC1000microSetConnection(udp_address,udp_port,udp_file_port);
        bool connection_satus = yrc100micro_com.YRC1000microConnect();
//        if(connection_satus == false){
//            QMessageBox::warning(this,"UDP Connection","Can not connect to udp address");
//            return;
//        }
        ui->btn_connect->setText("Disconnect");
        ui->btn_connect->setPalette(pal_green);

//        timer->start(100);
    }
    else if(ui->btn_connect->text() == "Disconnect"){
        ui->btn_connect->setText("Connect");
        ui->btn_connect->setPalette(pal_red);
        yrc100micro_com.YRC1000microDisConnect();
    }
}

void MainWindow::on_btn_servo_clicked()
{
    if(ui->btn_servo->text() == "Servo On"){
        yrc100micro_com.YRC1000microOnServo();
        ui->btn_servo->setText("Servo Off");
    }
    else if(ui->btn_servo->text() == "Servo Off"){
        yrc100micro_com.YRC1000microOffServo();
        ui->btn_servo->setText("Servo On");
    }
}

void MainWindow::on_pushButton_clicked()
{
    yrc100micro_com.YRC1000microReadPosition();
}

void MainWindow::on_pushButton_2_clicked()
{
    double set_speed = ui->txt_setSpeed->text().toDouble();
    QVector<double> set_position;
//    qDebug() << "Set position: " << set_position;
    if(ui->rbtn_xyz->isChecked()){
        set_position.append(ui->txt_setX->text().toDouble());
        set_position.append(ui->txt_setY->text().toDouble());
        set_position.append(ui->txt_setZ->text().toDouble());
        set_position.append(172);
        set_position.append(0);
        set_position.append(-135);
        if(ui->rbtn_linkAbs->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_LINK_ABSOLUTE,CMD_DATA_MOVE_SPEED_TYPE_V_SPEED,set_speed,&set_position);
        else if(ui->rbtn_lineAbs->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_STRAIGHT_ABSOLUTE,CMD_DATA_MOVE_SPEED_TYPE_V_SPEED,set_speed,&set_position);
        else if(ui->rbtn_LineInc->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,CMD_DATA_MOVE_SPEED_TYPE_V_SPEED,set_speed,&set_position);
    }
    else if(ui->rbtn_rpy->isChecked()){
        set_position.append(0);
        set_position.append(0);
        set_position.append(0);
        set_position.append(ui->txt_setRoll->text().toDouble());
        set_position.append(ui->txt_setPitch->text().toDouble());
        set_position.append(ui->txt_setYaw->text().toDouble());

        if(ui->rbtn_linkAbs->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_LINK_ABSOLUTE,CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED,set_speed,&set_position);
        else if(ui->rbtn_lineAbs->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_STRAIGHT_ABSOLUTE,CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED,set_speed,&set_position);
        else if(ui->rbtn_LineInc->isChecked())
            yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
                CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED,set_speed,&set_position);
    }
}

void MainWindow::updateUICallback(){
    QVector<double> position = yrc100micro_com.updateRobotPosition();
    ui->txt_getX->setText(QString::number(position[0]));
    ui->txt_getY->setText(QString::number(position[1]));
    ui->txt_getZ->setText(QString::number(position[2]));
    ui->txt_getRoll->setText(QString::number(position[3]));
    ui->txt_getPitch->setText(QString::number(position[4]));
    ui->txt_getYaw->setText(QString::number(position[5]));

    quint16 status_code = yrc100micro_com.updateRobotStatus();
    status_code &= RES_VALUE_READING_RUNNING_MASK;
    if(status_code){
        ui->lb_run_status->setText("Running");
    }
    else
        ui->lb_run_status->setText("Stop");

}

void MainWindow::timerCallback()
{
    yrc100micro_com.YRC1000microReadStatus();
}

void MainWindow::on_btn_saveJob_clicked()
{
//  qDebug() << "ui data: " << ui->txt_saveJob->text();
    yrc100micro_com.YRC1000microSaveJob(0,ui->txt_saveJob->text());
}

void MainWindow::on_btn_loadJob_clicked()
{
    yrc100micro_com.YRC1000microLoadJob(ui->txt_loadJob->text());
    qDebug() << "File name " << ui->txt_loadJob->text() << endl;
}

void MainWindow::inc_dec_bt_clicked()
{
    QPushButton *current_bt = (QPushButton*)sender();

    double set_speed;
    bool mode_selection = ui->radiobt_linear->isChecked();
    double distance_mm = (double)ui->slider_dis_mm->value();
    double distance_deg = (double)ui->slider_dis_deg->value();
    set_speed = (mode_selection==true)?(double)ui->slider_sp_mps->value():(double)ui->slider_sp_degps->value();
    quint8 selected_sp_type = (mode_selection==true)?CMD_DATA_MOVE_SPEED_TYPE_V_SPEED:CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED;

    QVector<double> set_position(6, 0);
    if (current_bt->objectName() == "t1_inc" && mode_selection == true){
        set_position[0] = distance_mm;
    }else if(current_bt->objectName() == "t2_inc" && mode_selection == true){
        set_position[1] = distance_mm;
    }else if(current_bt->objectName() == "t3_inc" && mode_selection == true){
        set_position[2] = distance_mm;
    }else if(current_bt->objectName() == "t4_inc" && mode_selection == false){
        set_position[3] = distance_deg;
    }else if(current_bt->objectName() == "t5_inc" && mode_selection == false){
        set_position[4] = distance_deg;
    }else if(current_bt->objectName() == "t6_inc" && mode_selection == false){
        set_position[5] = distance_deg;
    }else if(current_bt->objectName() == "t1_dec" && mode_selection == true){
        set_position[0] = -distance_mm;
    }else if(current_bt->objectName() == "t2_dec" && mode_selection == true){
        set_position[1] = -distance_mm;
    }else if(current_bt->objectName() == "t3_dec" && mode_selection == true){
        set_position[2] = -distance_mm;
    }else if(current_bt->objectName() == "t4_dec" && mode_selection == false){
        set_position[3] = -distance_deg;
    }else if(current_bt->objectName() == "t5_dec" && mode_selection == false){
        set_position[4] = -distance_deg;
    }else if(current_bt->objectName() == "t6_dec" && mode_selection == false){
        set_position[5] = -distance_deg;
    }

    yrc100micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT,
        CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT, selected_sp_type, set_speed, &set_position);

}


