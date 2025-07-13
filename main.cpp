#include <iostream>
#include "LIDARCloud.h"
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"

int main() {
    DSLib::DynamicArray<int> array{};
    for (int i = 0; i < 10; i++) {
        array.insert(0, i);
    }

    for (int i = 0; i < array.size(); i++) {
        std::cout << array.get(i) << ", ";
    }

    std::cout << std::endl;
    array.insert(4,10);

    for (int i = 0; i < array.size(); i++) {
        std::cout << array.get(i) << ", ";
    }

    array.remove(3);

    return 0;
}
