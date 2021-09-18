/******************************
*
*    Copyright (C) 2021 VTX
*    File name: %{Cpp:License:FileName}
*    Author: phuongdm10@viettel.com.vn
*    Created: 8/10/2021
*
*******************************/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "action/actionprovider.h"
#include "commonstore.h"
#include "flux/dispatcher.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<ActionProvider>("Flux", 1, 0, "ActionProvider",
                                             [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(ActionProvider::getInstance(), QQmlEngine::CppOwnership);
        return ActionProvider::getInstance();
    });
    qmlRegisterSingletonType<CommonStore>("Flux", 1, 0, "CommonStore",
                                          [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(&CommonStore::getInstance(), QQmlEngine::CppOwnership);
        return &CommonStore::getInstance();
    });
    vtx::flux::Dispatcher::instance().registerStore(QSharedPointer<vtx::flux::Store>(&CommonStore::getInstance(), [](vtx::flux::Store*) {}));
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject * obj, const QUrl & objUrl)
    {
        if (!obj && url == objUrl)
        {
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
