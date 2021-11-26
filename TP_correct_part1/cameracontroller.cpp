#include "cameracontroller.h"
#include <QThread>
#include <QDebug>

CameraController::CameraController(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000); //1 seconde
    connect(timer, &QTimer::timeout, this, &CameraController::sendImage);
}

void CameraController::startCamera()
{
    running = true;
    videoCapture.open(0);
    if(!fullfps){
        timer->start();
    }
    if(videoCapture.isOpened()){
        runCam();
    }
    return;
}

void CameraController::stopCamera()
{
    running = false;
    timer->stop();
    videoCapture.release();
}

void CameraController::setCameraFullFPS()
{
    timer->stop();
    fullfps = true;
}

void CameraController::setCameraLowFPS()
{
    timer->start();
    fullfps = false;

}

void CameraController::runCam(){
    if(running && videoCapture.isOpened()){
        videoCapture >> image;
        if(fullfps){
            sendImage();
        }
        QTimer::singleShot(0, this, &CameraController::runCam);
    }
}

void CameraController::sendImage(){
    emit frameReady(QPixmap::fromImage(QImage((unsigned char*) image.data, image.cols, image.rows, QImage::Format_RGB888)));
}
