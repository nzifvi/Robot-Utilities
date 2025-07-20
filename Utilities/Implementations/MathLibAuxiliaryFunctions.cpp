#include "MathLibAuxiliaryFunctions.h"
#include "LaplaceExpander.h"

void MathLib::transpose(Matrix& m) {
    for (int i = 0; i < m.getRowAmount(); i++) {
        for (int j = 0; j < m.getColumnAmount(); j++) {
            m.set(j, i, m.get(i, j));
        }
    }
}

float MathLib::determinant(Matrix& m) {
    if (m.getRowAmount() != m.getColumnAmount() || m.getRowAmount() == 0 || m.getRowAmount() == 1) {
        throw invalid_dimensions();
    }else {
        if (m.getRowAmount() == 2 && m.getColumnAmount() == 2) {
            return m.get(0,0) * m.get(1,1) - m.get(0,1) * m.get(1,0);
        }else {
            LaplaceExpander laplaceExpander(m);
            laplaceExpander.performLaplaceExpansion();
            float det = 0;
            for (int i = 0; i < laplaceExpander.getNumberOfLaplaceExpansionTerms(); i++) {
                det += determinant(laplaceExpander.getLaplaceTermMatrix(i)) * laplaceExpander.getLaplaceTermSign(i);
            }
            return det;
        }
    }
}