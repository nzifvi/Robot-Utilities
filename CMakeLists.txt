cmake_minimum_required(VERSION 3.31)
project(RobotUtilities)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
    "Engines/Implementations/*.cpp"
    "Utilities/Implementations/*.cpp"
    "main.cpp"
)

add_executable(
        RobotUtilities ${SOURCES}
)

target_include_directories(RobotUtilities PRIVATE
        ${CMAKE_SOURCE_DIR}/Engines/Headers
        ${CMAKE_SOURCE_DIR}/Utilities/Headers
)