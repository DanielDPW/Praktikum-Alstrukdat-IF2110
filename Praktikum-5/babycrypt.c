#include <stdio.h>

#include "mesinkarakter.h"
#include "mesinkata.h"

void printWord(Word x) {
    int length = x.Length;
    for (int i = 0; i < length; i++) {
        printf("%c",x.TabWord[i]);
    }
}

Word caesar (Word x, int shift) {
    int length = x.Length;
    shift = shift % 26;
    for (int i = 0; i < length; i++) {
        if (x.TabWord[i] >= 'a' && x.TabWord[i] <= 'z') {
            if (x.TabWord[i] - shift < 'a') {
                x.TabWord[i] = x.TabWord[i] + (26 - shift);
            } else {
                x.TabWord[i] = x.TabWord[i] - shift;
            }
        } else if (x.TabWord[i] >= 'A' && x.TabWord[i] <= 'Z') {
            if (x.TabWord[i] - shift < 'A') {
                x.TabWord[i] = x.TabWord[i] + (26 - shift);
            } else {
                x.TabWord[i] = x.TabWord[i] - shift;
            }
        }
    }
    return x;
}

int main (void) {
    int shift;
    scanf("%d", &shift);
    STARTWORD();
    while (!EndWord) {
        currentWord = caesar(currentWord,shift);
        printWord(currentWord);
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
}