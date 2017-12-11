#include "weatherapp.h"
#include "ui_weatherapp.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>

WeatherApp::WeatherApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherApp)
{
//    setStyleSheet("QMainWindow { background-image: url(/home/senal/Desktop/colombo.jpg) } ");


//    QPalette palette;
//    palette.setBrush(this->backgroundRole(), QBrush(QImage("/home/senal/Desktop/colombo.jpg")));
//    this->setPalette(palette);
//    qDebug() << "bg happened";

    QGraphicsView * view = new QGraphicsView(this);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    qDebug() << "bg happened";
    item->setPixmap(QPixmap("/home/senal/Desktop/colombo.jpg"));
qDebug() << "bg happened";
    scene->setSceneRect(0,0,QWidget::width(), QWidget::height());
qDebug() << "bg happened";
    view->setScene(scene);
    qDebug() << "bg happened";
    item->setPos(0,0);
    scene->addItem(item);
    view->show();


    ui->setupUi(this);
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
