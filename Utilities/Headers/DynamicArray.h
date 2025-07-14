//
// Created by benja on 13.07.2025.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>
#include "Exceptions.h"

namespace DSLib {

template<typename T> class DynamicArray {
protected:
    // DATA MEMBER(S):
    T* ptrArray;
    int arraySize;
    int arrayCapacity;

    // PRIVATE FUNCTION MEMBER(S):
    void resize(const int newCapacity) {
        std::cout << "resize" << std::endl;
        T* newArray = new T[newCapacity];
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = ptrArray[i];
        }
        ptrArray = newArray;
        arrayCapacity = newCapacity;
    }

public:
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    DynamicArray() {
        ptrArray = new T[0];
        arraySize = 0;
        arrayCapacity = 0;
    }

    DynamicArray(const DynamicArray<T>& otherDynamicArray) {
        ptrArray = new T[otherDynamicArray.size];
        arraySize = otherDynamicArray.size;
        arrayCapacity = otherDynamicArray.capacity;
        for (int i = 0; i < arraySize; i++) {
            ptrArray[i] = otherDynamicArray.ptrArray[i];
        }
    }

    DynamicArray(const int capacity) {
        ptrArray = new T[capacity];
        this->arrayCapacity = capacity;
        arraySize = 0;
    }

    ~DynamicArray() {
        delete[] ptrArray;
    }

    // PUBLIC FUNCTION MEMBER(S):
    virtual void insert(const int index, T value) {
        if (index < 0) {
            throw std::invalid_argument("index cannot be negative");
        }else {
            if (arraySize == arrayCapacity) {
                resize(std::max(1, arrayCapacity * 2));
            }
            if (index == arraySize) {
                ptrArray[index] = value;
            }else {
                for (int i = arraySize; i > index; i--) {
                    ptrArray[i] = ptrArray[i - 1];
                }
                ptrArray[index] = value;
            }
            arraySize++;
        }
    }

    virtual T remove(const int index) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("index out of range");
        }else {
            T toReturn = ptrArray[index];
            for (int i = index; i < arraySize; i++) {
                ptrArray[i] = ptrArray[i + 1];
            }
            arraySize--;
            if (arraySize == arrayCapacity / 4) {
                resize(arrayCapacity/4);
            }
            return toReturn;
        }
    }

    void clear() {
        delete[] ptrArray;
        resize(0);
        arraySize = 0;
        arrayCapacity = 0;

    }

    // ENCAPSULATION METHOD(S):
    T get(const int index) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("");
        }else {
            return ptrArray[index];
        }
    }
    void set(const int index, const T value) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("");
        }else {
            ptrArray[index] = value;
        }
    }
    int size() {return this->arraySize;}
    int capacity() {return this->arrayCapacity;}
    DynamicArray<T> clone() {
        return DynamicArray<T>(ptrArray);
    }

};

} // DSLib

#endif //DYNAMICARRAY_H
