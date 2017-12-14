#include "apihandle.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

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

    QJsonValue response = itemObject.value("coord");
    qDebug()<<"";
    qDebug()<<response;
    QJsonObject coordObject = response.toObject();
    qDebug()<<coordObject;

    QJsonValue lat = coordObject.value("lat");
    qDebug()<<lat;
    qreal l = lat.toDouble();
    qDebug()<<l;

    emit(dataReadyRead(myData));
}

