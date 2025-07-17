# Robot Utilities Library

[![Build Status](fucked)]

Robot Utilities is a C++ library which provides multiple assets, and sublibraries, with the intention to provide planned motion of a chassis which uses wheels as it's method of locomotion.

## IMPORTANT NOTICE
Robot Utilities is intended to work using a Rasberry Pi with multiple cores (at least 4). Furthermore, it utilises pigpio library to set voltages through pins and communicate with another microcontroller which actually drives the motors of a given chassis.

## Features

## Subliraries

### MathLib
The MathLib library is a sublirary of Robot Utilities library. It's purpose is to provide multiple mathematical structures, such as matrices and vectors, and various operations associated with linear algebra and calculus. 

MathLib uses:
- MathLib is utilised by the [MovementEngine](####MovementEngine.h) class-type object to compute the shortest weighted path whilst accounting for clearance.
- MathLib is utilised by the [LIDAREngine](####LIDAREngine.h) class-type object to categorise points into multiple types: enabling planned motion for the chassis.



#### Vector.h

#### Matrix.h

#### LaplaceExpander.h

### DSLib

#### LIDARPoint.h

#### LIDARCloud.h

#### DynamicArray.h

### EngineLib

#### CentralEngine.h

#### MovementEngine.h

#### LIDAREngine.h
