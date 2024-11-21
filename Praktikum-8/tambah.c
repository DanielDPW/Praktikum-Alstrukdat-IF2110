#include <stdio.h>

#include "listlinier.h"

int main(void) {
    int x, y;
    List l1;
    List l2;
    List res;

    CreateList(&l1);
    CreateList(&l2);
    CreateList(&res);
    do {
        scanf("%d", &x);
        if (x != -1) {
            insertFirst(&l1, x);
        }
    } while (x != -1);
    do {
        scanf("%d", &y);
        if (y != -1) {
            insertFirst(&l2, y);
        }
    } while (y != -1);

    int num;
    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
        num = INFO(l1) + INFO(l2);
        if (carry != 0) {
            num += carry;
            carry = 0;
        }
        if (num > 9) {
            carry = num / 10;
            num = num % 10;
        }
        insertFirst(&res, num);
        l1 = NEXT(l1);
        l2 = NEXT(l2);
    }
    while (l1 != NULL) {
        num = INFO(l1);
        if (carry != 0) {
            num += carry;
            carry = 0;
        }
        if (num > 9) {
            carry = num / 10;
            num = num % 10;
        }
        insertFirst(&res, num);
        l1 = NEXT(l1);
    }

    while (l2 != NULL) {
        num = INFO(l2);
        if (carry != 0) {
            num += carry;
            carry = 0;
        }
        if (num > 9) {
            carry = num / 10;
            num = num % 10;
        }
        insertFirst(&res, num);
        l2 = NEXT(l2);
    }
    if (carry != 0) {
        insertFirst(&res, carry);
    }
    int val;
    while (INFO(res) == 0 && NEXT(res) != NULL) {
        deleteFirst(&res, &val);
    }
    
    List p = res;
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}