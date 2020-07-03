#include "application.h"

int main(int argc, char *argv[])
{
    // 1. Сделать экран заставки
    Application app(argc, argv, "fin-app");
    return app.CreateGui("qrc:/gui/main.qml")
            .CreateCore()
            .Run();
}
