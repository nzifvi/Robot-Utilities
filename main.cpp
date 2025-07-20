#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"
#include "LaplaceExpander.h"
#include "LIDAREngine.h"
#include "CentralEngine.h"

int main() {
    MathLib::Matrix matrix(3,3);
    matrix.set(0,0, 1);
    matrix.set(0,1,3);
    matrix.set(0,2, 4);
    matrix.set(1,0, 8);
    matrix.set(1,1,12);
    matrix.set(1,2, -1);
    matrix.set(2,0, 14);
    matrix.set(2,1, 3);
    matrix.set(2,2, 7);

    MathLib::LaplaceExpander laplaceExpander(matrix);
    laplaceExpander.performLaplaceExpansion();
    MathLib::Matrix newMatrix = laplaceExpander.getLaplaceTerm(0);
    MathLib::Matrix newMatrix2 = laplaceExpander.getLaplaceTerm(1);
    MathLib::Matrix newMatrix3 = laplaceExpander.getLaplaceTerm(2);


    std::cout << matrix << std::endl;
    std::cout << newMatrix << std::endl;
    std::cout << newMatrix2 << std::endl;
    std::cout << newMatrix3 << std::endl;
}

int x = 4 + 2;