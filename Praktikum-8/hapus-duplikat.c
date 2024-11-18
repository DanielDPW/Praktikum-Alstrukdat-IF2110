#include <stdio.h>

#include "hapus-duplikat.h"

List hapusDuplikat(List l) {
    List p = l;
    List q;
    CreateList(&q);
    int val;
    int dupe;
    while (p != NULL) {
        if (NEXT(p) != NULL && INFO(p) == INFO(NEXT(p))) {
            dupe = INFO(p);
            while (p != NULL && INFO(p) == dupe) {
                deleteAt(&l, indexOf(l, dupe), &val);
                p = NEXT(p);
            }
        } else {
            p = NEXT(p);
        }
    }
    p = l;
    while (p != NULL) {
        insertFirst(&q, INFO(p));
        p = NEXT(p);
    }
    return q;
}
