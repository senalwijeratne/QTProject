#ifndef WEATHERAPP_H
#define WEATHERAPP_H

#include <QWidget>

namespace Ui {
class WeatherApp;
}

class WeatherApp : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherApp(QWidget *parent = 0);
    ~WeatherApp();

private:
    Ui::WeatherApp *ui;
};

#endif // WEATHERAPP_H
