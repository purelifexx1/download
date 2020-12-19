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
    QPushButton *test1;
    QPushButton *bt_robot_stop;
    QPushButton *test2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 291);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        com_list = new QComboBox(centralwidget);
        com_list->setObjectName(QString::fromUtf8("com_list"));
        com_list->setGeometry(QRect(71, 40, 111, 21));
        bt_connect = new QPushButton(centralwidget);
        bt_connect->setObjectName(QString::fromUtf8("bt_connect"));
        bt_connect->setGeometry(QRect(280, 40, 80, 21));
        bt_refresh = new QPushButton(centralwidget);
        bt_refresh->setObjectName(QString::fromUtf8("bt_refresh"));
        bt_refresh->setGeometry(QRect(190, 40, 80, 21));
        test1 = new QPushButton(centralwidget);
        test1->setObjectName(QString::fromUtf8("test1"));
        test1->setGeometry(QRect(230, 140, 80, 21));
        bt_robot_stop = new QPushButton(centralwidget);
        bt_robot_stop->setObjectName(QString::fromUtf8("bt_robot_stop"));
        bt_robot_stop->setGeometry(QRect(350, 140, 80, 21));
        test2 = new QPushButton(centralwidget);
        test2->setObjectName(QString::fromUtf8("test2"));
        test2->setGeometry(QRect(290, 190, 80, 21));
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
        test1->setText(QCoreApplication::translate("MainWindow", "test1", nullptr));
        bt_robot_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        test2->setText(QCoreApplication::translate("MainWindow", "test2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
