#include <stdio.h>

#include "list_circular.h"

boolean clockwise(List l, int min) {
    Address p = search(l, min);
    Address q = p;
    while (NEXT(q) != p) {
        if(INFO(NEXT(q)) - INFO(q) != 1) {
            return false;
        }
        q = NEXT(q);
    }
    return true;
}

boolean counter_clockwise(List l, int max) {
    Address p = search(l, max);
    Address q = p;
    while (NEXT(q) != p) {
        if(INFO(q) - INFO(NEXT(q)) != 1) {
            return false;
        }
        q = NEXT(q);
    }
    return true;
}

int main(void) {
    int n, x, min, max;
    scanf("%d", &n);

    List l;
    CreateList(&l);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertLast(&l, x);
        if (i == 0) {
            min = x;
            max = x;
        } else {
            if (min > x) {
                min = x;
            }
            if (max < x) {
                max = x;
            }
        }
    }

    if(clockwise(l, min) || counter_clockwise(l, max)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}