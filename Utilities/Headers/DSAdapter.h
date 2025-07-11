//
// Created by benja on 10.07.2025.
//

#ifndef DSADAPTER_H
#define DSADAPTER_H

#include "LIDARPoint.h"
#include "LIDARCloud.h"
#include "Vector.h"

namespace DSLib {

class DSAdapter {
public:
    static MathLib::Vector LIDARPointToVector(LIDARPoint& originPoint, LIDARPoint& terminalPoint) {
        return MathLib::Vector(
            static_cast<float>(terminalPoint.getX() - originPoint.getX()),
            static_cast<float>(terminalPoint.getY() - originPoint.getY()),
            static_cast<float>(terminalPoint.getZ() - originPoint.getZ())
            );
    }

    static MathLib::Vector LIDARPointToVector(LIDARPoint& originPoint, int xOrigin, int yOrigin, int zOrigin) {
        return MathLib::Vector(
            static_cast<float>(originPoint.getX() - xOrigin),
            static_cast<float>(originPoint.getY() - yOrigin),
            static_cast<float>(originPoint.getZ() - zOrigin)
            );
    }
};

} // DSLib

#endif //DSADAPTER_H
