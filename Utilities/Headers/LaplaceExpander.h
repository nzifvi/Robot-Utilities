//
// Created by benja on 13.07.2025.
//

#ifndef LAPLACEEXPANDER_H
#define LAPLACEEXPANDER_H

#include "Matrix.h"

namespace MathLib {

    class LaplaceExpander {
    private:
        // DATA MEMBER(S):
        struct LaplaceExpansionTerm {
            Matrix* matrix;
            int sign;
            LaplaceExpansionTerm(Matrix& matrix, const int sign) {
                this->matrix = &matrix;
                this->sign = sign;
            }
        };
        LaplaceExpansionTerm* ptrLaplaceExpansionExpression;
        int arraySize;
        int arrayCapacity;
        Matrix originalMatrix;

        // PRIVATE FUNCTION MEMBER(S):
    public:
        // CONSTRUCTOR(S):
        LaplaceExpander(Matrix& originalMatrix);
        ~LaplaceExpander();

        //DESTRUCTOR(S):
    };

} // MathLib

#endif //LAPLACEEXPANDER_H
