#include <stdio.h>
#include <math.h>
#include "matrix.h"

int main (void) {
    int n;
    scanf("%d", &n);
    Matrix m;
    readMatrix(&m, n, n);
    int sum = 0;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ELMT(m, i, j) > 0) {
                for (k = 0; k < n; k++) {
                    if (k != i && ELMT(m, k, j) > 0) {
                        sum = (sum + ELMT(m, k, j)) % (int) (pow(10, 9) + 7);
                    }
                    if (k != j && ELMT(m, i, k) > 0) {
                        sum = (sum + ELMT(m, i, k)) % (int) (pow(10, 9) + 7);
                    }
                }
            }
        }
    }
    sum = sum % (int) (pow(10, 9) + 7);
    printf("%d\n", sum);
    return 0;
}