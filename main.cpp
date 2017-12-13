#include "weatherapp.h"
#include <QApplication>

WeatherApp *MainScreen;

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    MainScreen = new WeatherApp();
    MainScreen->show();

    return prog.exec();
}
