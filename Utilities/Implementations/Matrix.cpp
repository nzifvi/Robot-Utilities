//
// Created by benja on 12.07.2025.
//

#include "../Headers/Matrix.h"

namespace MathLib {

    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    Matrix::Matrix(const int rowSize, const int columnSize):
    ptrArray(new float[rowSize * columnSize]),
    rows(rowSize),
    columns(columnSize){

    }

    Matrix::Matrix(const Matrix& other): // DEEP COPY
    ptrArray(new float[other.rows * other.columns]),
    rows(other.rows),
    columns(other.columns){
        for (int rowIndex = 0; rowIndex < other.rows; rowIndex++) {
            for (int columnIndex = 0; columnIndex < other.columns; columnIndex++) {
                ptrArray[index(rowIndex, columnIndex)] = other.ptrArray[index(rowIndex, columnIndex)];
            }
        }
    }

    Matrix::Matrix(Matrix&& other): // DEEP MOVE
    rows(other.rows),
    columns(other.columns),
    ptrArray(std::move(other.ptrArray)){
        other.ptrArray = nullptr;
    }

    Matrix::~Matrix() {
        if (ptrArray) {
            delete[] ptrArray;
        }
    }

    // PRIVATE FUNCTION MEMBER(S):
    int Matrix::index(const int row, const int col) const {
        return row*columns + col;
    }

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

    ::std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int row = 0; row < m.getRowAmount(); row++) {
            os << "| ";
            for (int col = 0; col < m.getColumnAmount(); col++) {
                os << m.get(row, col) << " ";
            }
            os << "|\n";
        }
        return os;
    }

    Matrix& Matrix::operator=(Matrix&& other) {
        if (this != &other) {
            delete[] ptrArray;

            ptrArray = other.ptrArray;
            rows = other.rows;
            columns = other.columns;

            other.ptrArray = nullptr;
            other.rows = 0;
            other.columns = 0;
        }
        return *this;
    }

    Matrix& Matrix::operator=(const Matrix& other) {
        if (this != &other) {
            delete[] ptrArray;

            rows = other.rows;
            columns = other.columns;
            ptrArray = new float[rows*columns];
            for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
                for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
                    ptrArray[index(rowIndex, columnIndex)] = other.get(rowIndex, columnIndex);
                }
            }
        }
        return *this;
    }

} // MathLib