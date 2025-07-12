//
// Created by benja on 12.07.2025.
//

#ifndef MATRIX_H
#define MATRIX_H

namespace MathLib {
    /*  TO DO LIST:
     *    1) Create 2 matrix data structures: a 2d and 3d one.
     *    2) Use a float or double datatype (whichever one requires less bits per var).
     *    3) Declare and define operator overloads for basic matrix operations plus printing.
     *    4) Declare and define functions (transpose, determinant (one for 2d, one for 3d)).
     */
    class Matrix2D {
    private:
        // DATA MEMBER(S):
        float matrix[][];
        int iSize;
        int jSize;

        // PRIVATE FUNCTION MEMBER(S):
    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        Matrix2D(const int iSize, const int jSize);

        // PUBLIC FUNCTION MEMBER(S):

        // ENCAPSULATION FUNCTION MEMBER(S):
    };

    class Matrix3D {
    private:
        // DATA MEMBER(S):
        float matrix[][][];
        int iSize;
        int jSize;

        // PRIVATE FUNCTION MEMBER(S):

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        Matrix3D(const int iSize, const int jSize, const int kSize);

        // PUBLIC FUNCTION MEMBER(S):

        // ENCAPSULATION FUNCTION MEMBER(S):
    };

} // MathLib

#endif //MATRIX_H
