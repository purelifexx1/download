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
    QPushButton *pushButton_4;
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
    QRadioButton *rb_qvt;
    QRadioButton *rb_qva;
    QPushButton *bt_movL;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(913, 450);
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
        groupBox->setGeometry(QRect(30, 50, 311, 201));
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
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 90, 80, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 70, 461, 191));
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
        label_5->setGeometry(QRect(340, 80, 47, 13));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 50, 47, 13));
        tb_a_factor = new QLineEdit(groupBox_2);
        tb_a_factor->setObjectName(QString::fromUtf8("tb_a_factor"));
        tb_a_factor->setGeometry(QRect(220, 50, 113, 21));
        tb_v_factor = new QLineEdit(groupBox_2);
        tb_v_factor->setObjectName(QString::fromUtf8("tb_v_factor"));
        tb_v_factor->setGeometry(QRect(220, 80, 113, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 110, 47, 13));
        tb_time = new QLineEdit(groupBox_2);
        tb_time->setObjectName(QString::fromUtf8("tb_time"));
        tb_time->setGeometry(QRect(220, 110, 113, 21));
        rb_qvt = new QRadioButton(groupBox_2);
        rb_qvt->setObjectName(QString::fromUtf8("rb_qvt"));
        rb_qvt->setGeometry(QRect(10, 160, 84, 19));
        rb_qvt->setChecked(true);
        rb_qva = new QRadioButton(groupBox_2);
        rb_qva->setObjectName(QString::fromUtf8("rb_qva"));
        rb_qva->setGeometry(QRect(100, 160, 84, 19));
        bt_movL = new QPushButton(groupBox_2);
        bt_movL->setObjectName(QString::fromUtf8("bt_movL"));
        bt_movL->setGeometry(QRect(200, 150, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 913, 20));
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
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "A factor", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "V factor", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        rb_qvt->setText(QCoreApplication::translate("MainWindow", "QVT", nullptr));
        rb_qva->setText(QCoreApplication::translate("MainWindow", "QVA", nullptr));
        bt_movL->setText(QCoreApplication::translate("MainWindow", "Move Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
