#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"
#include "LaplaceExpander.h"
#include "LIDAREngine.h"
#include "CentralEngine.h"

int main() {
    CentralEngineLib::CentralEngine centralEngine;
    if (centralEngine.checkLidarEngineInitialisationState() == CentralEngineLib::InitialisationState::INITIALISING) {
        return 1;
    }else {
        return 0;
    }
    return 0;
}
