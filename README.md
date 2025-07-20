# Robot Utilities Library

[![Build Status](fucked)]

Robot Utilities is a C++ library which provides multiple assets, and sublibraries, with the intention to provide planned motion of a chassis which uses wheels as it's method of locomotion.

## IMPORTANT NOTICES
Robot Utilities is STRICTLY for use with a Rasberry Pi with multiple cores (at least 4). Furthermore, it utilises pigpio library to set voltages through pins and communicate with another microcontroller which actually drives the motors of a given chassis.

Furthermore, a sensor which has some method of computing 3D points in space is required.

## Features

## Subliraries

### MathLib
The MathLib library is a sublirary of Robot Utilities library. It's purpose is to provide multiple mathematical structures, such as matrices and vectors, and various operations associated with linear algebra and calculus. 

MathLib uses:
- MathLib is utilised by the [MovementEngine](####MovementEngine.h) class-type object to compute the shortest weighted path whilst accounting for clearance.
- MathLib is utilised by the [LIDAREngine](####LIDAREngine.h) class-type object to categorise points into multiple types: enabling planned motion for the chassis.

#### Vector.h
Vector is a class-type object which represents a vector of variable dimensions (1xN). By default, the dimensions of a Vector class-type object will be 1x3. This can be modified by providing an integer argument. A typical use of this might be to create a pose vector which also stores angle data.

Vector data members, which are rectangular components of a vector, are stored as floats to permit a high degree of accuracy.

##### Vector.h Function Members
`Vector(float x, float y, float z)`
- Constructor which allows for a Vector class-type object to be initialised

`Vector(Vector other)`
- Constructor which allows for a deep copy of another Vector class-type object to be initialised. Post copy, both Vector class-type objects will have independent memory for their data members.

`float magnitude()`
- Public function member which returns the magnitude of a Vector class-type object, given that all data members have been initialised.

`float directionX()`
- Public function member which returns the angle between the vector and the x-axis.

`float directionY()`
- Public function member which returns the angle between the vector and the y-axis.

`float directionZ()`
- Public function member which returns the angle between the vector and the z-axis.

`float getXComponent()`
- Encapsulation function member returning the assigned x rectangular component that was assigned.

`float getYComponent()`
- Encapsulation function member returning the assigned y rectangular component that was assigned.

`float getZComponent()`
- Encapsulation function member returning the assigned z rectangular component that was assigned.

#### Vector.h Auxiliary Functions

`angleBetween(Vector& v1, Vector v2&)`
- Auxiliary function which returns the angle between 2 vectors given as arguments in the function call.

#### Matrix.h
Matrix is a class-type object which provides a program representation of a Matrix. It can be assigned a variable amount of rows and columns. 

No default constructor exists. The number of rows and columns to assign a Matrix class-type object must be given as arguments during initialisation.

#### Matrix.h function members

#### LaplaceExpander.h

### DSLib

#### LIDARPoint.h

#### LIDARCloud.h

#### DynamicArray.h

### EngineLib

#### CentralEngine.h

#### MovementEngine.h

#### LIDAREngine.h
