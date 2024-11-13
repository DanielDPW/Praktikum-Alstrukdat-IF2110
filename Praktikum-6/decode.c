#include <stdio.h>
#include "stack.h"

int main() {
    int N, i;
    char ch;

    Stack s;
    CreateEmpty(&s);
    Stack temp;
    CreateEmpty(&temp);

    scanf("%d", &N);
    char arr[N];

    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);
        arr[i] = ch;
    }
    char val;
    for (i = 0; i < N; i++) {
        if (arr[i] != ']') {
            Push(&s, arr[i]);
        } else if (arr[i] == ']') {
            while (InfoTop(s) != '[') {
                Pop(&s, &val);
                Push(&temp, val);
            }
            Pop(&s, &val);
            int num = 0;
            int exp = 1;
            while (!IsEmpty(s) && InfoTop(s) >= '0' && InfoTop(s) <= '9') {
                Pop(&s, &val);
                num = (val - '0') * exp + num;
                exp *= 10;
            }
            int str_length = Top(temp) + 1;
            for (int j = 0; j < num - 1; j++) {
                for (int k = 0; k < str_length; k++) {
                    Push(&temp, temp.T[k]);
                }
            }
            while(!IsEmpty(temp)) {
                Pop(&temp, &val);
                Push(&s, val);
            }
        }
    }
    int length = Top(s) + 1;
    for (i = 0; i < length; i++) {
        printf("%c", s.T[i]);
    }
    printf("\n");
    return 0;
}