#include <stdio.h>
#include <math.h>

#include "point.h"

void CreatePoint(POINT * P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P) {
    float x, y;

    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
    return !EQ(P1, P2);
}

boolean IsOrigin(POINT P) {
    return (!Absis(P) && !Ordinat(P));
}

boolean IsOnSbX(POINT P) {
    return !Ordinat(P);
}

boolean IsOnSbY(POINT P) {
    return !Absis(P);
}

int Kuadran(POINT P) {
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    }
    else if (Absis(P) > 0 && Ordinat(P) < 0) {
        return 4;
    }
    return 0;
}

POINT NextX(POINT P) {
    POINT newPoint;
    CreatePoint(&newPoint, Absis(P) + 1, Ordinat(P));
    return newPoint;
}

POINT NextY(POINT P) {
    POINT newPoint;
    CreatePoint(&newPoint, Absis(P), Ordinat(P) + 1);
    return newPoint;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    POINT newPoint;

    CreatePoint(&newPoint, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return newPoint;
}

POINT MirrorOf(POINT P, boolean SbX) {
    POINT newPoint;

    if (SbX) {
        CreatePoint(&newPoint, Absis(P), -Ordinat(P));
    }
    else {
        CreatePoint(&newPoint, -Absis(P), Ordinat(P));
    }
    return newPoint;
}

float Jarak0(POINT P) {
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}

float Panjang(POINT P1, POINT P2) {
    return sqrt(pow(Absis(P2) - Absis(P1), 2) + pow(Ordinat(P2) - Ordinat(P1), 2));
}

void Geser(POINT *P, float deltaX, float deltaY) {
    CreatePoint(P, Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}

void GeserKeSbX(POINT *P) {
    CreatePoint(P, Absis(*P), 0);
}

void GeserKeSbY(POINT *P) {
    CreatePoint(P, 0, Ordinat(*P));
}

void Mirror(POINT *P, boolean SbX) {
    if (SbX) {
        CreatePoint(P, Absis(*P), -Ordinat(*P));
    }
    else {
        CreatePoint(P, -Absis(*P), Ordinat(*P));
    }
}

void Putar (POINT *P, float Sudut) {
    float Radian = -1 * Sudut * acos(-1) / 180;

    float newX = Absis(*P) * cos(Radian) - Ordinat(*P) * sin(Radian);
    float newY = Absis(*P) * sin(Radian) + Ordinat(*P) * cos(Radian);

    Absis(*P) = newX;
    Ordinat(*P) = newY;
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) {
    int a, b;

    float m = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));

    a = (int) m;
    b = (int) -m * Absis(P1) + Ordinat(P1);

    printf("(%d,%d)\n", a, b);
}