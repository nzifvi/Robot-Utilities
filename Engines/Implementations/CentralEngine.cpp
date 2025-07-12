//
// Created by benja on 12.07.2025.
//

#include "../Headers/CentralEngine.h"

namespace CentralEngineLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):

    CentralEngine::CentralEngine() {
        ptrLidarEngine = new LIDARLib::LIDAREngine();
        ptrMovementEngine = new MovementLib::MovementEngine(ptrLidarEngine->getCloudAddress());
    }

    CentralEngine::~CentralEngine() {
        delete ptrLidarEngine;
        delete ptrMovementEngine;
    }
} // CentralEngineLib