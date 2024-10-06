#include <stdio.h>
#include <stdlib.h>

#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l) {
    if (BUFFER(*l) != NULL) {
        free(BUFFER(*l));
        BUFFER(*l) = NULL;
    }

    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l) {
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return ((i >= getFirstIdx(l)) && (i < CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return ((i >= getFirstIdx(l)) && (i <= getLastIdx(l)));
}

boolean isEmpty(ListDin l) {
    return (!listLength(l));
}

boolean isFull(ListDin l) {
    return NEFF(l) == CAPACITY(l);
}
void readList(ListDin *l) {
    int n;
    
    do {
        scanf("%d", &n);
    } while (n > CAPACITY(*l) || n < 0);

    NEFF(*l) = n;

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l,i));
    }
}

void printList(ListDin l) {
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

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    int length = listLength(l1);

    ListDin l;
    CreateListDin(&l, CAPACITY(l1));
    NEFF(l) = length;
    
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

boolean isListEqual(ListDin l1, ListDin l2) {
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

IdxType indexOf(ListDin l, ElType val) {
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

void extremeValues(ListDin l, ElType *max, ElType *min) {
    int length = listLength(l);

    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    int i;
    for (i = 1; i < length; i++) {
        if (ELMT(l,i) > *max) {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min) {
            *min = ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    int length = listLength(lIn);

    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    int i;
    for (i = 0; i < length; i++) {
        ELMT(*lOut, i) = ELMT(lIn,i);
    }
}

ElType sumList(ListDin l) {
    int length = listLength(l);
    int sum = 0;

    int i;
    for (i = 0; i < length; i++) {
        sum += ELMT(l,i);
    }
    return sum;
}

int countVal(ListDin l, ElType val) {
    int length = listLength(l);
    int count = 0;

    int i;
    for (i = 0; i < length; i++) {
        if (ELMT(l,i) == val) {
            count++;
        }
    }
    return count;
}
void sort(ListDin *l, boolean asc) {
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

void insertLast(ListDin *l, ElType val) {
    if (!isFull(*l)) {
        ELMT(*l, listLength(*l)) = val;
        NEFF(*l)++;
    }
}

void deleteLast(ListDin *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, getLastIdx(*l));
        NEFF(*l)--;
    }
}

void expandList(ListDin *l, int num) {
    ElType *newBuffer;
    newBuffer = realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));

    if (newBuffer != NULL) {
        BUFFER(*l) = newBuffer;
        CAPACITY(*l) += num;
    }
}

void shrinkList(ListDin *l, int num) {
    if (CAPACITY(*l) > num && NEFF(*l) <= (CAPACITY(*l) - num)) {
        ElType *newBuffer;
        newBuffer = realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(ElType));

        if (newBuffer != NULL) {
            BUFFER(*l) = newBuffer;
            CAPACITY(*l) -= num;
        }
    }
}

void compressList(ListDin *l) {
    int diff = CAPACITY(*l) - NEFF(*l);
    if (!!diff) {
        shrinkList(l, diff);
    }
}