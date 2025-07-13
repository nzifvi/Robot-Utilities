//
// Created by benja on 12.07.2025.
//

#include "../Headers/Matrix.h"

namespace MathLib {

    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    Matrix::Matrix(const int rowSize, const int columnSize) {
        this->rows = rowSize;
        this->columns = columnSize;
        ptrArray = new float*[rows];
        for (int j = 0; j < columns; j++) {
            ptrArray[j] = new float[columns];
        }
    }

    Matrix::~Matrix() {
        for (int j = 0; j < columns; j++) {
            delete[] ptrArray[j];
        }
        delete[] ptrArray;
    }

    // PRIVATE FUNCTION MEMBER(S):

    // PUBLIC FUNCTION MEMBER(S):

    // AUXILIARY FUNCTION(S) AND GENERAL FUNCTION(S):
    Matrix operator+(Matrix& m1, Matrix& m2) {
        Matrix result = Matrix(m1.getRowAmount(), m1.getColumnAmount());
        for (int i = 0; i < m1.getRowAmount(); i++) {
            for (int j = 0; j < m1.getColumnAmount(); j++) {
                result.set(i, j, m1.get(i, j) + m2.get(i, j));
            }
        }
        return result;
    }

    Matrix operator-(Matrix& m1, Matrix& m2) {
        Matrix result = Matrix(m1.getRowAmount(), m1.getColumnAmount());
        for (int i = 0; i < m1.getRowAmount(); i++) {
            for (int j = 0; j < m1.getRowAmount(); j++) {
                result.set(i, j, m1.get(i, j) - m2.get(i, j));
            }
        }
        return result;
    }

    Matrix operator*(Matrix& m1, Matrix& m2) {

    }

    Matrix operator*(float f, Matrix& m1) {
        Matrix result = Matrix(m1.getRowAmount(), m1.getColumnAmount());
        for (int i = 0; i < m1.getRowAmount(); i++) {
            for (int j = 0; j < m1.getColumnAmount(); j++) {
                result.set(i, j, m1.get(i, j) * f);
            }
        }
        return result;
    }

    ::std::ostream& operator<<(std::ostream& os, Matrix& m) {
        for (int i = 0; i < m.getRowAmount(); i++) {
            os << "| ";
            for (int j = 0; j < m.getColumnAmount(); j++) {
                os << m.get(i, j) << " ";
            }
            os << "|\n";
        }
        return os;
    }

} // MathLib