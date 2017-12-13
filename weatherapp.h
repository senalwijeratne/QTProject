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
#include "display.h"

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
    Display *dis;

private slots:
    void on_searchButton_clicked();

private:
    Ui::WeatherApp *ui;
};

#endif // WEATHERAPP_H
