#include <stdio.h>
#include <math.h>

#include "circle.h"

boolean IsCIRCLEValid(float X, float Y, float R) {
    return (R > 0);
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    CreatePoint(&Center(*C), X, Y);
    Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C) {
    float x, y, r;

    do {
        scanf("%f %f %f", &x, &y, &r);
        if (!(IsCIRCLEValid(x, y, r))) {
            printf("CIRCLE tidak valid\n");
        }   
    } while (!IsCIRCLEValid(x, y, r));
    CreateCIRCLE(C, x, y, r);
}

void WriteCIRCLE(CIRCLE C) {
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

float Circumference(CIRCLE C) {
    return (3.14 * 2 * Radius(C));
}

float Area(CIRCLE C) {
    return (3.14 * pow(Radius(C), 2));
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    return (Panjang(Center(C), P) < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
 
    return (fabsf(Panjang(Center(C), P) - Radius(C)) < 0.0001);
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    return (Panjang(Center(C1), Center(C2)) < fabsf(Radius(C2) - Radius(C1)));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    return (Panjang(Center(C1), Center(C2)) == fmaxf(Radius(C1), Radius(C2)) - fminf(Radius(C1), Radius(C2)) || Panjang(Center(C1), Center(C2)) == (Radius(C1) + Radius(C2)));
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    return (fabsf(Radius(C1) - Radius(C2)) < d && d < (Radius(C1) + Radius(C2)));
}