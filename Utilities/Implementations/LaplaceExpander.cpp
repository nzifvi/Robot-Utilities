//
// Created by benja on 13.07.2025.
//

#include "../Headers/LaplaceExpander.h"

namespace MathLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LaplaceExpander::LaplaceExpander(Matrix& originalMatrix): originalMatrix(originalMatrix) {
        ptrLaplaceExpansionExpression = new LaplaceExpansionTerm[0]();
    }

    LaplaceExpander::~LaplaceExpander() {
        delete[] ptrLaplaceExpansionExpression;
    }


    // PRIVATE FUNCTION MEMBER(S):

    // PUBLIC FUNCTION MEMBER(S):

    // AUXILIARY FUNCTION(S) AND GENERAL FUNCTION(S):
} // MathLib