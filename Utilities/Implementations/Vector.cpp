#include "../Headers/Vector.h"

namespace MathLib {

    // VECTOR::VECTOR FUNCTION MEMBER DEFINITIONS |------------------------------------------------------------------------

    //  ->  VECTOR::VECTOR CONSTRUCTOR(S) AND DESTRUCTOR(S):
    Vector::Vector(const float x, const float y, const float z):
    xComponent(x),
    yComponent(y),
    zComponent(z){

    }

    Vector::Vector(const Vector& other):
    xComponent(other.xComponent),
    yComponent(other.yComponent),
    zComponent(other.zComponent){

    }


    //  ->  VECTOR::VECTOR PUBLIC FUNCTION MEMBER(S):

    float Vector::magnitude() const {
        return sqrtf(xComponent*xComponent+yComponent*yComponent+zComponent*zComponent);
    }

    float Vector::directionX() const {
        return xComponent / magnitude();
    }

    float Vector::directionY() const {
        return yComponent / magnitude();
    }

    float Vector::directionZ() const {
        return zComponent / magnitude();
    }

    //  ->  VECTOR::VECTOR ENCAPSULATION FUNCTION MEMBER(S):

    float Vector::getXComponent() const {
        return this->xComponent;
    }

    float Vector::getYComponent() const {
        return this->yComponent;
    }

    float Vector::getZComponent() const {
        return this->zComponent;
    }

}
