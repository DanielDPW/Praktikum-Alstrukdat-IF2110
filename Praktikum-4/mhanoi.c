#include <stdio.h>

#include "matrix.h"

void rotate2x2 (Matrix *m) {
        int a = ELMT(*m, 0, 0);
        int b = ELMT(*m, 0, 1);
        int c = ELMT(*m, 1, 0);
        int d = ELMT(*m, 1, 1);

        ELMT(*m, 0, 0) = c;
        ELMT(*m, 0, 1) = a;
        ELMT(*m, 1, 0) = d;
        ELMT(*m, 1, 1) = b;
}

int main (void) {
    int n;
    scanf("%d", &n);
    Matrix m, x;
    readMatrix(&m, n, n);
    int rows = ROW_EFF(m);
    int cols = COL_EFF(m);
    readMatrix(&x, 2, 2);
    int count = 0;
    int rot_count;
    int i, j;
    boolean found;
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < cols - 1; j++) {
            rot_count = 0;
            found = false;
            while (rot_count < 4) {
                if (!found && ELMT(m, i, j) > ELMT(x, 0, 0) && ELMT(m, i, j + 1) > ELMT(x, 0, 1) && ELMT(m, i + 1, j) > ELMT(x, 1, 0) && ELMT(m, i + 1, j + 1) > ELMT(x, 1, 1)) {
                    found = !found;
                    count++;
                }
                rotate2x2(&x);
                rot_count++;
            }
            
        }
    }
    printf("%d\n", count);
}