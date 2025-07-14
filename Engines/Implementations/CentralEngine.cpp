//
// Created by benja on 12.07.2025.
//

#include "../Headers/CentralEngine.h"

namespace EngineLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    CentralEngine::CentralEngine() {
        ptrLidarEngine = new LIDAREngine(ptrLidarEngineInitialisationState);
        ptrMovementEngine = new MovementEngine(ptrLidarEngine->getCloud(), ptrMovementEngineInitialisationState);
    }

    CentralEngine::~CentralEngine() {

    }
} // CentralEngineLib