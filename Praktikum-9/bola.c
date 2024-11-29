#include <stdio.h>

#include "list_circular.h"

int main(){
    int N;
    scanf("%d", &N);
    
    List l;
    CreateList(&l);

    for(int i = 1; i <= N; i++) {
        insertLast(&l, i);
    }

    Address p = FIRST(l);
    while (NEXT(p) != FIRST(l)) {
        p = NEXT(p);
    }
    Address q = p;
    p = NEXT(q);

    int length = N;
    int x;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &x);
        if (i > 0 && x > 0) {
            x--;
        }
        x = ((x % length) + length) % length;

        for(int j = 0; j < x; j++) {
            p = NEXT(p);
            q = NEXT(q);
        }
        NEXT(q) = NEXT(p);
        p = NEXT(p);
        length--;
    }
    printf("%d\n", INFO(p));
}