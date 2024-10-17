#include <stdio.h>
#include "matrix.h"

const int MOD = 1e9 + 7;
Matrix m;
Matrix path;
int main(void) {
    int n;
    scanf("%d", &n);
    readMatrix(&m, n, n);
    createMatrix(n, n, &path);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ELMT(path, i, j) = 0;
        }
    }
    int lastRow = getLastIdxRow(m);
    int lastCol = getLastIdxCol(m);
    ELMT(path, lastRow, lastCol)= 1;
    for (i = lastRow; i >= 0; i--) {
        for (j = lastCol; j >= 0; j--) {
            if (ELMT(m, i, j) == 1) {
                ELMT(path, i, j) = 0;
            } else {
                if (i + 1 <= lastRow) {
                    ELMT(path, i, j) = (ELMT(path, i, j) + ELMT(path, i + 1, j)) % MOD;
                }
                if (j + 1 <= lastCol) {
                    ELMT(path, i, j) = (ELMT(path, i, j) + ELMT(path, i, j + 1)) % MOD;
                }
            }
        }
    }

    printf("%d\n", ELMT(path, 0, 0) % MOD);
    return 0;
}
