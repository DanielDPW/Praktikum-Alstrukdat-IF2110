#include <stdio.h>

#include "listlinier.h"

int main(void) {
    int x, min, max;
    List l;

    CreateList(&l);
    do {
        scanf("%d", &x);
        if (x != -9999) {
            if (isEmpty(l)) {
                insertFirst(&l, x);
                min = x;
                max = x;
            } else {
                if (x >= max) {
                    insertLast(&l, x);
                    max = x;
                } else if (x <= min) {
                    insertFirst(&l, x);
                    min = x;
                } else {
                    int i = length(l) - 1;
                    while (getElmt(l, i) > x) {
                        i--;
                    }
                    insertAt(&l, x, i + 1);
                }
            }
        }
    } while (x != -9999);
    displayList(l);
}