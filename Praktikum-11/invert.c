#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    if (!isTreeEmpty(*p)) {
        BinTree newRight = LEFT(*p);
        BinTree newLeft = RIGHT(*p);
        LEFT(*p) = newLeft;
        RIGHT(*p) = newRight;
        invertTree(&newLeft);
        invertTree(&newRight);
    }
}

