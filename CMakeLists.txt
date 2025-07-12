cmake_minimum_required(VERSION 3.31)
project(RobotUtilities)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        RobotUtilities main.cpp
        main.cpp

        Utilities/Headers/Vector.h
        Utilities/Implementations/Vector.cpp

        Utilities/Implementations/LIDARCloud.cpp
        Utilities/Headers/LIDARCloud.h

        Utilities/Implementations/LIDARPoint.cpp
        Utilities/Headers/LIDARPoint.h

        Utilities/Headers/Exceptions.h

        Utilities/Implementations/DSAdapter.cpp
        Utilities/Headers/DSAdapter.h
        Engines/Implementations/MovementEngine.cpp
        Engines/Headers/MovementEngine.h
        Engines/Implementations/LIDAREngine.cpp
        Engines/Headers/LIDAREngine.h
        Engines/Implementations/CentralEngine.cpp
        Engines/Headers/CentralEngine.h
        Utilities/Implementations/Matrix.cpp
        Utilities/Headers/Matrix.h
)
