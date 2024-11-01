#include <stdio.h>

#include "mesinkarakter.h"
#include "mesinkata.h"

void printWord(Word x) {
    int length = x.Length;
    for (int i = 0; i < length; i++) {
        printf("%c",x.TabWord[i]);
    }
}

Word putar (Word currentWord) {
    int length = currentWord.Length;

    char reversed[length];

    for (int i = 0; i < length; i++) {
        reversed[length - i - 1] = currentWord.TabWord[i];
    }
    for (int i = 0; i < length; i++){
        currentWord.TabWord[i] = reversed[i];
    }
    return currentWord;
}

int main (void) {
    STARTWORD();
    int count = 1;
    while (!EndWord) {
        if ((count % 2) == 1) {
            currentWord = putar(currentWord);
        }
        printWord(currentWord);
        count++;
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
}