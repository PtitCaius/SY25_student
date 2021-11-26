#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
}

ControlWindow::~ControlWindow()
{
    delete ui;
}


void ControlWindow::onFrameReady(QPixmap pixmap)
{
    pixmap.scaled(ui->label->width(), ui->label->width(), Qt::KeepAspectRatio);
    ui->label->setPixmap(pixmap);
}

void ControlWindow::on_startBtn_clicked()
{
    emit startCamera();
}

void ControlWindow::on_fullFpsBtn_clicked()
{
    emit setCameraFullFPS();
}

void ControlWindow::on_lowFPSBtn_clicked()
{
    emit setCameraLowFPS();
}

void ControlWindow::on_stopBtn_clicked()
{
    emit stopCamera();
}
