#include "weatherapp.h"
#include <QApplication>

WeatherApp * mainScreen;

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    mainScreen = new WeatherApp();
    mainScreen->show();

    return prog.exec();
}
