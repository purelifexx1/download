#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "yrc1000micro_com.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn_connect_clicked();

    void on_btn_servo_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void updateUICallback();

    void timerCallback();

    void on_btn_saveJob_clicked();

    void on_btn_loadJob_clicked();

    void inc_dec_bt_clicked();


    void on_fk_calculate_clicked();

private:
    Ui::MainWindow *ui;
    QPalette pal_red = palette();
    QPalette pal_green = palette();
    //    Init udp connection
//    UDP udp_sever;

    YRC1000micro_com yrc100micro_com;
    QTimer *timer;

};

#endif // MAINWINDOW_H
