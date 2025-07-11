#include "../Headers/LIDARCloud.h"

// CONSTRUCTOR(S) AND DESTRUCTOR(S)

DSLib::LIDARCloud::LIDARCloud() {

}

DSLib::LIDARCloud::~LIDARCloud() {
    delete[] ptrArray;
}

// PRIVATE FUNCTION MEMBER(S)

int DSLib::LIDARCloud::index(int x, int y, int z) {

}

// PUBLIC FUNCTION MEMBER(S)

// ENCAPSULATION FUNCTION MEMBER(S)

DSLib::LIDARPoint DSLib::LIDARCloud::get(int x, int y, int z) {

}

void DSLib::LIDARCloud::set(int x, int y, int z, char pointSymbol) {
    ptrArray[index(x, y, z)].
}



