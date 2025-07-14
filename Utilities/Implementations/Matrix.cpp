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

    Matrix::Matrix(Matrix& matrix) {
        this->rows = matrix.rows;
        this->columns = matrix.columns;
        ptrArray = new float*[rows];
        for (int j = 0; j < rows; j++) {
            ptrArray[j] = new float[columns];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ptrArray[i][j] = matrix.ptrArray[i][j];
            }
        }
    }

    Matrix::~Matrix() {
        std::cout << "Matrix destructor called\n";
        for (int j = 0; j < rows; j++) {
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
        if (m1.getColumnAmount() != m2.getRowAmount()) {
            throw invalid_dimensions();
        }else {
            Matrix result = Matrix(m1.getRowAmount(), m2.getColumnAmount());
            for (int i = 0; i < m1.getRowAmount(); i++) {
                for (int j = 0; j < m2.getColumnAmount(); j++) {
                    float weightedSum = 0.0f;
                    for (int k = 0; k < m1.getColumnAmount(); k++) {
                        weightedSum += m1.get(i, k) * m2.get(k, j);
                    }
                    result.set(i, j, weightedSum);
                }
            }
            return result;
        }
    }

    Matrix operator*(const float f, Matrix& m1) {
        Matrix result = Matrix(m1.getRowAmount(), m1.getColumnAmount());
        for (int i = 0; i < m1.getRowAmount(); i++) {
            for (int j = 0; j < m1.getColumnAmount(); j++) {
                result.set(i, j, m1.get(i, j) * f);
            }
        }
        return result;
    }

    ::std::ostream& operator<<(std::ostream& os, Matrix& m) {
        for (int row = 0; row < m.getRowAmount(); row++) {
            os << "| ";
            for (int col = 0; col < m.getColumnAmount(); col++) {
                os << m.get(row, col) << " ";
            }
            os << "|\n";
        }
        return os;
    }

    void transpose(Matrix& m) {
        for (int i = 0; i < m.getRowAmount(); i++) {
            for (int j = 0; j < m.getColumnAmount(); j++) {
                m.set(j, i, m.get(i, j));
            }
        }
    }

    float determinant(Matrix& m) {
        if (m.getRowAmount() != m.getColumnAmount() || m.getRowAmount() == 0 || m.getRowAmount() == 1) {
            throw invalid_dimensions();
        }else {
            if (m.getRowAmount() == 2 && m.getColumnAmount() == 2) {
                return m.get(0,0) * m.get(1,1) - m.get(0,1) * m.get(1,0);
            }else {
                throw case_not_yet_implemented(); // IMPLEMENT LAPLACE EXPANSION FUNCTION TO RECURSIVELY REDUCE TO A SUM OF 2D MATRIX DETERMINANTS
            }
        }
    }

} // MathLib