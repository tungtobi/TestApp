#include "actionprovider.h"
#include "flux/action.h"
#include "flux/dispatcher.h"
#include "actionprovider.h"
#include "actiontype.h"

ActionProvider ActionProvider::mInstance;

ActionProvider* ActionProvider::getInstance()
{
    return &(ActionProvider::mInstance);
}

void ActionProvider::startApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionStart, QVariant()));
}

void ActionProvider::stopApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionStop, QVariant()));
}

void ActionProvider::resetApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionReset, QVariant()));
}

void ActionProvider::exitApplication()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ExitApplication, QVariant()));
}

inline int sum(int a, int b) {
    return a + b;
}
