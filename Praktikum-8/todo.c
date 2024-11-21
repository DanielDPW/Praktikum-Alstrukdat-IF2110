#include <stdio.h>

#include "listlinier.h"

int main(void) {
    char c;
    int id, val;
    List l;
    CreateList(&l);
    do {
        scanf(" %c", &c);
        if (c == 'P') {
            scanf("%d", &id);
            insertFirst(&l, id);
            
        } else if (c == 'I') {
            scanf("%d", &id);
            insertLast(&l, id);
            
        } else if (c == 'C') {
            if (!isEmpty(l)) {
                deleteFirst(&l, &val);
            }
            
        } else if (c == 'D') {
            scanf("%d", &id);
            if (!isEmpty(l)) {
                int idx = indexOf(l, id);
                if (idx != IDX_UNDEF) {
                    deleteAt(&l, idx, &val);
                }
            }
            
        } 
    } while (c != 'X');

    displayList(l);
}