//
// Created by benja on 10.07.2025.
//

#ifndef LIDARCLOUD_H
#define LIDARCLOUD_H

#include <exception>
#include "LIDARPoint.h"

namespace DSLib {
    class LIDARCloud {
    private:
        const int   stdSize   = 300;
        const int   voxelSize = 5;
        LIDARPoint* ptrArray  = new LIDARPoint[(stdSize / voxelSize) * (stdSize / voxelSize) * (stdSize / voxelSize)]();

        // PRIVATE FUNCTION MEMBER(S):
        int index(int x, int y, int z);

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LIDARCloud();
        ~LIDARCloud();

        // PUBLIC FUNCTION MEMBER(S):
        void terminateExpiredPoints();

        // ENCAPSULATION METHODS:
        LIDARPoint get(int x, int y, int z);
        void set(int x, int y, int z, char pointSymbol);
    };
}




#endif //LIDARCLOUD_H
