#include "../Headers/LIDARPoint.h"

// CONSTRUCTOR(S) AND DESTRUCTOR(S):

DSLib::LIDARPoint::LIDARPoint() {
    x = 0;
    y = 0;
    z = 0;
    pointType = '?';
    timeOfScan = 0;
}

DSLib::LIDARPoint::LIDARPoint(int x, int y, int z, char pointType) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->pointType = pointType;
    timeOfScan = getCurrentTimeInSeconds();
}

// PRIVATE FUNCTION MEMBER(S):
int DSLib::LIDARPoint::getCurrentTimeInSeconds() {
    time_t now = time(nullptr);
    struct tm* timeNow = gmtime(&now);
    const int currentTimeInSeconds = timeNow->tm_sec + (timeNow->tm_min * 60) + (timeNow->tm_hour * 3600);
    delete timeNow;
    return currentTimeInSeconds;
}

// PUBLIC FUNCTION MEMBER(S):

void DSLib::LIDARPoint::updateTimeOfScan() {
    timeOfScan = getCurrentTimeInSeconds();
}
