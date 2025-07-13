#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"

int main() {
    MathLib::Matrix matrix1(2,2);
    matrix1.set(0, 0, 1.0f);
    matrix1.set(0, 1, 9.0f);
    matrix1.set(1, 0, 2.0f);
    matrix1.set(1, 1, 9.0f);

    MathLib::Matrix matrix2(2,2);
    matrix2.set(0, 0, 1.0f);
    matrix2.set(0, 1, 1.0f);
    matrix2.set(1, 0, 1.0f);
    matrix2.set(1,1, 1.0f);

    std::cout << matrix2 << std::endl;

    return 0;
}
