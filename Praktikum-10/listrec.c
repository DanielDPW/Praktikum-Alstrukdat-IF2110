#include <stdio.h>

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
