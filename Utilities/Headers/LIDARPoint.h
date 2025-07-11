//
// Created by benja on 10.07.2025.
//

#ifndef LIDARPOINT_H
#define LIDARPOINT_H

#include <ctime>

namespace DSLib {
    class LIDARPoint {
    private:
        int  timeOfScan;
        int  x;
        int  y;
        int  z;
        char pointType;

        // PRIVATE FUNCTION MEMBER(S):
        int getCurrentTimeInSeconds();

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LIDARPoint();
        LIDARPoint(int x, int y, int z, char pointType);

        // PUBLIC FUNCTION MEMBER(S):
        void updateTimeOfScan();

        // ENCAPSULATION FUNCTION MEMBER(S):
        constexpr inline int getX() {return x;}
        constexpr inline int getY() {return y;}
        constexpr inline int getZ() {return z;}
        constexpr inline char getPointType() {return pointType;}
        constexpr inline int getTimeOfScan() {return timeOfScan;}
        inline void setX(const int x) {this->x = x;}
        inline void setY(const int y) {this->y = y;}
        inline void setZ(const int z) {this->z = z;}
        inline void setPointType(const char pointType) {this->pointType = pointType;}
    };
}




#endif //LIDARPOINT_H
