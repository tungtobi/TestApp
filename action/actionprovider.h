#ifndef ACTIONPROVIDER1_H
#define ACTIONPROVIDER1_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QUrl>
#include <QStringList>
class ActionProvider final : public QObject
{

        Q_OBJECT
    public:
        static ActionProvider* getInstance();

        Q_INVOKABLE void startApp();
        Q_INVOKABLE void stopApp();
        Q_INVOKABLE void resetApp();
        Q_INVOKABLE void exitApplication();

    private:
        static ActionProvider mInstance;
        ActionProvider() = default;
        ActionProvider(const ActionProvider&) = delete;
        ActionProvider(ActionProvider&&) = delete;
        ActionProvider& operator=(const ActionProvider&) = delete;
        ActionProvider& operator=(ActionProvider &&) = delete;
        ~ActionProvider() = default;
};

#endif // ACTIONPROVIDER_H
