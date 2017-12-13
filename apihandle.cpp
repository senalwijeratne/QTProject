#include "apihandle.h"
#include <QDebug>

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
    QByteArray myData;
    myData = reply->readAll();
    qDebug()<<myData;
    emit(dataReadyRead(myData));
}

