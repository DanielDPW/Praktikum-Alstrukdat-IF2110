#include <stdio.h>

#include "liststatik.h"

int main (void) {
    ListStatik l;
    readList(&l);

    int length = listLength(l);

    int i;
    int extra = 1;
    for (i = length - 1; i >= 0; i--) {
        ELMT(l,i) += extra;
        if (ELMT(l, i) == 10) {
            ELMT(l,i) = 0;
            extra = 1;
        }
        else {
            extra = 0;
        }
        if (extra && i == 0) {
            insertFirst(&l,1);
        }
    }
    length = listLength(l);
    for (i = 0; i < length; i++) {
        printf("%d", ELMT(l, i));
        if (i != length - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}