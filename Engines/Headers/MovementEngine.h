//
// Created by benja on 12.07.2025.
//

#ifndef MOVEMENTENGINE_H
#define MOVEMENTENGINE_H

#include "LIDARCloud.h"
#include "CentralEngine.h"

namespace EngineLib {

class MovementEngine {
private:
    // DATA MEMBER(S):
    InitialisationState* ptrMovementEngineInitState = nullptr;
    DSLib::LIDARCloud addressCloud;

    // PRIVATE FUNCTION MEMBER(S):

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    MovementEngine(const DSLib::LIDARCloud& addressCloud, InitialisationState& state);
    ~MovementEngine();

    // PUBLIC FUNCTION MEMBER(S):

    // ENCAPSULATION FUNCTION MEMBER(S)
};

} // Movement

#endif //MOVEMENTENGINE_H
