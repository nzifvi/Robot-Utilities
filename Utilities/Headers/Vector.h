//
// Created by benja on 10.07.2025.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
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
        Vector(const Vector& other);

        // PUBLIC FUNCTION MEMBER(S):
        float magnitude() const;
        float directionX() const;
        float directionY() const;
        float directionZ() const;

        // ENCAPSULATION FUNCTION MEMBER(S):
        float getXComponent() const;
        float getYComponent() const;
        float getZComponent() const;
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

    inline std::ostream& operator<<(std::ostream& os, Vector& v){
        return os << "[" << v.getXComponent() << ", " << v.getYComponent() << ", " << v.getZComponent() << "]^T";
    }

    inline float angleBetween(Vector& v1, Vector& v2) {
        //return std::acos(v1 * v2 / v1.magnitude() * v2.magnitude());
        return 0.0f;
    }
}

#endif //VECTOR_H
