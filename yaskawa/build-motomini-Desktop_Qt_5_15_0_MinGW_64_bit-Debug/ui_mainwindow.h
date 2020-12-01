/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *txt_ip;
    QLineEdit *txt_port;
    QLineEdit *txt_filePort;
    QPushButton *btn_connect;
    QPushButton *btn_servo;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *txt_getX;
    QLineEdit *txt_getY;
    QLineEdit *txt_getZ;
    QLineEdit *txt_getRoll;
    QLineEdit *txt_getPitch;
    QLineEdit *txt_getYaw;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_29;
    QLabel *label_28;
    QLabel *label_32;
    QLabel *label_27;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_26;
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *rbtn_linkAbs;
    QRadioButton *rbtn_lineAbs;
    QRadioButton *rbtn_LineInc;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *txt_setX;
    QLineEdit *txt_setY;
    QLineEdit *txt_setZ;
    QLineEdit *txt_setRoll;
    QLineEdit *txt_setPitch;
    QLineEdit *txt_setYaw;
    QLineEdit *txt_setSpeed;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbtn_xyz;
    QRadioButton *rbtn_rpy;
    QPushButton *pushButton_2;
    QLabel *lb_run_status;
    QLabel *label_33;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_12;
    QPushButton *btn_saveJob;
    QPushButton *btn_loadJob;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *txt_saveJob;
    QLineEdit *txt_loadJob;
    QGroupBox *groupBox;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QPushButton *t1_inc;
    QPushButton *t1_dec;
    QPushButton *t2_inc;
    QPushButton *t2_dec;
    QPushButton *t3_inc;
    QPushButton *t3_dec;
    QPushButton *t4_inc;
    QPushButton *t4_dec;
    QPushButton *t5_inc;
    QPushButton *t5_dec;
    QPushButton *t6_inc;
    QPushButton *t6_dec;
    QRadioButton *radiobt_rotation;
    QRadioButton *radiobt_linear;
    QSlider *slider_dis_mm;
    QLabel *label_40;
    QLabel *label_41;
    QSlider *slider_dis_deg;
    QLabel *label_42;
    QSlider *slider_sp_degps;
    QSlider *slider_sp_mps;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_dis_mm_val;
    QLabel *label_dis_deg_val;
    QLabel *label_sp_mps_val;
    QLabel *label_sp_degps_val;
    QGroupBox *groupBox_2;
    QLineEdit *theta6;
    QLineEdit *theta1;
    QLineEdit *theta4;
    QLineEdit *theta3;
    QLineEdit *theta2;
    QLineEdit *theta5;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QPushButton *fk_calculate;
    QLabel *fk_rz;
    QLabel *fk_y;
    QLabel *fk_rx;
    QLabel *fk_ry;
    QLabel *fk_x;
    QLabel *fk_z;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_61;
    QLabel *label_62;
    QLabel *label_63;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 587);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 0, 226, 124));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txt_ip = new QLineEdit(layoutWidget);
        txt_ip->setObjectName(QString::fromUtf8("txt_ip"));

        verticalLayout->addWidget(txt_ip);

        txt_port = new QLineEdit(layoutWidget);
        txt_port->setObjectName(QString::fromUtf8("txt_port"));

        verticalLayout->addWidget(txt_port);

        txt_filePort = new QLineEdit(layoutWidget);
        txt_filePort->setObjectName(QString::fromUtf8("txt_filePort"));

        verticalLayout->addWidget(txt_filePort);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        btn_connect = new QPushButton(layoutWidget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setAutoFillBackground(true);

        verticalLayout_3->addWidget(btn_connect);

        btn_servo = new QPushButton(centralWidget);
        btn_servo->setObjectName(QString::fromUtf8("btn_servo"));
        btn_servo->setGeometry(QRect(30, 130, 101, 25));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 0, 238, 240));
        verticalLayout_9 = new QVBoxLayout(layoutWidget1);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_9->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        txt_getX = new QLineEdit(layoutWidget1);
        txt_getX->setObjectName(QString::fromUtf8("txt_getX"));

        verticalLayout_5->addWidget(txt_getX);

        txt_getY = new QLineEdit(layoutWidget1);
        txt_getY->setObjectName(QString::fromUtf8("txt_getY"));

        verticalLayout_5->addWidget(txt_getY);

        txt_getZ = new QLineEdit(layoutWidget1);
        txt_getZ->setObjectName(QString::fromUtf8("txt_getZ"));

        verticalLayout_5->addWidget(txt_getZ);

        txt_getRoll = new QLineEdit(layoutWidget1);
        txt_getRoll->setObjectName(QString::fromUtf8("txt_getRoll"));

        verticalLayout_5->addWidget(txt_getRoll);

        txt_getPitch = new QLineEdit(layoutWidget1);
        txt_getPitch->setObjectName(QString::fromUtf8("txt_getPitch"));

        verticalLayout_5->addWidget(txt_getPitch);

        txt_getYaw = new QLineEdit(layoutWidget1);
        txt_getYaw->setObjectName(QString::fromUtf8("txt_getYaw"));

        verticalLayout_5->addWidget(txt_getYaw);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_29 = new QLabel(layoutWidget1);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        verticalLayout_6->addWidget(label_29);

        label_28 = new QLabel(layoutWidget1);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_6->addWidget(label_28);

        label_32 = new QLabel(layoutWidget1);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        verticalLayout_6->addWidget(label_32);

        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_6->addWidget(label_27);

        label_30 = new QLabel(layoutWidget1);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        verticalLayout_6->addWidget(label_30);

        label_31 = new QLabel(layoutWidget1);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        verticalLayout_6->addWidget(label_31);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_6->addWidget(label_26);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_9->addWidget(pushButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(570, 270, 256, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        rbtn_linkAbs = new QRadioButton(layoutWidget2);
        rbtn_linkAbs->setObjectName(QString::fromUtf8("rbtn_linkAbs"));

        horizontalLayout_5->addWidget(rbtn_linkAbs);

        rbtn_lineAbs = new QRadioButton(layoutWidget2);
        rbtn_lineAbs->setObjectName(QString::fromUtf8("rbtn_lineAbs"));

        horizontalLayout_5->addWidget(rbtn_lineAbs);

        rbtn_LineInc = new QRadioButton(layoutWidget2);
        rbtn_LineInc->setObjectName(QString::fromUtf8("rbtn_LineInc"));
        rbtn_LineInc->setChecked(true);

        horizontalLayout_5->addWidget(rbtn_LineInc);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(551, -7, 295, 273));
        verticalLayout_11 = new QVBoxLayout(layoutWidget3);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_11->addWidget(label_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_8->addWidget(label_12);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_8->addWidget(label_13);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_8->addWidget(label_14);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_8->addWidget(label_15);

        label_16 = new QLabel(layoutWidget3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_8->addWidget(label_16);

        label_17 = new QLabel(layoutWidget3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_8->addWidget(label_17);

        label_18 = new QLabel(layoutWidget3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_8->addWidget(label_18);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        txt_setX = new QLineEdit(layoutWidget3);
        txt_setX->setObjectName(QString::fromUtf8("txt_setX"));

        verticalLayout_7->addWidget(txt_setX);

        txt_setY = new QLineEdit(layoutWidget3);
        txt_setY->setObjectName(QString::fromUtf8("txt_setY"));

        verticalLayout_7->addWidget(txt_setY);

        txt_setZ = new QLineEdit(layoutWidget3);
        txt_setZ->setObjectName(QString::fromUtf8("txt_setZ"));

        verticalLayout_7->addWidget(txt_setZ);

        txt_setRoll = new QLineEdit(layoutWidget3);
        txt_setRoll->setObjectName(QString::fromUtf8("txt_setRoll"));

        verticalLayout_7->addWidget(txt_setRoll);

        txt_setPitch = new QLineEdit(layoutWidget3);
        txt_setPitch->setObjectName(QString::fromUtf8("txt_setPitch"));

        verticalLayout_7->addWidget(txt_setPitch);

        txt_setYaw = new QLineEdit(layoutWidget3);
        txt_setYaw->setObjectName(QString::fromUtf8("txt_setYaw"));

        verticalLayout_7->addWidget(txt_setYaw);

        txt_setSpeed = new QLineEdit(layoutWidget3);
        txt_setSpeed->setObjectName(QString::fromUtf8("txt_setSpeed"));

        verticalLayout_7->addWidget(txt_setSpeed);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_10->addWidget(label_19);

        label_20 = new QLabel(layoutWidget3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_10->addWidget(label_20);

        label_21 = new QLabel(layoutWidget3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_10->addWidget(label_21);

        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_10->addWidget(label_22);

        label_23 = new QLabel(layoutWidget3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_10->addWidget(label_23);

        label_24 = new QLabel(layoutWidget3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_10->addWidget(label_24);

        label_25 = new QLabel(layoutWidget3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_10->addWidget(label_25);


        horizontalLayout_3->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbtn_xyz = new QRadioButton(layoutWidget3);
        rbtn_xyz->setObjectName(QString::fromUtf8("rbtn_xyz"));
        rbtn_xyz->setChecked(true);

        horizontalLayout_4->addWidget(rbtn_xyz);

        rbtn_rpy = new QRadioButton(layoutWidget3);
        rbtn_rpy->setObjectName(QString::fromUtf8("rbtn_rpy"));

        horizontalLayout_4->addWidget(rbtn_rpy);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        pushButton_2 = new QPushButton(layoutWidget3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout_11->addLayout(horizontalLayout_6);

        lb_run_status = new QLabel(centralWidget);
        lb_run_status->setObjectName(QString::fromUtf8("lb_run_status"));
        lb_run_status->setGeometry(QRect(410, 250, 67, 17));
        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(300, 250, 101, 17));
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 170, 234, 67));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        btn_saveJob = new QPushButton(layoutWidget4);
        btn_saveJob->setObjectName(QString::fromUtf8("btn_saveJob"));

        verticalLayout_12->addWidget(btn_saveJob);

        btn_loadJob = new QPushButton(layoutWidget4);
        btn_loadJob->setObjectName(QString::fromUtf8("btn_loadJob"));

        verticalLayout_12->addWidget(btn_loadJob);


        horizontalLayout_7->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        txt_saveJob = new QLineEdit(layoutWidget4);
        txt_saveJob->setObjectName(QString::fromUtf8("txt_saveJob"));

        verticalLayout_13->addWidget(txt_saveJob);

        txt_loadJob = new QLineEdit(layoutWidget4);
        txt_loadJob->setObjectName(QString::fromUtf8("txt_loadJob"));

        verticalLayout_13->addWidget(txt_loadJob);


        horizontalLayout_7->addLayout(verticalLayout_13);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 270, 411, 231));
        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 30, 47, 13));
        label_35 = new QLabel(groupBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(20, 60, 47, 13));
        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(20, 90, 47, 13));
        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(20, 120, 47, 13));
        label_38 = new QLabel(groupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(20, 150, 47, 13));
        label_39 = new QLabel(groupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(20, 180, 47, 13));
        t1_inc = new QPushButton(groupBox);
        t1_inc->setObjectName(QString::fromUtf8("t1_inc"));
        t1_inc->setGeometry(QRect(100, 30, 51, 21));
        t1_dec = new QPushButton(groupBox);
        t1_dec->setObjectName(QString::fromUtf8("t1_dec"));
        t1_dec->setGeometry(QRect(40, 30, 51, 21));
        t2_inc = new QPushButton(groupBox);
        t2_inc->setObjectName(QString::fromUtf8("t2_inc"));
        t2_inc->setGeometry(QRect(100, 60, 51, 21));
        t2_dec = new QPushButton(groupBox);
        t2_dec->setObjectName(QString::fromUtf8("t2_dec"));
        t2_dec->setGeometry(QRect(40, 60, 51, 21));
        t3_inc = new QPushButton(groupBox);
        t3_inc->setObjectName(QString::fromUtf8("t3_inc"));
        t3_inc->setGeometry(QRect(100, 90, 51, 21));
        t3_dec = new QPushButton(groupBox);
        t3_dec->setObjectName(QString::fromUtf8("t3_dec"));
        t3_dec->setGeometry(QRect(40, 90, 51, 21));
        t4_inc = new QPushButton(groupBox);
        t4_inc->setObjectName(QString::fromUtf8("t4_inc"));
        t4_inc->setGeometry(QRect(100, 120, 51, 21));
        t4_dec = new QPushButton(groupBox);
        t4_dec->setObjectName(QString::fromUtf8("t4_dec"));
        t4_dec->setGeometry(QRect(40, 120, 51, 21));
        t5_inc = new QPushButton(groupBox);
        t5_inc->setObjectName(QString::fromUtf8("t5_inc"));
        t5_inc->setGeometry(QRect(100, 150, 51, 21));
        t5_dec = new QPushButton(groupBox);
        t5_dec->setObjectName(QString::fromUtf8("t5_dec"));
        t5_dec->setGeometry(QRect(40, 150, 51, 21));
        t6_inc = new QPushButton(groupBox);
        t6_inc->setObjectName(QString::fromUtf8("t6_inc"));
        t6_inc->setGeometry(QRect(100, 180, 51, 21));
        t6_dec = new QPushButton(groupBox);
        t6_dec->setObjectName(QString::fromUtf8("t6_dec"));
        t6_dec->setGeometry(QRect(40, 180, 51, 21));
        radiobt_rotation = new QRadioButton(groupBox);
        radiobt_rotation->setObjectName(QString::fromUtf8("radiobt_rotation"));
        radiobt_rotation->setGeometry(QRect(170, 30, 111, 19));
        radiobt_rotation->setChecked(true);
        radiobt_linear = new QRadioButton(groupBox);
        radiobt_linear->setObjectName(QString::fromUtf8("radiobt_linear"));
        radiobt_linear->setGeometry(QRect(170, 50, 101, 31));
        slider_dis_mm = new QSlider(groupBox);
        slider_dis_mm->setObjectName(QString::fromUtf8("slider_dis_mm"));
        slider_dis_mm->setGeometry(QRect(160, 100, 160, 16));
        slider_dis_mm->setOrientation(Qt::Horizontal);
        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(160, 80, 61, 16));
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(360, 100, 47, 13));
        slider_dis_deg = new QSlider(groupBox);
        slider_dis_deg->setObjectName(QString::fromUtf8("slider_dis_deg"));
        slider_dis_deg->setGeometry(QRect(160, 130, 160, 16));
        slider_dis_deg->setOrientation(Qt::Horizontal);
        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(360, 130, 47, 13));
        slider_sp_degps = new QSlider(groupBox);
        slider_sp_degps->setObjectName(QString::fromUtf8("slider_sp_degps"));
        slider_sp_degps->setGeometry(QRect(160, 200, 160, 16));
        slider_sp_degps->setOrientation(Qt::Horizontal);
        slider_sp_mps = new QSlider(groupBox);
        slider_sp_mps->setObjectName(QString::fromUtf8("slider_sp_mps"));
        slider_sp_mps->setGeometry(QRect(160, 170, 160, 16));
        slider_sp_mps->setOrientation(Qt::Horizontal);
        label_43 = new QLabel(groupBox);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(360, 170, 47, 13));
        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(360, 200, 47, 13));
        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(160, 150, 61, 16));
        label_dis_mm_val = new QLabel(groupBox);
        label_dis_mm_val->setObjectName(QString::fromUtf8("label_dis_mm_val"));
        label_dis_mm_val->setGeometry(QRect(330, 100, 47, 13));
        label_dis_deg_val = new QLabel(groupBox);
        label_dis_deg_val->setObjectName(QString::fromUtf8("label_dis_deg_val"));
        label_dis_deg_val->setGeometry(QRect(330, 130, 47, 13));
        label_sp_mps_val = new QLabel(groupBox);
        label_sp_mps_val->setObjectName(QString::fromUtf8("label_sp_mps_val"));
        label_sp_mps_val->setGeometry(QRect(330, 170, 47, 13));
        label_sp_degps_val = new QLabel(groupBox);
        label_sp_degps_val->setObjectName(QString::fromUtf8("label_sp_degps_val"));
        label_sp_degps_val->setGeometry(QRect(330, 200, 47, 13));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 300, 461, 221));
        theta6 = new QLineEdit(groupBox_2);
        theta6->setObjectName(QString::fromUtf8("theta6"));
        theta6->setGeometry(QRect(10, 170, 113, 21));
        theta1 = new QLineEdit(groupBox_2);
        theta1->setObjectName(QString::fromUtf8("theta1"));
        theta1->setGeometry(QRect(10, 20, 113, 21));
        theta4 = new QLineEdit(groupBox_2);
        theta4->setObjectName(QString::fromUtf8("theta4"));
        theta4->setGeometry(QRect(10, 110, 113, 21));
        theta3 = new QLineEdit(groupBox_2);
        theta3->setObjectName(QString::fromUtf8("theta3"));
        theta3->setGeometry(QRect(10, 80, 113, 21));
        theta2 = new QLineEdit(groupBox_2);
        theta2->setObjectName(QString::fromUtf8("theta2"));
        theta2->setGeometry(QRect(10, 50, 113, 21));
        theta5 = new QLineEdit(groupBox_2);
        theta5->setObjectName(QString::fromUtf8("theta5"));
        theta5->setGeometry(QRect(10, 140, 113, 21));
        label_46 = new QLabel(groupBox_2);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(130, 20, 71, 16));
        label_47 = new QLabel(groupBox_2);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(130, 50, 71, 16));
        label_48 = new QLabel(groupBox_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(130, 80, 71, 16));
        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(130, 110, 71, 16));
        label_50 = new QLabel(groupBox_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(130, 140, 71, 16));
        label_51 = new QLabel(groupBox_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(130, 170, 71, 16));
        fk_calculate = new QPushButton(groupBox_2);
        fk_calculate->setObjectName(QString::fromUtf8("fk_calculate"));
        fk_calculate->setGeometry(QRect(200, 190, 80, 21));
        fk_rz = new QLabel(groupBox_2);
        fk_rz->setObjectName(QString::fromUtf8("fk_rz"));
        fk_rz->setGeometry(QRect(290, 170, 71, 16));
        fk_y = new QLabel(groupBox_2);
        fk_y->setObjectName(QString::fromUtf8("fk_y"));
        fk_y->setGeometry(QRect(290, 50, 71, 16));
        fk_rx = new QLabel(groupBox_2);
        fk_rx->setObjectName(QString::fromUtf8("fk_rx"));
        fk_rx->setGeometry(QRect(290, 110, 71, 16));
        fk_ry = new QLabel(groupBox_2);
        fk_ry->setObjectName(QString::fromUtf8("fk_ry"));
        fk_ry->setGeometry(QRect(290, 140, 71, 16));
        fk_x = new QLabel(groupBox_2);
        fk_x->setObjectName(QString::fromUtf8("fk_x"));
        fk_x->setGeometry(QRect(290, 20, 71, 16));
        fk_z = new QLabel(groupBox_2);
        fk_z->setObjectName(QString::fromUtf8("fk_z"));
        fk_z->setGeometry(QRect(290, 80, 71, 16));
        label_58 = new QLabel(groupBox_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(370, 170, 71, 16));
        label_59 = new QLabel(groupBox_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(370, 50, 71, 16));
        label_60 = new QLabel(groupBox_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(370, 110, 71, 16));
        label_61 = new QLabel(groupBox_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(370, 80, 71, 16));
        label_62 = new QLabel(groupBox_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(370, 20, 71, 16));
        label_63 = new QLabel(groupBox_2);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(370, 140, 71, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 958, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(slider_dis_mm, SIGNAL(valueChanged(int)), label_dis_mm_val, SLOT(setNum(int)));
        QObject::connect(slider_dis_deg, SIGNAL(valueChanged(int)), label_dis_deg_val, SLOT(setNum(int)));
        QObject::connect(slider_sp_mps, SIGNAL(valueChanged(int)), label_sp_mps_val, SLOT(setNum(int)));
        QObject::connect(slider_sp_degps, SIGNAL(valueChanged(int)), label_sp_degps_val, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Motomini Server", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "IP address", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "File Port", nullptr));
        txt_ip->setText(QCoreApplication::translate("MainWindow", "192.168.1.13", nullptr));
        txt_port->setText(QCoreApplication::translate("MainWindow", "10040", nullptr));
        txt_filePort->setText(QCoreApplication::translate("MainWindow", "10041", nullptr));
        btn_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btn_servo->setText(QCoreApplication::translate("MainWindow", "Servo On", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Current position", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "mm/s", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Get Position", nullptr));
        rbtn_linkAbs->setText(QCoreApplication::translate("MainWindow", "Link Abs", nullptr));
        rbtn_lineAbs->setText(QCoreApplication::translate("MainWindow", "Line Abs", nullptr));
        rbtn_LineInc->setText(QCoreApplication::translate("MainWindow", "Line Inc", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Set position", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        txt_setX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setRoll->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setPitch->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setYaw->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        txt_setSpeed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "mm/s - deg/s", nullptr));
        rbtn_xyz->setText(QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        rbtn_rpy->setText(QCoreApplication::translate("MainWindow", "RPY", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Set Position", nullptr));
        lb_run_status->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Robot Status :", nullptr));
        btn_saveJob->setText(QCoreApplication::translate("MainWindow", "Save job", nullptr));
        btn_loadJob->setText(QCoreApplication::translate("MainWindow", "Load job", nullptr));
        txt_saveJob->setText(QCoreApplication::translate("MainWindow", "MASTER.JBI", nullptr));
        txt_loadJob->setText(QCoreApplication::translate("MainWindow", "TESTS.JBI", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Incremental Position", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "T1", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "T2", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "T3", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "T4", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "T5", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "T6", nullptr));
        t1_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t1_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        t2_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t2_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        t3_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t3_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        t4_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t4_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        t5_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t5_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        t6_inc->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        t6_dec->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        radiobt_rotation->setText(QCoreApplication::translate("MainWindow", "Rotation velocity", nullptr));
        radiobt_linear->setText(QCoreApplication::translate("MainWindow", "Linear velocity", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "DISTANCE", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "mm/s", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "deg/s", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "SPEED", nullptr));
        label_dis_mm_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_dis_deg_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_sp_mps_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_sp_degps_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Foward kinematic validation", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Theata1(deg)", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Theata2(deg)", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Theata3(deg)", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "Theata4(deg)", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "Theata5(deg)", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "Theata6(deg)", nullptr));
        fk_calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        fk_rz->setText(QString());
        fk_y->setText(QString());
        fk_rx->setText(QString());
        fk_ry->setText(QString());
        fk_x->setText(QString());
        fk_z->setText(QString());
        label_58->setText(QCoreApplication::translate("MainWindow", "Yaw(deg)", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Y(mm)", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "Roll(deg)", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "Z(mm)", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "X(mm)", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "Pitch(deg)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
