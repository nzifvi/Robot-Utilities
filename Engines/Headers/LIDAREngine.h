//
// Created by benja on 12.07.2025.
//

#ifndef LIDARENGINE_H
#define LIDARENGINE_H

#include "LIDARCloud.h"
#include "MovementEngine.h"
#include "CentralEngine.h"

namespace EngineLib {

class LIDAREngine {
private:
    // DATA MEMBER(S):
    InitialisationState* ptrLidarEngineInitState = nullptr;
    DSLib::LIDARCloud lidarCloud;

    // PRIVATE FUNCTION MEMBER(S):

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LIDAREngine(InitialisationState& state);
    ~LIDAREngine();

    // PUBLIC FUNCTION MEMBER(S):

    // ENCAPSULATION FUNCTION MEMBER(S):
    DSLib::LIDARCloud getCloud(){return lidarCloud;};
};

} // LIDARLib

#endif //LIDARENGINE_H
