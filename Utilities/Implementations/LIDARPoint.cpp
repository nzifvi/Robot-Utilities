#include "../Headers/LIDARPoint.h"

namespace DSLib {

    // CONSTRUCTOR(S) AND DESTRUCTOR(S):

    LIDARPoint::LIDARPoint() {
        x = 0;
        y = 0;
        z = 0;
        type = PointType::UNSCANNED;
        timeOfScan = 0;
    }

    LIDARPoint::LIDARPoint(int x, int y, int z, PointType type) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->type = type;
        timeOfScan = getCurrentTimeInSeconds();
    }

    // PRIVATE FUNCTION MEMBER(S):
    int LIDARPoint::getCurrentTimeInSeconds() {
        time_t now = time(nullptr);
        struct tm* timeNow = gmtime(&now);
        const int currentTimeInSeconds = timeNow->tm_sec + (timeNow->tm_min * 60) + (timeNow->tm_hour * 3600);
        delete timeNow;
        return currentTimeInSeconds;
    }

    // PUBLIC FUNCTION MEMBER(S):

    void LIDARPoint::updateTimeOfScan() {
        timeOfScan = getCurrentTimeInSeconds();
    }


}