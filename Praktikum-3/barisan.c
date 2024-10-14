#include <stdio.h>

#include "listdin.h"

int main (void) {
    ListDin l1, l2;

    CreateListDin(&l1,1000);
    CreateListDin(&l2,1000);

    readList(&l1);

    int length = listLength(l1);
    int count = 0;
    int i;
    for (i = 0; i < length; i++) {
        insertLast(&l2, ELMT(l1, i));
        if (i > 0) {
            int j = i - 1;
            while (j >= 0 && ELMT(l2,i) < ELMT(l2,j)) {
                count++;
                j--;
            }
        }
        sort(&l2,true);
    }
    printf("%d\n",count);
    return 0;
}