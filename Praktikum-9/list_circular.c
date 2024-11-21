#include <stdio.h>

#include "list_circular.h"

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    Address p = (Address) malloc(sizeof(ElmtList));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P) {
    free(P);
}

Address search(List l, ElType val) {
    Address p = FIRST(l);
    if (!isEmpty(l)) {
        while (NEXT(p) != FIRST(l)) {
            if (INFO(p) == val) {
                return p;
            }
            p = NEXT(p);
        }
        if (INFO(p) == val) {
            return p;
        }
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
    Address q = FIRST(l);
    if (!isEmpty(l)) {
        while (NEXT(q) != FIRST(l)) {
            if (q == p) {
                return true;
            }
            q = NEXT(q);
        }
        if (q == p) {
            return true;
        }
    }
    return false;
}

void insertFirst(List *l, ElType val) {
    Address p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
            NEXT(p) = p;
        } else {
            Address q = FIRST(*l);
            while (NEXT(q) != FIRST(*l)) {
                q = NEXT(q);
            }
            NEXT(q) = p;
            NEXT(p) = FIRST(*l);
            FIRST(*l) = p;
        }
    }
}

void insertLast(List *l, ElType val) {
    Address p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
            NEXT(p) = p;
        } else {
            Address q = FIRST(*l);
            while (NEXT(q) != FIRST(*l)) {
                q = NEXT(q);
            }
            NEXT(q) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType * val) {
    Address p = FIRST(*l);
    *val = INFO(p);
    if (NEXT(p) == FIRST(*l)) {
        FIRST(*l) = NULL;
    } else {
        Address q = FIRST(*l);
        while (NEXT(p) != FIRST(*l)) {
            p = NEXT(p);
        }
        FIRST(*l) = NEXT(q);
        NEXT(p) = FIRST(*l);
        deallocate(q);
    }
}

void deleteLast(List *l, ElType * val) {
    Address p = FIRST(*l);
    if (NEXT(p) == FIRST(*l)) {
        *val = INFO(p);
        FIRST(*l) = NULL;
    } else {
        Address q;
        while (NEXT(p) != FIRST(*l)) {
            q = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        NEXT(q) = FIRST(*l);
        deallocate(p);
    }
}

void displayList(List l) {
    Address p = FIRST(l);
    printf("[");
    if (!isEmpty(l)) {
        while (NEXT(p) != FIRST(l)) {
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != FIRST(l)) {
                printf(",");
            }
        }
        printf("%d", INFO(p));
    }
    printf("]");
}