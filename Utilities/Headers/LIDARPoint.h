//
// Created by benja on 10.07.2025.
//

#ifndef LIDARPOINT_H
#define LIDARPOINT_H

namespace DSLib {
    class LIDARPoint {
    private:
        const int  timeToLive = 2;
              int  x;
              int  y;
              int  z;
              char pointType;
    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LIDARPoint(int x, int y, int z, char pointType);

        // PUBLIC FUNCTION MEMBER(S):

        // ENCAPSULATION FUNCTION MEMBER(S):
        int getX();
        int getY();
        int getZ();
        char getPointType();
        char setPointType(char pointType);
    };
}




#endif //LIDARPOINT_H
