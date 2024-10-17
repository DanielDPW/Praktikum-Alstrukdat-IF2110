#include <stdio.h>
#include <math.h>

#include "matrix.h"

Matrix subMatrix(Matrix m, int row, int col);

Matrix subMatrix(Matrix m, int row, int col) {
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    Matrix newM;
    createMatrix(rows - 1, cols - 1, &newM);

    int rowIdx = 0;
    int i, j;
    for (i = 0; i < rows; i++) {
        int colIdx = 0;
        for (j = 0; j < cols; j++) {
            if (i != row && j != col) {
                ELMT(newM, rowIdx, colIdx) = ELMT(m, i, j);
                colIdx++;
            }
        }
        if (i != row) {
            rowIdx++;
        }
    }
    return newM;
}

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
    return (i <= ROW_CAP - 1 && i >= 0 && j <= COL_CAP - 1 && j >= 0);
}

IdxType getLastIdxRow(Matrix m) {
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m) {
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i <= getLastIdxRow(m) && i >= 0 && j <= getLastIdxCol(m) && j >= 0);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i, j;
    int rows = ROW_EFF(mIn);
    int cols = COL_EFF(mIn);
    ROW_EFF(*mOut) = rows;
    COL_EFF(*mOut) = cols;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);

    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d", ELMT(m, i, j));
            if (j != getLastIdxCol(m)) {
                printf(" ");
            }
        }
        if (i != getLastIdxRow(m)) {
            printf("\n");
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    int rows = ROW_EFF(m1);
    int cols = COL_EFF(m1);
    Matrix m;
    createMatrix(rows, cols, &m);

    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    int rows = ROW_EFF(m1);
    int cols = COL_EFF(m1);
    Matrix m;
    createMatrix(rows, cols, &m);
    
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    int rows1 = ROW_EFF(m1);
    int cols1 = COL_EFF(m1);
    int rows2 = ROW_EFF(m2);
    int cols2 = COL_EFF(m2);
    Matrix m;
    createMatrix(rows1, cols2, &m);

    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            int temp = 0;
            for (k = 0; k < cols1; k++) {
                temp += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(m, i, j) = temp;
        }
    }
    return m;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    Matrix newM;
    createMatrix(rows, cols, &newM);

    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(newM, i, j) = ELMT(m, i, j) * x;
        }
    }
    return newM;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    int rows = ROW_EFF(*m);
    int cols = COL_EFF(*m);

    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (!isMatrixSizeEqual(m1, m2)) {
        return false;
    }
    int rows = ROW_EFF(m1);
    int cols = COL_EFF(m1);

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
}

int countElmt(Matrix m) {
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m) {
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }

    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j && ELMT(m, i, j) != 1) {
                return false;
            } else if ( i!= j && ELMT(m, i, j) != 0) {
                return false;
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m) {
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    int count = 0;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (ELMT(m, i, j) != 0) {
                count++;
            }
        }
    }
    return 100*count <= 5*countElmt(m);
}

Matrix negation(Matrix m) {
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
    int rows = ROW_EFF(*m);
    int cols = COL_EFF(*m);

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(*m, i, j) *= -1;
        }
    }
}

float determinant(Matrix m) {
    int cols = COL_EFF(m);
    if (cols == 1) {
        return (float) ELMT(m, 0, 0);
    }

    float det = 0;
    int i;
    for (i = 0; i < cols; i++) {
        Matrix subM = subMatrix(m, 0, i);
        det += pow(-1, i) * ELMT(m, 0, i) * determinant(subM);
    }
    return det;
}

Matrix transpose(Matrix m) {
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    Matrix newM;
    createMatrix(cols, rows, &newM);
    
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ELMT(newM, j, i) = ELMT(m, i, j);
        }
    }
    return newM;
}

void pTranspose(Matrix *m) {
    int rows = ROW_EFF(*m);
    int cols = COL_EFF(*m);

    int temp;
    int i, j;
    for (i = 1; i < rows; i++) {
        for (j = 0; j < i; j++) {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}