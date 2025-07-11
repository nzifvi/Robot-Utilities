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
            terminalPoint.getX() - originPoint.getX(),
            terminalPoint.getY() - originPoint.getY(),
            terminalPoint.getZ() - originPoint.getZ()
            );
    }

    static MathLib::Vector LIDARPointToVector(LIDARPoint& originPoint, int xOrigin, int yOrigin, int zOrigin) {
        return MathLib::Vector(
            originPoint.getX() - xOrigin,
            originPoint.getY() - yOrigin,
            originPoint.getZ() - zOrigin
            );
    }
};

} // DSLib

#endif //DSADAPTER_H
