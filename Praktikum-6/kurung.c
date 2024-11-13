#include <stdio.h>

#include "stack.h"

int main(void) {
    int n;
    scanf("%d\n", &n);
    Stack S;
    CreateEmpty(&S);
    for (int i = 0; i < n; i++) {
        char c;
        char x;
        scanf("%c", &c);
        if (c == '{' || c == '(' || c == '[') {
            Push(&S, c);
        } else if (c == '}' && InfoTop(S) == '{') {
            Pop(&S, &x);
        } else if (c == ']' && InfoTop(S) == '[') {
            Pop(&S, &x);
        } else if (c == ')' && InfoTop(S) == '(') {
            Pop(&S, &x);
        } else {
            Push(&S, c);
        }
    }
    if (!IsEmpty(S)) {
        printf("Invalid\n");
    } else {
        printf("Valid\n");
    }
    return 0;
}