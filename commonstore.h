#ifndef COMMONSTORE_H
#define COMMONSTORE_H
#include "flux/action.h"
#include "flux/store.h"
#include "action/actiontype.h"
#include "statemachine/StatemachineInterface.h"
#include "statemachine/TestApp.h"

class CommonStore: public QObject, public vtx::flux::Store, public TestApp::DefaultSCI_OCB
{
        Q_OBJECT
    public:
        ~CommonStore() override;
        static CommonStore& getInstance()
        {
            static CommonStore self;
            return self;
        }

        void process(const QSharedPointer<vtx::flux::Action>& action) override;

        void cbGotoIdleState() override;

        void cbGotoStartState() override;

        void cbGotoStopState() override;

    signals:
        void stateIdle();
        void stateStart();
        void stateStop();
    private:
        CommonStore();
        TestApp mStateMachine;
};

#endif // COMMONSTORE_H
