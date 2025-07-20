//
// Created by benja on 13.07.2025.
//

#include "LaplaceExpander.h"

namespace MathLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LaplaceExpander::LaplaceExpander(const Matrix& originalMatrix):
    originalMatrix(originalMatrix),
    cofactorsMatrix(Matrix(originalMatrix.getRowAmount(), originalMatrix.getColumnAmount())){
        for (int rowIndex = 0; rowIndex < cofactorsMatrix.getRowAmount(); rowIndex++) {
            for (int colIndex = 0; colIndex < cofactorsMatrix.getColumnAmount(); colIndex++) {
                if ((rowIndex * cofactorsMatrix.getColumnAmount() + colIndex) % 2 == 0) {
                    cofactorsMatrix.set(rowIndex, colIndex, 1);
                }else {
                    cofactorsMatrix.set(rowIndex, colIndex, -1);
                }
            }
        }
    }

    LaplaceExpander::~LaplaceExpander() {

    }


    // PRIVATE FUNCTION MEMBER(S):

    // PUBLIC FUNCTION MEMBER(S):
    void LaplaceExpander::performLaplaceExpansion() {
        // ASSUMING FIRST ROW (1 (0 in array index)) IS ALWAYS CHOSEN

        for (int excludeColNo = 0; excludeColNo < originalMatrix.getColumnAmount(); excludeColNo++) {
            std::queue<float> extractedElements;
            for (int rowNo = 1; rowNo < originalMatrix.getRowAmount(); rowNo++) {
                for (int colNo = 0; colNo < originalMatrix.getColumnAmount(); colNo++) {
                    if (colNo != excludeColNo) {
                        extractedElements.push(originalMatrix.get(rowNo, colNo));
                    }
                }
            }
            MathLib::Matrix tempMatrix(originalMatrix.getRowAmount() - 1, originalMatrix.getColumnAmount() - 1);
            for (int rowIndex = 0; rowIndex < originalMatrix.getRowAmount() - 1; rowIndex++) {
                for (int colNo = 0; colNo < originalMatrix.getColumnAmount() - 1; colNo++) {
                    tempMatrix.set(rowIndex, colNo, extractedElements.front());
                    extractedElements.pop();
                }
            }
            laplaceExpansionVec.push_back(LaplaceExpansionTerm{std::move(tempMatrix), cofactorsMatrix.get(0, excludeColNo)});
        }
    }

    // AUXILIARY FUNCTION(S) AND GENERAL FUNCTION(S):

} // MathLib