#include <stdio.h>

#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
    return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq) {
    return (length(pq) == CAPACITY);
}

int length(PrioQueue pq) {
    if (isEmpty(pq)) {
        return 0;
    } else {
        if ((IDX_TAIL(pq) - IDX_HEAD(pq)) >= 0) {
            return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
        } else {
            return (CAPACITY - (IDX_HEAD(pq) - (IDX_TAIL(pq) + 1)));
        }
    }
}

void enqueue(PrioQueue *pq, ElType val) {
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
        TAIL(*pq) = val;

        int i = IDX_TAIL(*pq);
        while (i != IDX_HEAD(*pq) && (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY] < (*pq).buffer[i]) {
            // Tukar elemen
            ElType temp = (*pq).buffer[i];
            (*pq).buffer[i] = (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY];
            (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY] = temp;

            i = (i - 1 + CAPACITY) % CAPACITY;
        }
    }
}

void dequeue(PrioQueue *pq, ElType *val) {
    *val = HEAD(*pq);
    if (length(*pq) == 1)
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
    }
}

void displayPrioQueue(PrioQueue pq) {
    printf("[");
    if (!isEmpty(pq)) {
        int i;
        int len = length(pq);
        for (i = 0; i < len; i++) {
            printf("%d", HEAD(pq));
            IDX_HEAD(pq) = (IDX_HEAD(pq) + 1) % CAPACITY;
            if (i < len - 1) {
                printf(",");
            }
        }
    }
    printf("]\n");
}