//
// Created by benja on 12.07.2025.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

namespace MathLib {
    /*  TO DO LIST:
     *    1) Create 2 matrix data structures: a 2d and 3d one.
     *    2) Use a float or double datatype (whichever one requires less bits per var).
     *    3) Declare and define operator overloads for basic matrix operations plus printing.
     *    4) Declare and define functions (transpose, determinant (one for 2d, one for 3d)).
     */
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
        ~Matrix();

        // PUBLIC FUNCTION MEMBER(S):


        // ENCAPSULATION FUNCTION MEMBER(S):
        inline int getRowAmount() {return rows;}
        inline int getColumnAmount() {return columns;}
        inline float get(int i, int j) {
            if (i < 0 || j < 0 || i>= rows || j>= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to access an element (" + std::to_string(i) + "," + std::to_string(j) + ")");
            }else {
                return ptrArray[i][j];
            }
        }
        inline void set(int i, int j, float value) {
            if (i < 0 || j < 0 || i >= rows || j>= columns) {
                throw std::out_of_range("Non-existent index used in an attempt to access an element (" + std::to_string(i) + "," + std::to_string(j) + ")");
            }else {
                ptrArray[j][i] = value;
            }
        }
    };

    Matrix operator+(Matrix& m1, Matrix& m2);
    Matrix operator-(Matrix& m1, Matrix& m2);
    Matrix operator*(Matrix& m1, Matrix& m2);
    Matrix operator*(float f, Matrix& m1);


    Matrix transpose(Matrix& m);
    Matrix transpose(Matrix& m);

    float determinant(Matrix& m);

    ::std::ostream& operator<<(std::ostream& os, Matrix& m);


} // MathLib

#endif //MATRIX_H
