#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = nullptr);
    ~ControlWindow();

private:
    Ui::ControlWindow *ui;

signals:
    void startCamera();
    void stopCamera();
    void setCameraFullFPS();
    void setCameraLowFPS();

public slots:
    void onFrameReady(QPixmap pixmap);
private slots:
    void on_startBtn_clicked();
    void on_fullFpsBtn_clicked();
    void on_lowFPSBtn_clicked();
    void on_stopBtn_clicked();
};

#endif // CONTROLWINDOW_H
