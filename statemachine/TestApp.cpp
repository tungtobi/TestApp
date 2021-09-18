
#include "TestApp.h"
#include <string.h>

/*! \file Implementation of the state machine 'TestApp'
*/


TestApp::TestApp():
    stateConfVectorPosition(0),
    iface(),
    iface_OCB(nullptr)
{
}

TestApp::~TestApp()
{
}


void TestApp::init()
{
    for (sc_ushort i = 0; i < maxOrthogonalStates; ++i)
    {
        stateConfVector[i] = TestApp_last_state;
    }

    stateConfVectorPosition = 0;
    clearInEvents();
    clearOutEvents();
}

void TestApp::enter()
{
    /* Default enter sequence for statechart TestApp */
    enseq_main_region_default();
}

void TestApp::exit()
{
    /* Default exit sequence for statechart TestApp */
    exseq_main_region();
}

sc_boolean TestApp::isActive() const
{
    return stateConfVector[0] != TestApp_last_state;
}

/*
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean TestApp::isFinal() const
{
    return false;
}

void TestApp::runCycle()
{
    clearOutEvents();

    for (stateConfVectorPosition = 0;
         stateConfVectorPosition < maxOrthogonalStates;
         stateConfVectorPosition++)
    {
        switch (stateConfVector[stateConfVectorPosition])
        {
            case main_region_IdleState :
                {
                    react_main_region_IdleState();
                    break;
                }

            case main_region_StartState :
                {
                    react_main_region_StartState();
                    break;
                }

            case main_region_StopState :
                {
                    react_main_region_StopState();
                    break;
                }

            default:
                break;
        }
    }

    clearInEvents();
}

void TestApp::clearInEvents()
{
    iface.ev_start_raised = false;
    iface.ev_stop_raised = false;
    iface.ev_reset_raised = false;
}

void TestApp::clearOutEvents()
{
}


sc_boolean TestApp::isStateActive(TestAppStates state) const
{
    switch (state)
    {
        case main_region_IdleState :
            return (sc_boolean)(stateConfVector[SCVI_MAIN_REGION_IDLESTATE] == main_region_IdleState
                               );

        case main_region_StartState :
            return (sc_boolean)(stateConfVector[SCVI_MAIN_REGION_STARTSTATE] == main_region_StartState
                               );

        case main_region_StopState :
            return (sc_boolean)(stateConfVector[SCVI_MAIN_REGION_STOPSTATE] == main_region_StopState
                               );

        default:
            return false;
    }
}

TestApp::DefaultSCI* TestApp::getDefaultSCI()
{
    return &iface;
}
/* Functions for event ev_start in interface DefaultSCI */
void TestApp::DefaultSCI::raise_ev_start()
{
    ev_start_raised = true;
}
void TestApp::raise_ev_start()
{
    iface.raise_ev_start();
}
/* Functions for event ev_stop in interface DefaultSCI */
void TestApp::DefaultSCI::raise_ev_stop()
{
    ev_stop_raised = true;
}
void TestApp::raise_ev_stop()
{
    iface.raise_ev_stop();
}
/* Functions for event ev_reset in interface DefaultSCI */
void TestApp::DefaultSCI::raise_ev_reset()
{
    ev_reset_raised = true;
}
void TestApp::raise_ev_reset()
{
    iface.raise_ev_reset();
}
void TestApp::setDefaultSCI_OCB(DefaultSCI_OCB* operationCallback)
{
    iface_OCB = operationCallback;
}

// implementations of all internal functions

sc_boolean TestApp::check_main_region_IdleState_tr0_tr0()
{
    return iface.ev_start_raised;
}

sc_boolean TestApp::check_main_region_StartState_tr0_tr0()
{
    return iface.ev_stop_raised;
}

sc_boolean TestApp::check_main_region_StopState_tr0_tr0()
{
    return iface.ev_reset_raised;
}

