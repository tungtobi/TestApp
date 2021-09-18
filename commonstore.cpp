#include "commonstore.h"

CommonStore::~CommonStore()
{
}

void CommonStore::process(const QSharedPointer<vtx::flux::Action>& action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::ActionStart:
            {
                mStateMachine.raise_ev_start();
                mStateMachine.runCycle();
                break;
            }

        case ActionType::ActionStop:
            {
                mStateMachine.raise_ev_stop();
                mStateMachine.runCycle();
                break;
            }

        case ActionType::ActionReset:
            {
                mStateMachine.raise_ev_reset();
                mStateMachine.runCycle();
                break;
            }

        default:
            break;
    }
}

void CommonStore::cbGotoIdleState()
{
    emit stateIdle();
}

void CommonStore::cbGotoStartState()
{
    emit stateStart();
}

void CommonStore::cbGotoStopState()
{
    emit stateStop();
}

CommonStore::CommonStore()
{
    mStateMachine.setDefaultSCI_OCB(this);
    mStateMachine.init();
    mStateMachine.enter();
}
