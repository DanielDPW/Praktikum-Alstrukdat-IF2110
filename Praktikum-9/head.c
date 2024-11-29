#include <stdio.h>

#include "list_circular.h"

int main(void) {
    int n, x;
    scanf("%d", &n);

    List l;
    CreateList(&l);

    int max;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertLast(&l, x);
        if (i == 0) {
            max = x;
        } else {
            if (max < x) {
                max = x;
            }
        }
        
    }
    FIRST(l) = search(l, max);
    displayList(l);
}

