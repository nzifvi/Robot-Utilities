//
// Created by benja on 10.07.2025.
//

#ifndef LIDARPOINT_H
#define LIDARPOINT_H

#include <ctime>
#include <iostream>
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
        inline int getX() const {return x;}
        inline int getY() const {return y;}
        inline int getZ() const {return z;}
        inline char getPointType() const {return pointType;}
        inline int getTimeOfScan() const {return timeOfScan;}
        inline void setX(const int x) {this->x = x;}
        inline void setY(const int y) {this->y = y;}
        inline void setZ(const int z) {this->z = z;}
        inline void setPointType(const char pointType) {this->pointType = pointType;}
    };

    inline std::ostream& operator<<(std::ostream& os, const LIDARPoint& point) {
        return os << "(x:" << point.getX() << ", y:" << point.getY() << ", z:" << point.getZ() << ")";
    }
}

#endif //LIDARPOINT_H
