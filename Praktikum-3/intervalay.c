#include <stdio.h>

#include "listdin.h"

int main (void) {
    ListDin l;
    int n;
    scanf("%d", &n);
    CreateListDin(&l, n);
    NEFF(l) = n;

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(l,i));
    }

    ListDin x;
    CreateListDin(&x, 2);

    ListDin new;
    CreateListDin(&new, n + 2);
    for (i = 0; i < 2; i++) {
        scanf("%d", &ELMT(x,i));
    }
    boolean inNewInterval = false;
    boolean found = false;
    for (i = 0; i < n; i++) {
        if (ELMT(l,i) >= ELMT(x, 0) && ELMT(l,i) <= ELMT(x,1)) {
            found = true;
            if (!inNewInterval) {
                if (i % 2 == 0) {
                    insertLast(&new, ELMT(x, 0));
                }
            }
            inNewInterval = true;
        } else {
            if (inNewInterval) {
                if (i % 2 == 0) {
                    insertLast(&new, ELMT(x, 1));
                }
                inNewInterval = false;
            }
            insertLast(&new, ELMT(l, i));
        }
    }
    for (i = 0; i < n; i++){
        if ((i % 2 == 1) && ELMT(x, 0) <= ELMT(l,i) && ELMT(x, 1) <= ELMT(l, i) && ELMT(x, 0) >= ELMT(l,i - 1) && ELMT(x, 1) >= ELMT(l, i - 1)) {
            found = true;
        }
    }

    if (inNewInterval) {
        insertLast(&new, ELMT(x, 1));
    }
    
    if (!found) {

            insertLast(&new, ELMT(x, 0));
            insertLast(&new, ELMT(x, 1));
            sort(&new, true);

    }
    
    for (i = 0; i < listLength(new); i++) {
        printf("%d", ELMT(new, i));
        if (i != listLength(new) - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
