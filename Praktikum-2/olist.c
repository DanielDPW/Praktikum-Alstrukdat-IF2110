#include <stdio.h>

#include "liststatik.h"

int main (void) {
    ListStatik l1;
    ListStatik l2;
    readList(&l1);

    int lengthl1 = listLength(l1);
    CreateListStatik(&l2);
    int i;
    for (i = 0; i < lengthl1; i++) {
        if (indexOf(l2, ELMT(l1,i)) == IDX_UNDEF) {
            insertLast(&l2, ELMT(l1, i));
        }
    }
    printList(l2);
    printf("\n");
    int count;
    int lengthl2 = listLength(l2);
    int j;
    for (i = 0; i < lengthl2; i++) {
        count = 0;
        for (j = 0; j < lengthl1; j++) {
            if (ELMT(l1,j) == ELMT(l2, i)) {
                count++;
            }
        }
        printf("%d %d\n", ELMT(l2,i), count);
    }
    return 0;
}