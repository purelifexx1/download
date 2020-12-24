#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receivethread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ReceiveThread *Received_Thread;
private slots:
    void on_bt_refresh_clicked();

    void on_bt_connect_clicked();

    void on_bt_robot_stop_clicked();
    void on_bt_scan_limit_clicked();

    void on_bt_home_clicked();

    void on_bt_movL_clicked();

    void on_bt_model_setting_clicked();

    void on_bt_on_magnet_clicked();

    void on_bt_off_magnet_clicked();

public slots:
    void received_callback(QByteArray data);
private:
    Ui::MainWindow *ui;
    void addspace(QByteArray *obj);
};
#endif // MAINWINDOW_H
