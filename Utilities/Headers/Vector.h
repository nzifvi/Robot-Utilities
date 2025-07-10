//
// Created by benja on 10.07.2025.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

namespace MathLib {
    class Vector {
    private:
        float xComponent;
        float yComponent;
        float zComponent;
    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        Vector(const float x, const float y, const float z);

        // PUBLIC FUNCTION MEMBER(S):
        float magnitude();
        float directionX();
        float directionY();
        float directionZ();

        // ENCAPSULATION FUNCTION MEMBER(S):
        float getXComponent();
        float getYComponent();
        float getZComponent();
    };

    inline Vector operator+(Vector& v1, Vector& v2) {
        return Vector(
            v1.getXComponent() + v2.getXComponent(),
            v1.getYComponent() + v2.getYComponent(),
            v1.getZComponent() + v2.getZComponent()
        );
    }

    inline Vector operator-(Vector& v1, Vector& v2) {
        return Vector(
            v1.getXComponent() - v2.getXComponent(),
            v1.getYComponent() - v2.getYComponent(),
            v1.getZComponent() - v2.getZComponent()
        );
    }

    inline float operator*(Vector& v1, Vector& v2) {
        return  v1.getXComponent() * v2.getXComponent() + v1.getYComponent() * v2.getYComponent() + v1.getZComponent() * v2.getZComponent();
    }

    inline float angleBetween(Vector& v1, Vector& v2) {
        return std::acos(v1 * v2 / v1.magnitude() * v2.magnitude());
    }
}

#endif //VECTOR_H
