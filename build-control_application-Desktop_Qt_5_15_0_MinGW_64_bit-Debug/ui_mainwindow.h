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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *com_list;
    QPushButton *bt_connect;
    QPushButton *bt_refresh;
    QGroupBox *groupBox;
    QPushButton *bt_robot_stop;
    QPushButton *bt_scan_limit;
    QPushButton *test1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *test1_2;
    QPushButton *pushButton_3;
    QPushButton *test1_3;
    QPushButton *bt_home;
    QGroupBox *groupBox_2;
    QLineEdit *tb_x_cor;
    QLineEdit *tb_y_cor;
    QLineEdit *tb_z_cor;
    QLineEdit *tb_roll_ang;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *tb_a_factor;
    QLineEdit *tb_v_factor;
    QLabel *label_7;
    QLineEdit *tb_time;
    QPushButton *bt_movL;
    QGroupBox *groupBox_3;
    QRadioButton *rb_qva;
    QRadioButton *rb_qvt;
    QGroupBox *groupBox_4;
    QRadioButton *rb_inc;
    QRadioButton *rb_abs;
    QGroupBox *groupBox_5;
    QRadioButton *rb_scur;
    QRadioButton *rb_lspb;
    QPushButton *bt_model_setting;
    QGroupBox *groupBox_6;
    QPushButton *bt_off_magnet;
    QPushButton *bt_on_magnet;
    QGroupBox *groupBox_7;
    QLineEdit *tb_x_cur_cor;
    QLineEdit *tb_y_cur_cor;
    QLineEdit *tb_z_cur_cor;
    QLineEdit *tb_roll_cur_cor;
    QLineEdit *tb_theta1_cur_val;
    QLineEdit *tb_theta2_cur_val;
    QLineEdit *tb_d3_cur_val;
    QLineEdit *tb_theta4_cur_val;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *bt_read_position;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 430);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        com_list = new QComboBox(centralwidget);
        com_list->setObjectName(QString::fromUtf8("com_list"));
        com_list->setGeometry(QRect(21, 10, 111, 21));
        bt_connect = new QPushButton(centralwidget);
        bt_connect->setObjectName(QString::fromUtf8("bt_connect"));
        bt_connect->setGeometry(QRect(230, 10, 80, 21));
        bt_refresh = new QPushButton(centralwidget);
        bt_refresh->setObjectName(QString::fromUtf8("bt_refresh"));
        bt_refresh->setGeometry(QRect(140, 10, 80, 21));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 291, 171));
        bt_robot_stop = new QPushButton(groupBox);
        bt_robot_stop->setObjectName(QString::fromUtf8("bt_robot_stop"));
        bt_robot_stop->setGeometry(QRect(20, 30, 80, 21));
        bt_scan_limit = new QPushButton(groupBox);
        bt_scan_limit->setObjectName(QString::fromUtf8("bt_scan_limit"));
        bt_scan_limit->setGeometry(QRect(110, 30, 80, 21));
        test1 = new QPushButton(groupBox);
        test1->setObjectName(QString::fromUtf8("test1"));
        test1->setGeometry(QRect(20, 80, 80, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 80, 80, 21));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 110, 80, 21));
        test1_2 = new QPushButton(groupBox);
        test1_2->setObjectName(QString::fromUtf8("test1_2"));
        test1_2->setGeometry(QRect(20, 110, 80, 21));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 140, 80, 21));
        test1_3 = new QPushButton(groupBox);
        test1_3->setObjectName(QString::fromUtf8("test1_3"));
        test1_3->setGeometry(QRect(20, 140, 80, 21));
        bt_home = new QPushButton(groupBox);
        bt_home->setObjectName(QString::fromUtf8("bt_home"));
        bt_home->setGeometry(QRect(200, 30, 80, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 10, 391, 341));
        tb_x_cor = new QLineEdit(groupBox_2);
        tb_x_cor->setObjectName(QString::fromUtf8("tb_x_cor"));
        tb_x_cor->setGeometry(QRect(10, 30, 113, 21));
        tb_y_cor = new QLineEdit(groupBox_2);
        tb_y_cor->setObjectName(QString::fromUtf8("tb_y_cor"));
        tb_y_cor->setGeometry(QRect(10, 60, 113, 21));
        tb_z_cor = new QLineEdit(groupBox_2);
        tb_z_cor->setObjectName(QString::fromUtf8("tb_z_cor"));
        tb_z_cor->setGeometry(QRect(10, 90, 113, 21));
        tb_roll_ang = new QLineEdit(groupBox_2);
        tb_roll_ang->setObjectName(QString::fromUtf8("tb_roll_ang"));
        tb_roll_ang->setGeometry(QRect(10, 120, 113, 21));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 60, 47, 13));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 30, 47, 13));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 120, 47, 13));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 90, 47, 13));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 60, 47, 13));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 30, 47, 13));
        tb_a_factor = new QLineEdit(groupBox_2);
        tb_a_factor->setObjectName(QString::fromUtf8("tb_a_factor"));
        tb_a_factor->setGeometry(QRect(180, 60, 113, 21));
        tb_v_factor = new QLineEdit(groupBox_2);
        tb_v_factor->setObjectName(QString::fromUtf8("tb_v_factor"));
        tb_v_factor->setGeometry(QRect(180, 30, 113, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 90, 47, 13));
        tb_time = new QLineEdit(groupBox_2);
        tb_time->setObjectName(QString::fromUtf8("tb_time"));
        tb_time->setGeometry(QRect(180, 90, 113, 21));
        bt_movL = new QPushButton(groupBox_2);
        bt_movL->setObjectName(QString::fromUtf8("bt_movL"));
        bt_movL->setGeometry(QRect(190, 120, 80, 21));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 160, 111, 41));
        rb_qva = new QRadioButton(groupBox_3);
        rb_qva->setObjectName(QString::fromUtf8("rb_qva"));
        rb_qva->setGeometry(QRect(50, 20, 51, 19));
        rb_qvt = new QRadioButton(groupBox_3);
        rb_qvt->setObjectName(QString::fromUtf8("rb_qvt"));
        rb_qvt->setGeometry(QRect(0, 20, 41, 19));
        rb_qvt->setChecked(true);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(230, 160, 151, 41));
        rb_inc = new QRadioButton(groupBox_4);
        rb_inc->setObjectName(QString::fromUtf8("rb_inc"));
        rb_inc->setGeometry(QRect(0, 20, 84, 19));
        rb_abs = new QRadioButton(groupBox_4);
        rb_abs->setObjectName(QString::fromUtf8("rb_abs"));
        rb_abs->setGeometry(QRect(80, 20, 84, 19));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(230, 210, 131, 41));
        rb_scur = new QRadioButton(groupBox_5);
        rb_scur->setObjectName(QString::fromUtf8("rb_scur"));
        rb_scur->setGeometry(QRect(70, 20, 84, 19));
        rb_lspb = new QRadioButton(groupBox_5);
        rb_lspb->setObjectName(QString::fromUtf8("rb_lspb"));
        rb_lspb->setGeometry(QRect(0, 20, 84, 19));
        bt_model_setting = new QPushButton(groupBox_2);
        bt_model_setting->setObjectName(QString::fromUtf8("bt_model_setting"));
        bt_model_setting->setGeometry(QRect(230, 260, 80, 21));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 220, 171, 51));
        bt_off_magnet = new QPushButton(groupBox_6);
        bt_off_magnet->setObjectName(QString::fromUtf8("bt_off_magnet"));
        bt_off_magnet->setGeometry(QRect(90, 20, 80, 21));
        bt_on_magnet = new QPushButton(groupBox_6);
        bt_on_magnet->setObjectName(QString::fromUtf8("bt_on_magnet"));
        bt_on_magnet->setGeometry(QRect(0, 20, 80, 21));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 210, 311, 181));
        tb_x_cur_cor = new QLineEdit(groupBox_7);
        tb_x_cur_cor->setObjectName(QString::fromUtf8("tb_x_cur_cor"));
        tb_x_cur_cor->setGeometry(QRect(10, 20, 81, 21));
        tb_y_cur_cor = new QLineEdit(groupBox_7);
        tb_y_cur_cor->setObjectName(QString::fromUtf8("tb_y_cur_cor"));
        tb_y_cur_cor->setGeometry(QRect(10, 50, 81, 21));
        tb_z_cur_cor = new QLineEdit(groupBox_7);
        tb_z_cur_cor->setObjectName(QString::fromUtf8("tb_z_cur_cor"));
        tb_z_cur_cor->setGeometry(QRect(10, 80, 81, 21));
        tb_roll_cur_cor = new QLineEdit(groupBox_7);
        tb_roll_cur_cor->setObjectName(QString::fromUtf8("tb_roll_cur_cor"));
        tb_roll_cur_cor->setGeometry(QRect(10, 110, 81, 21));
        tb_theta1_cur_val = new QLineEdit(groupBox_7);
        tb_theta1_cur_val->setObjectName(QString::fromUtf8("tb_theta1_cur_val"));
        tb_theta1_cur_val->setGeometry(QRect(160, 20, 81, 21));
        tb_theta2_cur_val = new QLineEdit(groupBox_7);
        tb_theta2_cur_val->setObjectName(QString::fromUtf8("tb_theta2_cur_val"));
        tb_theta2_cur_val->setGeometry(QRect(160, 50, 81, 21));
        tb_d3_cur_val = new QLineEdit(groupBox_7);
        tb_d3_cur_val->setObjectName(QString::fromUtf8("tb_d3_cur_val"));
        tb_d3_cur_val->setGeometry(QRect(160, 80, 81, 21));
        tb_theta4_cur_val = new QLineEdit(groupBox_7);
        tb_theta4_cur_val->setObjectName(QString::fromUtf8("tb_theta4_cur_val"));
        tb_theta4_cur_val->setGeometry(QRect(160, 110, 81, 21));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 20, 47, 13));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 50, 47, 13));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 80, 47, 13));
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 110, 47, 13));
        label_12 = new QLabel(groupBox_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(250, 110, 47, 13));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(250, 20, 47, 13));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(250, 80, 47, 13));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(250, 50, 47, 13));
        bt_read_position = new QPushButton(groupBox_7);
        bt_read_position->setObjectName(QString::fromUtf8("bt_read_position"));
        bt_read_position->setGeometry(QRect(10, 140, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 743, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bt_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        bt_refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Robot command", nullptr));
        bt_robot_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        bt_scan_limit->setText(QCoreApplication::translate("MainWindow", "scan limit", nullptr));
        test1->setText(QCoreApplication::translate("MainWindow", "Inc x", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Dec x", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Dec y", nullptr));
        test1_2->setText(QCoreApplication::translate("MainWindow", "Inc y", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Dec z", nullptr));
        test1_3->setText(QCoreApplication::translate("MainWindow", "Inc z", nullptr));
        bt_home->setText(QCoreApplication::translate("MainWindow", "Move Home", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "A factor", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "V factor", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        bt_movL->setText(QCoreApplication::translate("MainWindow", "Move Line", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Calculate model", nullptr));
        rb_qva->setText(QCoreApplication::translate("MainWindow", "QVA", nullptr));
        rb_qvt->setText(QCoreApplication::translate("MainWindow", "QVT", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Move method", nullptr));
        rb_inc->setText(QCoreApplication::translate("MainWindow", "Incremental", nullptr));
        rb_abs->setText(QCoreApplication::translate("MainWindow", "Absolute", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Trajectory planning model", nullptr));
        rb_scur->setText(QCoreApplication::translate("MainWindow", "SCurve", nullptr));
        rb_lspb->setText(QCoreApplication::translate("MainWindow", "LSPB", nullptr));
        bt_model_setting->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Output shaft", nullptr));
        bt_off_magnet->setText(QCoreApplication::translate("MainWindow", "Magnet off", nullptr));
        bt_on_magnet->setText(QCoreApplication::translate("MainWindow", "Magnet on", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Current position", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "theta4", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "theta1", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "D3", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "theta2", nullptr));
        bt_read_position->setText(QCoreApplication::translate("MainWindow", "Read position", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H