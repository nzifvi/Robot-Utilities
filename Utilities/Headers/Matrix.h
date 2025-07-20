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
        float* ptrArray = nullptr;
        int rows;
        int columns;

        // PRIVATE FUNCTION MEMBER(S):
        int index(int row, int column) const;

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        Matrix(const int rowSize, const int columnSize);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other);
        ~Matrix();

        // PUBLIC FUNCTION MEMBER(S):


        // ENCAPSULATION FUNCTION MEMBER(S):
        [[nodiscard]] inline int getRowAmount() const {return rows;}
        [[nodiscard]] inline int getColumnAmount() const {return columns;}
        [[nodiscard]] inline float get(const int rowIndex, const int colIndex) const {
            if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows || colIndex >= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to get an element (" + std::to_string(rowIndex) + "," + std::to_string(colIndex) + ")");
            }else {
                return ptrArray[index(rowIndex, colIndex)];
            }
        }
        inline void set(const int rowIndex, const int colIndex, const float value) const {
            if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows || colIndex >= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to set an element (" + std::to_string(rowIndex) + "," + std::to_string(colIndex) + ") in matrix");
            }else {
                ptrArray[index(rowIndex, colIndex)] = value;
            }
        }

        Matrix& operator=(Matrix&& other);
        Matrix& operator=(const Matrix& other);
    };

    Matrix operator+(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator-(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator*(Matrix& m1, Matrix& m2); // FULLY WORKS
    Matrix operator*(float f, Matrix& m1); // FULLY WORKS
    ::std::ostream& operator<<(std::ostream& os, const Matrix& m); // FULLY WORKS

} // MathLib

#endif //MATRIX_H
