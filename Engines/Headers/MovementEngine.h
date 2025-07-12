//
// Created by benja on 12.07.2025.
//

#ifndef MOVEMENTENGINE_H
#define MOVEMENTENGINE_H

#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/Vector.h"
#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/LIDARCloud.h"
#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/LIDARPoint.h"

namespace MovementLib {

class MovementEngine {
private:
    // DATA MEMBER(S):
    DSLib::LIDARCloud& addressCloud;

    // PRIVATE FUNCTION MEMBER(S):

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    MovementEngine(const DSLib::LIDARCloud& _addressCloud);
    ~MovementEngine();

    // PUBLIC FUNCTION MEMBER(S):

    // ENCAPSULATION FUNCTION MEMBER(S)
};

} // Movement

#endif //MOVEMENTENGINE_H
