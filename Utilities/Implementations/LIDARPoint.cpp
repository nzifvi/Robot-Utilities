#include "../Headers/LIDARPoint.h"

// CONSTRUCTOR(S) AND DESTRUCTOR(S):
DSLib::LIDARPoint::LIDARPoint(int x, int y, int z, char pointType) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->pointType = pointType;
}

// PUBLIC FUNCTION MEMBER(S):

// ENCAPSULATION FUNCTION MEMBER(S):
int DSLib::LIDARPoint::getX() {
    return x;
}

int DSLib::LIDARPoint::getY() {
    return y;
}

int DSLib::LIDARPoint::getZ() {
    return z;
}

char DSLib::LIDARPoint::getPointType() {
    return pointType;
}

char DSLib::LIDARPoint::setPointType(char pointType) {
    this->pointType = pointType;
}