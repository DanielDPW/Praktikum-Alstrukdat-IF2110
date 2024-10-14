#include <stdio.h>

#include "listdin.h"

int main (void) {
    ListDin l, left, right;
    CreateListDin(&l, 100000);
    CreateListDin(&left, 100000);
    CreateListDin(&right, 100000);
    readList(&l);

    int count = 0;
    int length = listLength(l);

    ELMT(left, 0) = ELMT(l, 0);
    ELMT(right, length - 1) = ELMT(l, length - 1);
    NEFF(left)++;
    NEFF(right)++;
    
    int i;
    for (int i = 1; i < length; i++) {
        if (ELMT(l, i) > ELMT(left, i - 1)) {
            ELMT(left, i) = ELMT(l, i);
        } else {
            ELMT(left, i) = ELMT(left, i - 1);
        }
        NEFF(left)++;
        if (ELMT(l, length - i - 1) < ELMT(right, length - i)) {
            ELMT(right, length - i - 1) = ELMT(l, length - i - 1);
        } else {
            ELMT(right, length - i - 1) = ELMT(right, length - i);
        }
        NEFF(right)++;
    }

    if (ELMT(l, 0) < ELMT(right, 1)) {
        count++;
    }

    if (ELMT(l, length - 1) > ELMT(right, length - 2)) {
        count++;
    }
    for (int i = 1; i < length - 1; i++) {
        if (ELMT(l, i) > ELMT(left, i - 1) && ELMT(l, i) < ELMT(right, i + 1)) {
            count++;
        }
    }
    
    printf("%d\n",count);
    return 0;
}