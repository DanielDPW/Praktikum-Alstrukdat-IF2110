#include <stdio.h>

#include "mesinkarakter.h"
#include "mesinkata.h"

const int MAXLENGTH = 15;

boolean assessWord(Word x) {
    int length = x.Length;
    if (length > MAXLENGTH) {
        return false;
    }
    int num = 0;
    int count = 0;
    boolean enteredNum = false;
    for (int i = 0; i < length; i++) {
        if (x.TabWord[i] != '0' && x.TabWord[i] != '1' && x.TabWord[i] != '2' && x.TabWord[i] != '3' && x.TabWord[i] != '4' && x.TabWord[i] != '5' && x.TabWord[i] != '6' && x.TabWord[i] != '7' && x.TabWord[i] != '8' && x.TabWord[i] != '9' && x.TabWord[i] != '@') {
            return false;
        } else if (x.TabWord[i] == '@') {
            num = 0;
            count++;
            if (enteredNum) {
                enteredNum = false;
            } else {
                return false;
            }
        } else if (x.TabWord[i] == '0' || x.TabWord[i] == '1' || x.TabWord[i] == '2' || x.TabWord[i] == '3' || x.TabWord[i] == '4' || x.TabWord[i] == '5' || x.TabWord[i] == '6' || x.TabWord[i] == '7' || x.TabWord[i] == '8' || x.TabWord[i] == '9') {
            if (!enteredNum && x.TabWord[i] == '0' && (i + 1 < length && x.TabWord[i + 1] != '@')) {
                return false;
            } else {
                enteredNum = true;
            }
            if (x.TabWord[i] == '0') {
                num = 10 * num;
            } else if (x.TabWord[i] == '1') {
                num = 10 * num + 1;
            } else if (x.TabWord[i] == '2') {
                num = 10 * num + 2;
            } else if (x.TabWord[i] == '3') {
                num = 10 * num + 3;
            } else if (x.TabWord[i] == '4') {
                num = 10 * num + 4;
            } else if (x.TabWord[i] == '5') {
                num = 10 * num + 5;
            } else if (x.TabWord[i] == '6') {
                num = 10 * num + 6;
            } else if (x.TabWord[i] == '7') {
                num = 10 * num + 7;
            } else if (x.TabWord[i] == '8') {
                num = 10 * num + 8;
            } else if (x.TabWord[i] == '9') {
                num = 10 * num + 9;
            }

            if (num > 255) {
                return false;
            }
        }
    }
    return enteredNum && count == 3;
}

int main (void) {
    
    STARTWORD();
    while (!EndWord) {
        if (assessWord(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");

}