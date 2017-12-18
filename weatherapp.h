#ifndef WEATHERAPP_H
#define WEATHERAPP_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QCompleter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QUrl>
#include <QDebug>
#include "apihandle.h"

namespace Ui {
class WeatherApp;
}

class WeatherApp : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherApp(QWidget *parent = 0);
    ~WeatherApp();
    void setBG();
    void setAutoComp();
    void dataInDaHouse(QByteArray data);
    void setWeatherValues(qreal lon, qreal lat, qint32 weather_id, QString main, QString des, QString icon, qint32 temp, qint32 pres, qint32 humi, qint32 temp_max, qint32 temp_min, qreal speed, qreal deg, qint32 type, qint32 sys_id, qreal message, QString country, qint32 sunrise, qint32 sunset);

private slots:
    void on_searchButton_clicked();

private:
    Ui::WeatherApp *ui;
    ApiHandle api;
};

#endif // WEATHERAPP_H
