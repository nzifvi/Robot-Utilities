//
// Created by benja on 12.07.2025.
//

#ifndef CENTRALENGINE_H
#define CENTRALENGINE_H

namespace CentralEngineLib {

#include "LIDAREngine.h"
#include "MovementEngine.h"

class CentralEngine {
private:
    LIDARLib::LIDAREngine* ptrLidarEngine = nullptr;
    MovementLib::MovementEngine* ptrMovementEngine = nullptr;
    // PRIVATE FUNCTION MEMBER(S):

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    CentralEngine();
    ~CentralEngine();

    // PUBLIC FUNCTION MEMBER(S)

    // ENCAPSULATION FUNCTION MEMBER(S)
};

} // CentralEngineLib

#endif //CENTRALENGINE_H
