#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"
#include "LaplaceExpander.h"

int main() {
    MathLib::Matrix matrix(3,3);
    matrix.set(0,0, 1);
    matrix.set(0,1, 2);
    matrix.set(0,2, 7);
    matrix.set(1,0,3);
    matrix.set(1,1,4);
    matrix.set(1,2,12);
    matrix.set(2,0,13);
    matrix.set(2,1,1);
    matrix.set(2,2,0);


    std::cout << matrix << std::endl;


    MathLib::LaplaceExpander laplace(matrix);
    laplace.performLaplaceExpansion();

    return 0;
}
