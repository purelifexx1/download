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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 340);
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
        groupBox->setGeometry(QRect(30, 50, 281, 201));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 20));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
