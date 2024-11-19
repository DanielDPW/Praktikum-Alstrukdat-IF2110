#include <stdio.h>

#include "prioqueue.h"

int main (void) {
    long long res = 0;

    int N, num;
    scanf("%d", &N);

    PrioQueue pq1;
    PrioQueue pq2;
    CreatePrioQueue(&pq1);
    CreatePrioQueue(&pq2);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        enqueue(&pq1, num);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        enqueue(&pq2, num);
    }

    for (int i = 0; i < N; i++) {
        int val1, val2;
        dequeue(&pq1, &val1);
        dequeue(&pq2, &val2);
        res += (long long) val1 * (long long) val2;
    }

    printf("%lld\n", res);
}