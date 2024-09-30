#include <stdio.h>
#include <math.h>

#include "fraction.h"


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D) {
    return (D != 0);
}

void CreateFRACTION(FRACTION *F, int N, int R) {
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F) {
    int x, y;

    do {
        scanf("%d %d", &x, &y);
        if (!(IsFRACTIONValid(x, y))) {
            printf("FRACTION tidak valid\n");
        }   
    } while (!IsFRACTIONValid(x, y));
    CreateFRACTION(F, x, y);
}

void WriteFRACTION(FRACTION F) {
    F = SimplifyFRACTION(F);
    printf("%d/%d",Numerator(F), Denominator(F));
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    int num, den;

    num = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    den = Denominator(F1) * Denominator(F2);

    FRACTION x;
    Numerator(x) = num;
    Denominator(x) = den;

    if (num == 0) {
        Denominator(x) = 1;
    }
    return SimplifyFRACTION(x);

}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    int num, den;

    num = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
    den = Denominator(F1) * Denominator(F2);

    FRACTION x;
    Numerator(x) = num;
    Denominator(x) = den;
    if (num == 0) {
        Denominator(x) = 1;
    }
    return SimplifyFRACTION(x);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    int num, den;

    num = Numerator(F1) * Numerator(F2);
    den = Denominator(F1) * Denominator(F2);

    FRACTION x;
    Numerator(x) = num;
    Denominator(x) = den;
    if (num == 0) {
        Denominator(x) = 1;
    }
    return SimplifyFRACTION(x);
}



FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    int num, den;

    num = Numerator(F1) * Denominator(F2);
    den = Denominator(F1) * Numerator(F2);

    FRACTION x;
    Numerator(x) = num;
    Denominator(x) = den;
    if (num == 0) {
        Denominator(x) = 1;
    }
    return SimplifyFRACTION(x);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    int num, den;

    num = Numerator(F1) * n;
    den = Denominator(F1);

    FRACTION x;
    Numerator(x) = num;
    Denominator(x) = den;
    return SimplifyFRACTION(x);
}

FRACTION SimplifyFRACTION(FRACTION F) {
    int num, den;

    num = Numerator(F);
    den = Denominator(F);

    int fpb = gcd(num, den);

    FRACTION x;
    Numerator(x) = num / fpb;
    Denominator(x) = den / fpb;

    if (Denominator(x) < 0) {
        Denominator(x) *= -1;
        Numerator(x) *= -1;
    }
    return x;
}

float ToDecimal(FRACTION F) {
    return ((float) Numerator(F)) / ((float) Denominator(F));
}