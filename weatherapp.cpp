#include "weatherapp.h"
#include "ui_weatherapp.h"
#include <QDebug>

WeatherApp::WeatherApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherApp)
{
    ui->setupUi(this);
//    setStyleSheet("QMainWindow { background-image: url(/home/senal/Desktop/colombo.jpg) } ");

`
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("/home/senal/Desktop/colombo.jpg")));
    this->setPalette(palette);
    qDebug() << "bg happened";

//    this->setStyleSheet("background-image:url(\"https://i.imgur.com/0CiEAZ9.jpg\");" );


//    QPixmap bkgnd("/home/senal/Desktop/this.jpg");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);
}

WeatherApp::~WeatherApp()
{
    delete ui;
}

void setBG(){

}