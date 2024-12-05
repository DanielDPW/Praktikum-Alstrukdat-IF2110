#include <stdio.h>

#include "listrec.h"

List zigzag(List l1, List l2, int x) {
    if (isEmpty(l1)) {
        return l2;
    } else if (isEmpty(l2)) {
        return l1;
    } else {
        if (x % 2 == 1) {
            return konso(zigzag(tail(l1), l2, x + 1), head(l1));
        } else {
            return konso(zigzag(l1, tail(l2), x + 1), head(l2));
        }
    }
}

int main(void) {
    List l1 = NIL;
    List l2 = NIL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l1 = konsb(l1, x);
    }

    l2 = reverseList(l1);

    List l;
    l = zigzag(l1, l2, 1);
    int len = length(l1);
    
    for (int i = 0; i < len; i++) {
        l = deleteLast(l);
    }
    displayList(l);


}