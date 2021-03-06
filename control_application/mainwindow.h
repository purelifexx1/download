#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receivethread.h"
#include "define_parameter.h"
#include "packet_handler.h"
#define log_console(content) ui->tb_console->append(content)
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
    define_parameter *system_parameter = new define_parameter();
    packet_handler *_packet_handler = new packet_handler();

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

    void on_bt_read_position_clicked();

    void on_bt_keycommand();

    void on_bt_key_setsp_clicked();

    void on_bt_set_method_clicked();

    void on_bt_clear_console_clicked();

    void on_testing_clicked();

    void on_bt_testmt();

    void on_bt_conveyor_sp_clicked();

public slots:
    void received_callback(QByteArray data);
    void display_event(Display_packet data);
private:
    Ui::MainWindow *ui;
    void QbyteArray_AddValue(QByteArray *object_array, QVariant convert_object, TypeDef_Conversion input_type);
};
#endif // MAINWINDOW_H
