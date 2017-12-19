#include "apihandle.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "weatherapp.h"

extern WeatherApp * mainScreen;

ApiHandle::ApiHandle(QObject *parent) : QObject(parent)
{
    connect(NetManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(dataRead(QNetworkReply*)));
}

void ApiHandle::makeRequest(QString endPointRequest)
{
    NetManager->get(QNetworkRequest(QUrl(endPointRequest)));
}

void ApiHandle::dataRead(QNetworkReply *reply)
{
    //gets the api QByteArray response
    QByteArray myData = reply->readAll();
    //converts and saves the QByteArray as a QJsonDocument
    QJsonDocument dataDoc = QJsonDocument::fromJson(myData);
    //converts and saves the QJsonDoc as a QJsonObject
    QJsonObject itemObject = dataDoc.object();

    //separating coordinates from the JSON Object
    qreal lat = ((itemObject.value("coord").toObject())
                .value("lat"))
                    .toDouble();
    qreal lon = ((itemObject.value("coord").toObject())
                .value("lon"))
                    .toDouble();
    qDebug()<<"";
    qDebug()<<"Longitude:"<<lon<<", Latitude:"<<lat;

    //separating weather from the JSON Object
    QJsonArray weather = (itemObject.value("weather").toArray());
    foreach (const QJsonValue &value, weather) {
        QJsonObject temp = value.toObject();

        weather_id = (temp.value("id")).toInt();
        main = (temp.value("main")).toString();
        des = (temp.value("description")).toString();
        icon = (temp.value("icon")).toString();

        qDebug()<<"ID:"<<weather_id<<", Main:"<<main<<", Description"<<des<<", Icon:"<<icon;
    }

    //separating main info from the JSON Object
    qreal temp = ((itemObject.value("main").toObject())
                .value("temp"))
                    .toDouble();
    qreal pres = ((itemObject.value("main").toObject())
                .value("pressure"))
                    .toDouble();
    qreal humi = ((itemObject.value("main").toObject())
                .value("humidity"))
                    .toDouble();
    qreal temp_max = ((itemObject.value("main").toObject())
                .value("temp_max"))
                    .toDouble();
    qreal temp_min = ((itemObject.value("main").toObject())
                .value("temp_min"))
                    .toDouble();
    qDebug()<<"Temperature:"<<temp<<", Pressure"<<pres<<", humidity:"<<humi<<", Max Temperature"<<temp_max<<", Min Tempreature"<<temp_min;

    //separating wind from the JSON Object
    qreal speed = ((itemObject.value("wind").toObject())
                .value("speed"))
                    .toDouble();
    qreal deg = ((itemObject.value("wind").toObject())
                .value("deg"))
                    .toDouble();
    qDebug()<<"Speed:"<<speed<<", Direction:"<<deg;

    //separating sys from the JSON Object
    qint32 type = ((itemObject.value("sys").toObject())
                .value("type"))
                    .toInt();
    qint32 sys_id = ((itemObject.value("sys").toObject())
                .value("id"))
                    .toInt();
    qreal message = ((itemObject.value("sys").toObject())
                .value("message"))
                    .toDouble();
    QString country = ((itemObject.value("sys").toObject())
                .value("country"))
                    .toString();
    qint32 sunrise = ((itemObject.value("sys").toObject())
                .value("sunrise"))
                    .toInt();
    qint32 sunset = ((itemObject.value("sys").toObject())
                .value("sunset"))
                    .toInt();
    qDebug()<<"Type:"<<type<<", ID"<<sys_id<<", Message:"<<message<<", Country"<<country<<", Sunrise"<<sunrise<<", Sunset"<<sunset;


    mainScreen->setWeatherValues(lon, lat, weather_id, main, des, icon, temp, pres, humi, temp_max, temp_min, speed, deg, type, sys_id, message, country, sunrise, sunset);


    emit(dataReadyRead(myData));
}

