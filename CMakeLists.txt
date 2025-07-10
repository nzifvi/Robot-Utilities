cmake_minimum_required(VERSION 3.31)
project(RobotUtilities)

set(CMAKE_CXX_STANDARD 20)

add_executable(RobotUtilities main.cpp
        main.cpp
        Utilities/Headers/Vector.h
        Utilities/Implementations/LIDARCloud.cpp
        Utilities/Headers/LIDARCloud.h
        Utilities/Implementations/LIDARPoint.cpp
        Utilities/Headers/LIDARPoint.h)
