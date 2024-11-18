#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    int i = 0;
    List p = l;
    while(i < idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    int i = 0;
    Address p = *l;
    while(i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    int i = 0;
    List p = l;
    while (p != NULL) {
        if (INFO(p) == val) {
            return i;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    Address p = *l;
    Address q = newNode(val);
    if (q != NULL) {
        if (!isEmpty(p)) {
            while (NEXT(p) != NULL) {
                p = NEXT(p);
            }
            NEXT(p) = q;
        } else {
            insertFirst(l, val);
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    int i = 0;
    Address p = *l;
    Address q = newNode(val);
    if (q != NULL) {
        if (idx != 0) {
            while (i < idx - 1) {
                p = NEXT(p);
                i++;
            }
            NEXT(q) = NEXT(p);
            NEXT(p) = q;
        } else {
            insertFirst(l, val);
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    *val = INFO(*l);
    Address p = *l;
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = *l;
    Address q = NULL;
    while (NEXT(p) != NULL) {
        q = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (q == NULL) {
        *l = NULL;
    } else {
        NEXT(q) = NULL;
    }
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    int i = 0;
    Address p = *l;
    Address q = NULL;
    if (idx != 0) {
        while (i < idx) {
            q = p;
            p = NEXT(p);
            i++;
        }
        *val = INFO(p);
        NEXT(q) = NEXT(p);
        free(p);
    } else {
        deleteFirst(l, val);
    }
}

void displayList(List l) {
    List p = l;
    printf("[");
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        int i = 0;
        List p = l;
        while (p != NULL) {
            p = NEXT(p);
            i++;
        }
        return i;
    }
}

List concat(List l1, List l2) {
    List p;
    List l3;
    CreateList(&l3);
    p = l1;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}