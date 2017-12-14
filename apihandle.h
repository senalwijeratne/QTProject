#ifndef APIHANDLE_H
#define APIHANDLE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class ApiHandle : public QObject
{
    Q_OBJECT

public:
    explicit ApiHandle(QObject *parent = nullptr);
    void makeRequest(QString endPointRequest);

signals:
    void dataReadyRead(QByteArray);

public slots:
    void dataRead(QNetworkReply *reply);

private:
    QNetworkAccessManager *NetManager = new QNetworkAccessManager(this);

};

#endif // APIHANDLE_H
