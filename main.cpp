#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"
#include "LaplaceExpander.h"
#include "LIDAREngine.h"
#include "CentralEngine.h"
#include "MathLibAuxiliaryFunctions.h"

int main() {
    MathLib::Matrix matrix(3,3);
    matrix.set(0,0, 1);
    matrix.set(0,1,3);
    matrix.set(0,2, 4);
    matrix.set(1,0, 8);
    matrix.set(1,1,3);
    matrix.set(1,2, 1);
    matrix.set(2,0, 14);
    matrix.set(2,1, 3);
    matrix.set(2,2, 7);

    std::cout << matrix << std::endl;

    float det = determinant(matrix);
    std::cout << det;
}

int x = 4 + 2;