void TestApp::effect_main_region_IdleState_tr0()
{
    exseq_main_region_IdleState();
    enseq_main_region_StartState_default();
}

void TestApp::effect_main_region_StartState_tr0()
{
    exseq_main_region_StartState();
    enseq_main_region_StopState_default();
}

void TestApp::effect_main_region_StopState_tr0()
{
    exseq_main_region_StopState();
    enseq_main_region_IdleState_default();
}

/* Entry action for state 'IdleState'. */
void TestApp::enact_main_region_IdleState()
{
    /* Entry action for state 'IdleState'. */
    iface_OCB->cbGotoIdleState();
}

/* Entry action for state 'StartState'. */
void TestApp::enact_main_region_StartState()
{
    /* Entry action for state 'StartState'. */
    iface_OCB->cbGotoStartState();
}

/* Entry action for state 'StopState'. */
void TestApp::enact_main_region_StopState()
{
    /* Entry action for state 'StopState'. */
    iface_OCB->cbGotoStopState();
}

/* 'default' enter sequence for state IdleState */
void TestApp::enseq_main_region_IdleState_default()
{
    /* 'default' enter sequence for state IdleState */
    enact_main_region_IdleState();
    stateConfVector[0] = main_region_IdleState;
    stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state StartState */
void TestApp::enseq_main_region_StartState_default()
{
    /* 'default' enter sequence for state StartState */
    enact_main_region_StartState();
    stateConfVector[0] = main_region_StartState;
    stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state StopState */
void TestApp::enseq_main_region_StopState_default()
{
    /* 'default' enter sequence for state StopState */
    enact_main_region_StopState();
    stateConfVector[0] = main_region_StopState;
    stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
void TestApp::enseq_main_region_default()
{
    /* 'default' enter sequence for region main region */
    react_main_region__entry_Default();
}

/* Default exit sequence for state IdleState */
void TestApp::exseq_main_region_IdleState()
{
    /* Default exit sequence for state IdleState */
    stateConfVector[0] = TestApp_last_state;
    stateConfVectorPosition = 0;
}

/* Default exit sequence for state StartState */
void TestApp::exseq_main_region_StartState()
{
    /* Default exit sequence for state StartState */
    stateConfVector[0] = TestApp_last_state;
    stateConfVectorPosition = 0;
}

/* Default exit sequence for state StopState */
void TestApp::exseq_main_region_StopState()
{
    /* Default exit sequence for state StopState */
    stateConfVector[0] = TestApp_last_state;
    stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
void TestApp::exseq_main_region()
{
    /* Default exit sequence for region main region */
    /* Handle exit of all possible states (of TestApp.main_region) at position 0... */
    switch (stateConfVector[ 0 ])
    {
        case main_region_IdleState :
            {
                exseq_main_region_IdleState();
                break;
            }

        case main_region_StartState :
            {
                exseq_main_region_StartState();
                break;
            }

        case main_region_StopState :
            {
                exseq_main_region_StopState();
                break;
            }

        default:
            break;
    }
}

/* The reactions of state IdleState. */
void TestApp::react_main_region_IdleState()
{
    /* The reactions of state IdleState. */
    if (check_main_region_IdleState_tr0_tr0())
    {
        effect_main_region_IdleState_tr0();
    }
}

/* The reactions of state StartState. */
void TestApp::react_main_region_StartState()
{
    /* The reactions of state StartState. */
    if (check_main_region_StartState_tr0_tr0())
    {
        effect_main_region_StartState_tr0();
    }
}

/* The reactions of state StopState. */
void TestApp::react_main_region_StopState()
{
    /* The reactions of state StopState. */
    if (check_main_region_StopState_tr0_tr0())
    {
        effect_main_region_StopState_tr0();
    }
}

/* Default react sequence for initial entry  */
void TestApp::react_main_region__entry_Default()
{
    /* Default react sequence for initial entry  */
    enseq_main_region_IdleState_default();
}



