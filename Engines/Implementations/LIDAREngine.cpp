//
// Created by benja on 12.07.2025.
//

#include "../Headers/LIDAREngine.h"

namespace EngineLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LIDAREngine::LIDAREngine(InitialisationState& state) {
        lidarCloud = DSLib::LIDARCloud();
        ptrLidarEngineInitState = &state;
        *ptrLidarEngineInitState = InitialisationState{InitialisationState::INITIALISING};
    }

    LIDAREngine::~LIDAREngine() {

    }


    // PRIVATE FUNCTION MEMBER(S):

    // PUBLIC FUNCTION MEMBER(S):

    // AUXILIARY FUNCTIONS AND GENERAL FUNCTION(S):
} // LIDARLib