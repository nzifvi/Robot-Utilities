//
// Created by benja on 12.07.2025.
//

#ifndef CENTRALENGINE_H
#define CENTRALENGINE_H

#include "LIDAREngine.h"
#include "MovementEngine.h"

namespace EngineLib {

    enum class MovementEngineState {
        MOVING,
        STOPPED,
        SCANNING,
    };

    enum class InitialisationState {
        UNINITIALISED,
        INITIALISING,
        INITIALISED
    };

    class CentralEngine {
    private:
        //LIDAREngine* ptrLidarEngine = nullptr;
        //MovementEngine* ptrMovementEngine = nullptr;

        //InitialisationState* ptrMovementEngineInitialisationState = new InitialisationState{InitialisationState::UNINITIALISED};
        //InitialisationState* ptrLidarEngineInitialisationState = new InitialisationState{InitialisationState::UNINITIALISED};

        // PRIVATE FUNCTION MEMBER(S):

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        //CentralEngine();
        //~CentralEngine();

        // PUBLIC FUNCTION MEMBER(S)

        // ENCAPSULATION FUNCTION MEMBER(S)
        //InitialisationState checkMovementEngineInitialisationState(){return *ptrMovementEngineInitialisationState;}
        //InitialisationState checkLidarEngineInitialisationState(){return *ptrMovementEngineInitialisationState;}
    };

} // CentralEngineLib

#endif //CENTRALENGINE_H
