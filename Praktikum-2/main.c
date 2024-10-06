#include <stdio.h>

#include "liststatik.h"

int main (void) {
    ListStatik l1;
    ListStatik l2;
    ListStatik l3;

    readList(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);

    sortList(&l1, true);

    int lengthl1 = listLength(l1);

    int i;
    for (i = 0; i < lengthl1; i++) {
        if (indexOf(l2, ELMT(l1,i)) == IDX_UNDEF) {
            insertLast(&l2, ELMT(l1, i));
        }
    }

    int lengthl2 = listLength(l2);

    int j, count;
    for (i = 0; i < lengthl2; i++) {
        count = 0;
        for (j = 0; j < lengthl1; j++) {
            if (ELMT(l1,j) == ELMT(l2, i)) {
                count++;
            }
        }
        ELMT(l3, i) = count;
    }

    int max, min;
    extremeValues(l3, &max, &min);

    for (i = 0; i < lengthl2; i++) {
        if (ELMT(l3, i) == max) {
            ELMT(l3, i) = 0;
        }
    }

    extremeValues(l3, &max, &min);


    if (!isEmpty(l1) && max != 0) {
        printf("%d\n", ELMT(l2, indexOf(l3, max)));
    }
    else {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    return 0;
}