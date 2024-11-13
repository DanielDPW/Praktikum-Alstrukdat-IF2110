#include <stdio.h>

#include "stack.h"

int main() {
    int N;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %c", &ch);
        if (ch == '+') {
            int val1;
            int val2;
            Pop(&s, &val2);
            Pop(&s, &val1);
            Push(&s, val1);
            Push(&s, val2);
            Push(&s, val1 + val2);
        } else if (ch == 'X') {
            int val;
            Pop(&s, &val);
        } else if (ch == 'S') {
            int sum = 0;
            int val;
            while (!IsEmpty(s)) {
                Pop(&s, &val);
                sum += val;
            }
            Push(&s, sum);
        } else if (ch == 'A') {
            int sum = 0;
            int val;
            int count = 0;
            while (!IsEmpty(s)) {
                Pop(&s, &val);
                sum += val;
                count++;
            }
            if (count > 0) {
                sum = sum / count;
                Push(&s, sum);
            }
        } else {
            Push(&s, ch - '0');
        }
    }
    int res = 0;
    while (!IsEmpty(s)) {
        int val;
        Pop(&s, &val);
        res += val;
    }
    printf("%d\n", res);
    return 0;        
    }