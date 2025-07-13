#include "../Headers/LIDARCloud.h"

#include <array>

namespace DSLib {

// CONSTRUCTOR(S) AND DESTRUCTOR(S)

LIDARCloud::LIDARCloud() {
    cloudSize = 300;
    voxelSize = 5;
    // Potentially move hard-coded variables to JSON config file? (do for ALL config variables?)

    standardisedCloudSize = cloudSize / voxelSize;
    int arraySize = standardisedCloudSize * standardisedCloudSize * standardisedCloudSize;
    ptrArray = new LIDARPoint[arraySize]();
    for (int z = 0; z < standardisedCloudSize; z++) {
        for (int y = 0; y < standardisedCloudSize; y++) {
            for (int x = 0; x < standardisedCloudSize; x++) {
                ptrArray[index(x, y, z)].setX(x);
                ptrArray[index(x, y, z)].setY(y);
                ptrArray[index(x, y, z)].setY(z);
                ptrArray[index(x, y, z)].setPointType(PointType::UNSCANNED);
            }
        }
    }
}

    LIDARCloud::~LIDARCloud() {
        delete[] ptrArray;
    }

// PRIVATE FUNCTION MEMBER(S)

    inline size_t LIDARCloud::index(int x, int y, int z) {
        return static_cast<size_t>((z * standardisedCloudSize * standardisedCloudSize) + (y * standardisedCloudSize) + x);
    }

    inline int LIDARCloud::getCurrentTimeInSeconds() {
        time_t now = time(nullptr);
        struct tm* timeNow = gmtime(&now);
        const int currentTimeInSeconds = timeNow->tm_sec + (timeNow->tm_min * 60) + (timeNow->tm_hour * 3600);
        delete timeNow;
        return currentTimeInSeconds;
    }

    inline int LIDARCloud::standardiseOrdinate(const float ordinate) {
        return static_cast<int>(ordinate / voxelSize);
    }

// PUBLIC FUNCTION MEMBER(S)

    void LIDARCloud::terminateExpiredPoints(const int currentTimeInSeconds) {
        for (int z = 0; z < standardisedCloudSize; z++) {
            for (int y = 0; y < standardisedCloudSize; y++) {
                for (int x = 0; x < standardisedCloudSize; x++) {
                    if (getCurrentTimeInSeconds() - ptrArray[index(x, y, z)].getTimeOfScan() >= 2) {
                    ptrArray[index(x, y, z)].setPointType(PointType::UNSCANNED);
                    ptrArray[index(x,y, z)].updateTimeOfScan();
                    }
                }
            }
        }
    }

    LIDARPoint LIDARCloud::midpoint() {
        return LIDARPoint(
            standardisedCloudSize / 2,
            standardisedCloudSize / 2,
            standardisedCloudSize / 2,
            PointType::UNSCANNED
            );
    }
}
