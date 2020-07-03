#include "application.h"

#include <vector>

Application::Application(int &argc, char **argv, const std::string &name) : app_(Create(argc, argv,name)),
    engine_(std::make_unique<QQmlApplicationEngine>()) {
}

Application &Application::CreateGui(std::string path) {
    const QUrl url(path.c_str());
    QObject::connect(&*engine_, &QQmlApplicationEngine::objectCreated,
                     &*app_, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine_->load(url);
    return *this;
}

Application &Application::CreateCore() {

    return *this;
}

int Application::Run() {
    return app_->exec();
}

QGuiApplication *Application::Create(int &argc, char **argv, const std::string &name) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication *app = new QGuiApplication(argc, argv);
    return app;
}
