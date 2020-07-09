#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <memory>
#include <utility>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

class Application
{
public:
    Application(int &argc, char **argv, const std::string &name);

    int Run();

    Application& CreateGui(std::string path);
    Application& CreateCore();
private:
    std::unique_ptr<QGuiApplication> app_;
    std::unique_ptr<QQmlApplicationEngine> engine_;

    static QGuiApplication *Create(int &argc, char **argv, const std::string &name);
};

#endif // APPLICATION_H
