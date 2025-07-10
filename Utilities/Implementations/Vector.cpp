#include "../Headers/Vector.h"

// VECTOR::VECTOR FUNCTION MEMBER DEFINITIONS |------------------------------------------------------------------------

//  ->  VECTOR::VECTOR CONSTRUCTOR(S) AND DESTRUCTOR(S):
MathLib::Vector::Vector(const float x, const float y, const float z) {
    this->xComponent = x;
    this->yComponent = y;
    this->zComponent = z;
}

//  ->  VECTOR::VECTOR PUBLIC FUNCTION MEMBER(S):

float MathLib::Vector::magnitude() {
    return sqrtf(xComponent*xComponent+yComponent*yComponent+zComponent*zComponent);
}

float MathLib::Vector::directionX() {
    return xComponent / magnitude();
}

float MathLib::Vector::directionY() {
    return yComponent / magnitude();
}

float MathLib::Vector::directionZ() {
    return zComponent / magnitude();
}

//  ->  VECTOR::VECTOR ENCAPSULATION FUNCTION MEMBER(S):

float MathLib::Vector::getXComponent() {
    return this->xComponent;
}

float MathLib::Vector::getYComponent() {
    return this->yComponent;
}

float MathLib::Vector::getZComponent() {
    return this->zComponent;
}