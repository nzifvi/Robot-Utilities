//
// Created by benja on 12.07.2025.
//

#ifndef LIDARENGINE_H
#define LIDARENGINE_H

#include <iostream>
#include <cmath>
#include <cstddef>   // for std::size_t, might help mbstate_t indirectly
#include <wchar.h>   // explicitly brings mbstate_t, wint_t

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
