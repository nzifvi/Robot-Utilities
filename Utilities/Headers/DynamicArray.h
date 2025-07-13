//
// Created by benja on 13.07.2025.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>
#include "Exceptions.h"

namespace DSLib {

template<typename T> class DynamicArray {
private:
    // DATA MEMBER(S):
    T* ptrArray;
    int arraySize;
    int arrayCapacity;

    // PRIVATE FUNCTION MEMBER(S):
    void resize(const int newCapacity) {
        T* newArray = new T[newCapacity];
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = ptrArray[i];
        }
        arrayCapacity = newCapacity;
        ptrArray = newArray;
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
    void insert(const int index, T value) {
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

    T remove(const int index) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("index out of range");
        }else {
            throw case_not_yet_implemented();
        }
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

};

} // DSLib

#endif //DYNAMICARRAY_H
