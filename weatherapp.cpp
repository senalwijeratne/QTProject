#include "weatherapp.h"
#include "ui_weatherapp.h"

WeatherApp::WeatherApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherApp)
{
    setBG();
    ui->setupUi(this);
//    setAutoComp();
    connect(&api,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(dataInDaHouse(QByteArray data)));
}

WeatherApp::~WeatherApp(){
    delete ui;
}

void WeatherApp::setBG(){
    QGraphicsView * view = new QGraphicsView(this);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(QPixmap("/home/senal/Desktop/colombo.jpg"));
    scene->setSceneRect(0,0,QWidget::width(), QWidget::height());
    view->setScene(scene);
    item->setPos(0,0);
    scene->addItem(item);
    view->show();
    qDebug()<<"BG happened in weatherapp.cpp";
}

//void WeatherApp::setAutoComp(){
//    QStringList wordList;
//    wordList << "alpha" << "omega" << "omicron" << "zeta";
//    QCompleter *locationCompleter = new QCompleter(wordList, this);
//    locationCompleter->setCaseSensitivity(Qt::CaseInsensitive);
//    ui->locationEdit->setCompleter(locationCompleter);
//}

void WeatherApp::on_searchButton_clicked()
{
    QString city = ui->locationEdit->text();
    api.makeRequest("http://api.openweathermap.org/data/2.5/weather?q="+city+"&units=metric&appid=6a0c25eeca3831360143ec4edb858aad");
}

void WeatherApp::dataInDaHouse(QByteArray data)
{
    QString dataString;
    dataString = data;
    qDebug()<<"is it tho?"<<dataString;
}

void WeatherApp::setWeatherValues(qreal lon, qreal lat,
                                  qint32 weather_id, QString main, QString des, QString icon,
                                  qint32 temp, qint32 pres, qint32 humi, qint32 temp_max, qint32 temp_min,
                                  qreal speed, qreal deg,
                                  qint32 type, qint32 sys_id, qreal message, QString country, qint32 sunrise, qint32 sunset)
{
    ui->tempLabel->setText(QString::number(temp));

    qDebug()<<"";
    qDebug()<<"";
    qDebug()<<"Longitude:"<<lon<<", Latitude:"<<lat;
    qDebug()<<"ID:"<<weather_id<<", Main:"<<main<<", Description"<<des<<", Icon:"<<icon;
    qDebug()<<"Temperature:"<<temp<<", Pressure"<<pres<<", humidity:"<<humi<<", Max Temperature"<<temp_max<<", Min Tempreature"<<temp_min;
    qDebug()<<"Speed:"<<speed<<", Direction:"<<deg;
    qDebug()<<"Type:"<<type<<", ID"<<sys_id<<", Message:"<<message<<", Country"<<country<<", Sunrise"<<sunrise<<", Sunset"<<sunset;
}
