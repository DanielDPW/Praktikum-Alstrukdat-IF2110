#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    if (!(isEmpty(l1) && isEmpty(l2))) {
        if (isEmpty(l1)) {
            *res = l2;
        } else if (isEmpty(l2)) {
            *res = l1;
        } else {
            if (head(l1) < head(l2)) {
                mergeSortedUnique(tail(l1), l2, res);
                *res = konso(*res, head(l1)); 
            } else if (head(l1) == head(l2)) {
                mergeSortedUnique(tail(l1), tail(l2), res);
                *res = konso(*res, head(l1)); 
            } else {
                mergeSortedUnique(l1, tail(l2), res);
                *res = konso(*res, head(l2));
            }
        }
    }
}