#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "serialclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void populateCom();


private slots:
    void checkConnectionStatus();

    void on_pushButton_turnRight_pressed();

    void on_pushButton_turnLeft_pressed();

    void on_comboBox_com_currentTextChanged(const QString &arg1);

    void on_pushButton_stop_pressed();

    void on_pushButton_forward_pressed();

    void on_pushButton_reverse_pressed();

    void on_pushButton_retry_pressed();

    void on_radioButton_standard_pressed();

    void on_radioButton_sideways_pressed();

    void on_radioButton_zero_pressed();

private:
    Ui::MainWindow *ui;
    Serial* SP;
};
#endif // MAINWINDOW_H
