//
// Created by benja on 12.07.2025.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>
#include "Exceptions.h"

namespace MathLib {

    class Matrix {
    private:
        // DATA MEMBER(S):
        float** ptrArray;
        int rows;
        int columns;

        // PRIVATE FUNCTION MEMBER(S):

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        Matrix(const int rowSize, const int columnSize);
        Matrix(Matrix& matrix);
        ~Matrix();

        // PUBLIC FUNCTION MEMBER(S):


        // ENCAPSULATION FUNCTION MEMBER(S):
        inline int getRowAmount() {return rows;}
        inline int getColumnAmount() {return columns;}
        inline float get(int rowIndex, int colIndex) {
            if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows || colIndex >= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to access an element (" + std::to_string(rowIndex) + "," + std::to_string(colIndex) + ")");
            }else {
                return ptrArray[rowIndex][colIndex];
            }
        }
        inline void set(int rowIndex, int colIndex, float value) {
            if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows || colIndex >= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to access an element (" + std::to_string(rowIndex) + "," + std::to_string(colIndex) + ")");
            }else {
                ptrArray[rowIndex][colIndex] = value;
            }
        }
    };

    Matrix operator+(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator-(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator*(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator*(float f, Matrix& m1); // FULLY WORKS
    ::std::ostream& operator<<(std::ostream& os, Matrix& m); // FULLY WORKS

    void transpose(Matrix& m); // DOES NOT WORK, OVERWRITES
    float determinant(Matrix& m); // FULLY WORKS



} // MathLib

#endif //MATRIX_H
