#include <stdio.h>

#include "rotating_point.h"

COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    if (p == 0) {
        Real(C) = 1;
        Imag(C) = 0;
        return C;
    }
    else if (p == 1) {
        return C;
    }
    else {
        return MultiplyCOMPLEX(PowerCOMPLEX(C, p - 1), C);
    }
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    int i;
    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }
    for (i = 0;  i < n; i++) {
        COMPLEX pC = PowerCOMPLEX(C, i + 1);
        float x = (Absis(*P) * Real(pC)) - (Ordinat(*P) * Imag(pC));
        float y = (Absis(*P) * Imag(pC)) + (Ordinat(*P) * Real(pC));

        Absis(*P) = x;
        Ordinat(*P) = y;
        if (pow(Absis(*P), 2) + pow(Ordinat(*P), 2) >= 1) {
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i + 1);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}

