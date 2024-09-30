#include <stdio.h>

#include "complex.h"

boolean IsCOMPLEXValid(float Re, float Im) {
    return !isnan(Re) && !isnan(Im) && isfinite(Re) && isfinite(Im);
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
    float a, b;

    scanf("%f %f", &a, &b);
    CreateComplex(C, a, b);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) < 0) {
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    }
    else {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;

    CreateComplex(&C, Real(C1) + Real(C2), Imag(C1) + Imag(C2));
    return C;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;

    CreateComplex(&C, Real(C1) - Real(C2), Imag(C1) - Imag(C2));
    return C;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;

    CreateComplex(&C, (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2)), (Real(C1) * Imag(C2)) + (Real(C2) * Imag(C1)));
    return C;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;
    COMPLEX numerator = MultiplyCOMPLEX(C1, ConjugateCOMPLEX(C2));
    float denominator = pow(Real(C2), 2) + pow(Imag(C2), 2);
    if (!(denominator)) {
        CreateComplex(&C, 0, 0);
        return C;
    }
    
    CreateComplex(&C, Real(numerator) / denominator, Imag(numerator) / denominator);
    return C;
}

float AbsCOMPLEX(COMPLEX C) {
    return sqrt(pow(Real(C), 2) + pow(Imag(C), 2));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX x;
    
    Real(x) = Real(C);
    Imag(x) = - 1 * Imag(C);

    return x;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2) && Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return !CEQ(C1, C2);
}