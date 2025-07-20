//
// Created by benja on 13.07.2025.
//

#ifndef LAPLACEEXPANDER_H
#define LAPLACEEXPANDER_H

#include "Matrix.h"
#include "DynamicArray.h"
#include <vector>
#include <queue>

namespace MathLib {

    struct LaplaceExpansionTerm {
        Matrix term;
        float sign;
        LaplaceExpansionTerm(Matrix&& matrix, const float sign):
        term(matrix),
        sign(sign){}
    };

    class LaplaceExpander {
    private:
        // DATA MEMBER(S):
        Matrix originalMatrix;
        Matrix cofactorsMatrix;
        //DSLib::DynamicArray<LaplaceExpansionTerm> laplaceExpansionArray;
        std::vector<LaplaceExpansionTerm> laplaceExpansionVec;

        // PRIVATE FUNCTION MEMBER(S):

    public:
        // CONSTRUCTOR(S) AND DESTRUCTOR(S):
        LaplaceExpander(const Matrix& originalMatrix);

        ~LaplaceExpander();

        // PUBLIC FUNCTION MEMBER(S):
        void performLaplaceExpansion();

        // ENCAPSULATION FUNCTION MEMBER(S):
        Matrix& getCofactorsMatrixREFERENCE() {return cofactorsMatrix;}
        Matrix& getLaplaceTermMatrix(const int index) {
            if (index < 0 || index > laplaceExpansionVec.size()) {
                throw std::out_of_range("Attempt to get matrix in laplace expansion vector resulted in an attempt to access an out of bounds index");
            }else {
                return laplaceExpansionVec[index].term;
            }
        }
        float getLaplaceTermSign(const int index) {
            if (index < 0 ||index > laplaceExpansionVec.size()) {
                throw std::out_of_range("Attempt to get sign in laplace expansion vector resulted in an attempt to access an out of bounds index");
            }else {
                return laplaceExpansionVec[index].sign;
            }
        }
        int getNumberOfLaplaceExpansionTerms() {
            return laplaceExpansionVec.size();
        }
    };

} // MathLib

#endif //LAPLACEEXPANDER_H
