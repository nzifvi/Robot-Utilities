//
// Created by benja on 13.07.2025.
//

#ifndef LAPLACEEXPANDER_H
#define LAPLACEEXPANDER_H

#include "Matrix.h"
#include "DynamicArray.h"
#include <vector>

namespace MathLib {

    class LaplaceExpander {
    private:
        // DATA MEMBER(S):
        struct LaplaceExpansionTerm {
            Matrix matrix;
            float sign;
            LaplaceExpansionTerm(Matrix& matrix, const float sign): matrix(matrix) {
                this->sign = sign;
            }
            LaplaceExpansionTerm(): matrix(0,0) {
                sign = 0;
            }
            ~LaplaceExpansionTerm() {

            }
        };
        Matrix originalMatrix;
        Matrix* ptrCofactorsMatrix = nullptr;
        int arraySize;
        DSLib::DynamicArray<LaplaceExpansionTerm> laplaceExpansionExpression;

        // PRIVATE FUNCTION MEMBER(S):
        void updateCofactorsMatrix(Matrix& matrix);
        int index(const int rowNo, const int colNo);

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LaplaceExpander(Matrix* originalMatrix);

        LaplaceExpander(Matrix &originalMatrix);

        ~LaplaceExpander();

        // PUBLIC FUNCTION MEMBER(S):
        void performLaplaceExpansion();

        // ENCAPSULATION FUNCTION MEMBER(S):
        Matrix getCofactorsMatrix() { return *ptrCofactorsMatrix; }

    };

} // MathLib

#endif //LAPLACEEXPANDER_H
