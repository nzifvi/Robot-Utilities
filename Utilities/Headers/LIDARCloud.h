//
// Created by benja on 10.07.2025.
//

#ifndef LIDARCLOUD_H
#define LIDARCLOUD_H

#include <stdexcept>
#include "LIDARPoint.h"
#include <ctime>

namespace DSLib {

    class LIDARCloud {
    private:
        int cloudSize;
        int voxelSize;
        int standardisedCloudSize;

        LIDARPoint* ptrArray;
        int arraySize;

        // PRIVATE FUNCTION MEMBER(S):
               size_t index(int x, int y, int z);
        inline int getCurrentTimeInSeconds();
        inline int standardiseOrdinate(const float ordinate);
    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LIDARCloud();
        ~LIDARCloud();

        // PUBLIC FUNCTION MEMBER(S):
        void terminateExpiredPoints(const int currentTimeInSeconds);

        LIDARPoint midpoint();

        // ENCAPSULATION METHODS:
        inline LIDARPoint get(const int x, const int y, const int z) {
            if (index(x,y,z) < 0 || x > standardisedCloudSize || y > standardisedCloudSize || z > standardisedCloudSize) {
                throw ::std::out_of_range("Attempt to access out of bounds index occurred");
            }else {
                return ptrArray[index(x, y, z)];
            }
        }

        inline void set(const int x, const int y, const int z, const PointType type) {
            if (index(x,y,z) < 0 || x > standardisedCloudSize || y > standardisedCloudSize || z > standardisedCloudSize) {
                throw ::std::out_of_range("Attempt to access out of bounds index occurred");
            }else {
                ptrArray[index(x,y,z)] = DSLib::LIDARPoint(x, y, z, type);
            }
        }
    };
}




#endif //LIDARCLOUD_H
