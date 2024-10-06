#include <stdio.h>

#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int i = 0;
    while ((ELMT(l, i) != MARK) && (i < CAPACITY)) {
        i++;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    int length = listLength(l);
    if (!length) {
        return IDX_MIN;
    }
    else {
        return length - 1;
    }
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return ((i >= 0) && (i <= CAPACITY - 1));
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return ((i >= getFirstIdx(l)) && (i <= getLastIdx(l)));
}

boolean isEmpty(ListStatik l) {
    return (!listLength(l));
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

void readList (ListStatik *l) {
    int n;
    
    do {
        scanf("%d", &n);
    } while (n > CAPACITY || n < 0);
    

    CreateListStatik(l);
    if (n > 0 && n <= CAPACITY) {
        int i;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void printList(ListStatik l) {
    int length = listLength(l);

    printf("[");

    int i;
    for (i = 0; i < length; i++) {
        printf("%d", ELMT(l, i));
        if (i < length - 1) {
            printf(",");
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    int length = listLength(l1);

    ListStatik l;
    CreateListStatik(&l);

    int i;
    if (plus) {
        for (i = 0; i < length; i++) {
            ELMT(l,i) = ELMT(l1, i) + ELMT(l2,i);
        }
    }
    else {
        for (i = 0; i < length; i++) {
            ELMT(l,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    else {
        int length = listLength(l1);
        int i = 0;

        while (i < length) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                return false;
            }
            i++;
        }
        return true;
    }
}

int indexOf(ListStatik l, ElType val) {
    int length = listLength(l);

    if (!length) {
        return IDX_UNDEF;
    }
    else {
        int i;
        for (i = 0; i < length; i++) {
            if (ELMT(l, i) == val) {
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int length = listLength(l);

    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    int i;
    for (i = 0; i < length; i++) {
        if (ELMT(l,i) > *max) {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min) {
            *min = ELMT(l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val) {
    insertAt(l, val, getFirstIdx(*l));
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    int length = listLength(*l);

    int i;
    for (i = length; i > idx; i--) {
        ELMT(*l,i) = ELMT(*l, i - 1);
    }
    ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
    int length = listLength(*l);
    insertAt(l, val, length);
}

void deleteFirst(ListStatik *l, ElType *val) {
    deleteAt(l, val, getFirstIdx(*l));
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    int length = listLength(*l);
    *val = ELMT(*l, idx);

    int i;
    for (i = idx; i < length - 1; i++) {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, length - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
    deleteAt(l, val, getLastIdx(*l));
}

void sortList(ListStatik *l, boolean asc) {
    int length = listLength(*l);
    if (length > 0) {
        int i;
        for (i = 1; i < length; i++) {
            int key = ELMT(*l, i);
            int j = i - 1;
            if (asc) {
                while (j >= 0 && ELMT(*l, j) > key) {
                    ELMT(*l, j + 1) = ELMT(*l, j);
                    j--;
                }
            }
            else {
                while (j >= 0 && ELMT(*l, j) < key) {
                    ELMT(*l, j + 1) = ELMT(*l, j);
                    j--;
                }
            }
            ELMT(*l, j + 1) = key;
        }
    }
}
