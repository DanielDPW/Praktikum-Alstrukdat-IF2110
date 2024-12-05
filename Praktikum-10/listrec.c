#include <stdio.h>
#include <stdlib.h>

#include "listrec.h"

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return !isEmpty(l) && NEXT(l) == NIL;
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        Address p = newNode(e);
        if (p != NIL) {
            return p;
        } else {
            return NIL;
        }
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return length(tail(l)) + 1;
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        return (head(l) == x) || isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx) {
    if (idx == 0) {
        return konso(l, e);
    } else {
        return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l) {
    return tail(l);
}

List deleteAt(List l, int idx) {
    if (idx == 0) {
        return tail(l);
    } else {
        return konso(deleteAt(tail(l), idx - 1), head(l));
    }
}

List deleteLast(List l) {
    if (isOneElmt(l)) {
        return NIL;
    } else {
        return konso(deleteLast(tail(l)), head(l));
    }
}

List reverseList (List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konsb(reverseList(tail(l)), head(l));
    }
}

void splitOddEven (List l, List *l1, List *l2) {
    if (!isEmpty(l)) {
        if (head(l) % 2 == 0) {
            splitOddEven(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else if (head(l) % 2 == 1) {
            splitOddEven(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX (List l, int x, List *l1, List *l2) {
    if (x == 0) {
        *l2 = concat(*l2, l);
    } else {
        splitOnX(tail(l), x - 1, l1, l2);
        *l1 = konso(*l1, head(l));
    }
}
ElType getMiddle(List l) {
    Address p = l;
    Address q = l;

    while (q != NULL && tail(q) != NULL) {
        p = tail(p);
        q = tail(tail(q));
    }
    return head(p);
}
