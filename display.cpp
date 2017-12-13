#include "display.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "weatherapp.h"

extern WeatherApp *MainScreen;

Display::Display()
{

}

void Display::setBG(){

    QGraphicsView *view = new QGraphicsView(MainScreen);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(QPixmap("/home/senal/Desktop/colombo.jpg"));
    scene->setSceneRect(0,0,300,440);
    view->setScene(scene);
    item->setPos(0,0);
    scene->addItem(item);
    view->show();
    qDebug()<<"This thing happened!";
}
