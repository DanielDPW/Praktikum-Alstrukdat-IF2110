#include <stdio.h>

#include "stack.h"

const int MXN = 1e4 + 7;

int main() {
    int N;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);

    infotype arr[N];
    infotype left[N];
    infotype right[N];
    infotype res[N];
    infotype val;
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        arr[i] = val;
        left[i] = Nil;
        right[i] = N;
        res[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        while (!IsEmpty(s) && arr[InfoTop(s)] >= arr[i]) {
            Pop(&s, &val);
        }
        if (!IsEmpty(s)) {
            left[i] = InfoTop(s);
        }
        Push(&s, i);
    }
    Top(s) = Nil;
    for (int i = N - 1; i >= 0; i--) {
        while (!IsEmpty(s) && arr[InfoTop(s)] >= arr[i]) {
            Pop(&s, &val);
        }
        if (!IsEmpty(s)) {
            right[i] = InfoTop(s);
        }
        Push(&s, i);
    }

    for (int i = 0; i < N; i++) {
        int x = right[i] - left[i] - 2;
        res[x] = res[x] >= arr[i] ? res[x] : arr[i];
    }

    for (int i = N - 2; i >= 0; i--) {
        res[i] = res[i] >= res[i + 1] ? res[i] : res[i + 1];
    }

    for (int i = 0; i < N; i++) {
        printf("%d", res[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}