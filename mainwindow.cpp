#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SP = NULL; // create a NULL serial ptr
    populateCom();
    ui->comboBox_com->setCurrentIndex(2);
    on_comboBox_com_currentTextChanged("COM3");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkConnectionStatus()));
    timer->start();

    ui->radioButton_standard->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete SP;
}

void MainWindow::populateCom()
{
    ui->comboBox_com->addItem("COM1");
    ui->comboBox_com->addItem("COM2");
    ui->comboBox_com->addItem("COM3");
    ui->comboBox_com->addItem("COM4");
}

void MainWindow::checkConnectionStatus()
{
    if (SP->IsConnected())
    {
        QString com = ui->comboBox_com->currentText();
        ui->label_connectionStatus->setText("CONNECTED TO " + com);
    }
    else
    {
        ui->label_connectionStatus->setText("NOT CONNECTED");
    }
}

void MainWindow::on_pushButton_turnRight_pressed()
{
    char bytes[1];
    bytes[0] = 'R';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_pushButton_turnLeft_pressed()
{
    char bytes[1];
    bytes[0] = 'L';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_comboBox_com_currentTextChanged(const QString &arg1)
{
    // delete current serial pointer and create a new one
    // with the given COM

    if (SP != NULL)
    {
        delete SP;
    }

    if (arg1 == "COM1")
    {
        SP = new Serial("\\\\.\\COM1");
    }
    else if (arg1 == "COM2")
    {
        SP = new Serial("\\\\.\\COM2");
    }
    else if (arg1 == "COM3")
    {
        SP = new Serial("\\\\.\\COM3");
    }
    else if (arg1 == "COM4")
    {
        SP = new Serial("\\\\.\\COM4");
    }
}

void MainWindow::on_pushButton_stop_pressed()
{
    char bytes[1];
    bytes[0] = '9';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_pushButton_forward_pressed()
{
    char bytes[1];
    bytes[0] = '1';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_pushButton_reverse_pressed()
{
    char bytes[1];
    bytes[0] = '2';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_pushButton_retry_pressed()
{
    on_comboBox_com_currentTextChanged(ui->comboBox_com->currentText());
}

void MainWindow::on_radioButton_standard_pressed()
{
    on_pushButton_stop_pressed();

    char bytes[1];
    bytes[0] = 'F';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_radioButton_sideways_pressed()
{
    on_pushButton_stop_pressed();

    char bytes[1];
    bytes[0] = 'S';
    SP->WriteData(bytes, 1);
}

void MainWindow::on_radioButton_zero_pressed()
{
    on_pushButton_stop_pressed();

    char bytes[1];
    bytes[0] = 'O';
    SP->WriteData(bytes, 1);
}
