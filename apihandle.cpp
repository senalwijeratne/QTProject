#include "apihandle.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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

    //separating main info from the JSON Object
    qint32 temp = ((itemObject.value("main").toObject())
                .value("temp"))
                    .toInt();
    qint32 pres = ((itemObject.value("main").toObject())
                .value("pressure"))
                    .toInt();
    qint32 humi = ((itemObject.value("main").toObject())
                .value("humidity"))
                    .toInt();
    qint32 temp_max = ((itemObject.value("main").toObject())
                .value("temp_max"))
                    .toInt();
    qint32 temp_min = ((itemObject.value("main").toObject())
                .value("temp_min"))
                    .toInt();
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
    qint32 id = ((itemObject.value("sys").toObject())
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
    qDebug()<<"Type:"<<type<<", ID"<<id<<", Message:"<<message<<", Country"<<country<<", Sunrise"<<sunrise<<", Sunset"<<sunset;

    //separating weather from the JSON Object
    QJsonArray weather = (itemObject.value("weather").toArray());
    foreach (const QJsonValue &value, weather) {
        QJsonObject temp = value.toObject();

        qint32 id = (temp.value("id")).toInt();
        QString main = (temp.value("main")).toString();
        QString des = (temp.value("description")).toString();
        QString icon = (temp.value("icon")).toString();

        qDebug()<<"ID:"<<id<<", Main:"<<main<<", Description"<<des<<", Icon:"<<icon;
    }


    emit(dataReadyRead(myData));
}

