#include "weatherapp.h"
#include "ui_weatherapp.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QCompleter>

WeatherApp::WeatherApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherApp)
{

    QGraphicsView * view = new QGraphicsView(this);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(QPixmap("/home/senal/Desktop/colombo.jpg"));
    scene->setSceneRect(0,0,QWidget::width(), QWidget::height());
    view->setScene(scene);
    item->setPos(0,0);
    scene->addItem(item);
    view->show();

    ui->setupUi(this);

    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";

    QCompleter *locationCompleter = new QCompleter(wordList, this);
    locationCompleter->setCaseSensitivity(Qt::CaseInsensitive);

    ui->locationEdit->setCompleter(locationCompleter);
}

WeatherApp::~WeatherApp()
{
    delete ui;
}

void setBG(){

}
