#include <stdio.h>
#include <string.h>
#include "mesinkata.h"

boolean compare(Word x, char y[]) {
    if (x.Length != strlen(y)) {
        return false;
    }
    for (int i = 0; i < x.Length; i++) {
        if (x.TabWord[i] != y[i]) {
            return false;
        }
    }
    return true;
}

boolean checkEndNumPunct(Word x) {
    return (x.TabWord[x.Length - 1] == '.');
}

int main(void) {
    STARTWORD();

    int num = 0;
    boolean inNum = false;
    Word current;

    while (!EndWord) {
        strcpy(current.TabWord, currentWord.TabWord);
        current.Length = currentWord.Length;
        if (checkEndNumPunct(current)) {
            currentWord.Length--;
        }
        if (compare(current, "nol")) {
            if (!inNum) {
                inNum = true;
            }
        } else if (compare(current, "satu")) {
            if (!inNum) {
                inNum = true;
            }
            num += 1;
        } else if (compare(current, "dua")) {
            if (!inNum) {
                inNum = true;
            }
            num += 2;
        } else if (compare(current, "tiga")) {
            if (!inNum) {
                inNum = true;
            }
            num += 3;
        } else if (compare(current, "empat")) {
            if (!inNum) {
                inNum = true;
            }
            num += 4;
        } else if (compare(current, "lima")) {
            if (!inNum) {
                inNum = true;
            }
            num += 5;
        } else if (compare(current, "enam")) {
            if (!inNum) {
                inNum = true;
            }
            num += 6;
        } else if (compare(current, "tujuh")) {
            if (!inNum) {
                inNum = true;
            }
            num += 7;
        } else if (compare(current, "delapan")) {
            if (!inNum) {
                inNum = true;
            }
            num += 8;
        } else if (compare(current, "sembilan")) {
            if (!inNum) {
                inNum = true;
            }
            num += 9;
        } else if (compare(current, "sepuluh") || compare(current, "belas")) {
            if (!inNum) {
                inNum = true;
            }
            num += 10;
        } else if (compare(current, "sebelas")) {
            if (!inNum) {
                inNum = true;
            }
            num += 11;
        } else if (compare(current, "puluh")) {
            if (!inNum) {
                inNum = true;
            }
            num += 10 * (num % 10) - (num % 10);
        } else if (compare(current, "seratus")) {
            if (!inNum) {
                inNum = true;
            }
            num += 100;
        } else if (compare(current, "ratus")) {
            if (!inNum) {
                inNum = true;
            }
            num += 100 * (num % 100) - (num % 100);
        } else {
            if (inNum) {
                printf("%d ", num);
                num = 0;
                inNum = false;
            }
        }

        ADVWORD();
        if (!inNum) {
            int len = current.Length;
            for (int i = 0; i < len; i++) {
                printf("%c", current.TabWord[i]);
            }
            if (!EndWord) {
                printf(" ");
            }
        }
        
    }
    if (inNum) {
        printf("%d", num);
        num = 0;
        inNum = false;
    }
    
    printf("\n");
    return 0;
}
