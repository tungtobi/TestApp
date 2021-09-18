
#ifndef TESTAPP_H_
#define TESTAPP_H_

#include "sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'TestApp'.
*/


/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_IDLESTATE 0
#define SCVI_MAIN_REGION_STARTSTATE 0
#define SCVI_MAIN_REGION_STOPSTATE 0

class TestApp : public StatemachineInterface
{
    public:

        TestApp();

        ~TestApp();

        /*! Enumeration of all states */
        typedef enum
        {
            TestApp_last_state,
            main_region_IdleState,
            main_region_StartState,
            main_region_StopState
        } TestAppStates;

        //! Inner class for default interface scope.
        class DefaultSCI
        {

            public:
                /*! Raises the in event 'ev_start' that is defined in the default interface scope. */
                void raise_ev_start();

                /*! Raises the in event 'ev_stop' that is defined in the default interface scope. */
                void raise_ev_stop();

                /*! Raises the in event 'ev_reset' that is defined in the default interface scope. */
                void raise_ev_reset();


            private:
                friend class TestApp;
                sc_boolean ev_start_raised;
                sc_boolean ev_stop_raised;
                sc_boolean ev_reset_raised;
        };
        //! Inner class for default interface scope operation callbacks.
        class DefaultSCI_OCB
        {
            public:
                virtual ~DefaultSCI_OCB() = 0;

                virtual void cbGotoIdleState() = 0;

                virtual void cbGotoStartState() = 0;

                virtual void cbGotoStopState() = 0;
        };

        /*! Set the working instance of the operation callback interface 'DefaultSCI_OCB'. */
        void setDefaultSCI_OCB(DefaultSCI_OCB* operationCallback);

        /*! Returns an instance of the interface class 'DefaultSCI'. */
        DefaultSCI* getDefaultSCI();

        /*! Raises the in event 'ev_start' that is defined in the default interface scope. */
        void raise_ev_start();

        /*! Raises the in event 'ev_stop' that is defined in the default interface scope. */
        void raise_ev_stop();

        /*! Raises the in event 'ev_reset' that is defined in the default interface scope. */
        void raise_ev_reset();


        /*
         * Functions inherited from StatemachineInterface
         */
        virtual void init();

        virtual void enter();

        virtual void exit();

        virtual void runCycle();

        /*!
        * Checks if the state machine is active (until 2.4.1 this method was used for states).
        * A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
        */
        virtual sc_boolean isActive() const;


        /*!
        * Checks if all active states are final.
        * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
        */
        virtual sc_boolean isFinal() const;


        /*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
        sc_boolean isStateActive(TestAppStates state) const;


    private:

        TestApp(const TestApp& rhs);

        TestApp& operator=(const TestApp&);


        //! the maximum number of orthogonal states defines the dimension of the state configuration vector.
        static const sc_ushort maxOrthogonalStates = 1;


        TestAppStates stateConfVector[maxOrthogonalStates];

        sc_ushort stateConfVectorPosition;

        DefaultSCI iface;
        DefaultSCI_OCB* iface_OCB;

        // prototypes of all internal functions

        sc_boolean check_main_region_IdleState_tr0_tr0();
        sc_boolean check_main_region_StartState_tr0_tr0();
        sc_boolean check_main_region_StopState_tr0_tr0();
        void effect_main_region_IdleState_tr0();
        void effect_main_region_StartState_tr0();
        void effect_main_region_StopState_tr0();
        void enact_main_region_IdleState();
        void enact_main_region_StartState();
        void enact_main_region_StopState();
        void enseq_main_region_IdleState_default();
        void enseq_main_region_StartState_default();
        void enseq_main_region_StopState_default();
        void enseq_main_region_default();
        void exseq_main_region_IdleState();
        void exseq_main_region_StartState();
        void exseq_main_region_StopState();
        void exseq_main_region();
        void react_main_region_IdleState();
        void react_main_region_StartState();
        void react_main_region_StopState();
        void react_main_region__entry_Default();
        void clearInEvents();
        void clearOutEvents();


};

inline TestApp::DefaultSCI_OCB::~DefaultSCI_OCB() {}


#endif /* TESTAPP_H_ */
