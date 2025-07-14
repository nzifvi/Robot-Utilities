//
// Created by benja on 13.07.2025.
//

#include "../Headers/LaplaceExpander.h"

namespace MathLib {
    // CONSTRUCTOR(S) AND DESTRUCTOR(S):
    LaplaceExpander::LaplaceExpander(Matrix& originalMatrix): originalMatrix(originalMatrix) {
        updateCofactorsMatrix(originalMatrix);
    }

    LaplaceExpander::~LaplaceExpander() {
        delete ptrCofactorsMatrix;
    }


    // PRIVATE FUNCTION MEMBER(S):
    void LaplaceExpander::updateCofactorsMatrix(Matrix& matrix) {
        ptrCofactorsMatrix = new Matrix(matrix.getRowAmount(), matrix.getColumnAmount());
        arraySize = matrix.getRowAmount() * matrix.getColumnAmount();
        for (int rowNo = 0; rowNo < matrix.getRowAmount(); rowNo++) {
            for (int colNo = 0; colNo < matrix.getColumnAmount(); colNo++) {
                if (index(rowNo, colNo) % 2 == 0) {
                    ptrCofactorsMatrix->set(rowNo, colNo, 1);
                }else {
                    ptrCofactorsMatrix->set(rowNo, colNo, -1);
                }
            }
        }
    }

    int LaplaceExpander::index(const int rowNo, const int colNo) {
        return rowNo * originalMatrix.getColumnAmount() + colNo;
    }

    // PUBLIC FUNCTION MEMBER(S):
    void LaplaceExpander::performLaplaceExpansion() {
        // ASSUMING FIRST ROW (1 (0 in array index)) IS ALWAYS CHOSEN

        for (int excludeColNo = 0; excludeColNo < originalMatrix.getColumnAmount(); excludeColNo++) {
            DSLib::DynamicArray<float> extractedElements;
            for (int rowNo = 1; rowNo < originalMatrix.getRowAmount(); rowNo++) {
                for (int colNo = 0; colNo < originalMatrix.getColumnAmount(); colNo++) {
                    if (colNo != excludeColNo) {
                        extractedElements.insert(extractedElements.size(), originalMatrix.get(rowNo, colNo)); // verified as not the problem
                    }
                }
            }
            /* CODE BLOCK BELOW CAUSES SEGMENTATION FAULT

            */
            Matrix extractedMatrix(originalMatrix.getRowAmount() - 1, originalMatrix.getColumnAmount() - 1);
            for (int rowNo = 0; rowNo < extractedMatrix.getRowAmount(); rowNo++) {
                for (int colNo = 0; colNo < extractedMatrix.getColumnAmount(); colNo++) {
                    extractedMatrix.set(rowNo, colNo, extractedElements.remove(0));
                }
            }
            std::cout << extractedMatrix << std::endl;
            // BELOW CAUSES SEGMENTATION FAULT
            aaa
            /*
            laplaceExpansionExpression.insert(
                 0,
                 LaplaceExpansionTerm{extractedMatrix,ptrCofactorsMatrix->get(0, excludeColNo)}
             );
             */
        }
    }

    // AUXILIARY FUNCTION(S) AND GENERAL FUNCTION(S):
} // MathLib