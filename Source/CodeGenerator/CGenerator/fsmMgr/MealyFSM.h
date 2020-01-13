#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef UNIT_TEST
#define LIB_STATIC
#else
#define LIB_STATIC static
#endif

#define MAX_FSM_NUMBER  10U

typedef void (*TransitionFunction) ( void );

typedef struct{
    TransitionFunction pTransFunc;
    uint8_t nextState;
    bool isTransitionValid;
}Transition_t;

typedef struct{
    void* tableEntry;
    size_t tableLineSize;
    size_t currentCondition;
    size_t currentState;
    size_t defaultCondition;
    size_t defaultState;
}FSM_t;

FSM_t* M_FSM_New( void* table, 
                  size_t tableLineSize,
                  size_t startState,
                  size_t startCondition,
                  size_t defaultState,
                  size_t defaultCondition );

void M_FSM_Tick( FSM_t* self );
void FSM_UpdateCondition( FSM_t* self, size_t newCondition );
