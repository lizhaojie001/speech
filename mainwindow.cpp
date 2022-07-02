#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QRandomGenerator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    speech = new QTextToSpeech(this);
    speech->setVolume(100);
    _timer = new QTimer(this);
    connect(_timer,&QTimer::timeout,this,[&]() {
        int i = (QRandomGenerator::global()->bounded(7) + 100)%7 + 1;
        QString tts = QString("%1").arg(i);
        ui->label->setText(tts);
        speech->say(tts);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (_timer->isActive()) {
          _timer->stop();
        ui->pushButton->setText("开始");
    } else {
        _timer->start(2000);
        ui->pushButton->setText("暂停");
    }

}

