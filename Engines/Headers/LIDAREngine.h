//
// Created by benja on 12.07.2025.
//

#ifndef LIDARENGINE_H
#define LIDARENGINE_H

namespace LIDARLib {

#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/Vector.h"
#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/LIDARCloud.h"
#include "C:/Users/benja/CLionProjects/Robot-Utilities/Utilities/Headers/LIDARPoint.h"

class LIDAREngine {
private:
    // DATA MEMBER(S):
    DSLib::LIDARCloud* ptrCloud;

    // PRIVATE FUNCTION MEMBER(S):

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LIDAREngine();
    ~LIDAREngine();

    // PUBLIC FUNCTION MEMBER(S):

    // ENCAPSULATION FUNCTION MEMBER(S):
    DSLib::LIDARCloud* getCloudAddress();
};

} // LIDARLib

#endif //LIDARENGINE_H
