#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    Address p = newTreeNode(root);
    if (p != NULL) {
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
    Address p = (Address) malloc(sizeof(BinTree));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
}

void deallocTreeNode (Address p) {
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    return p == NULL;
}

boolean isOneElmt (BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft (BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL;
}

boolean isUnerRight (BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL;
}

boolean isBinary (BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL;
}

void printPreorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p) {
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTree(BinTree p, int h) {
    static int lvl = 0;
    if (!isTreeEmpty(p)) {
        for (int i = 0; i < h * lvl; i++) {
            printf(" ");
        }
        lvl++;
        printf("%d\n", ROOT(p));
        printTree(LEFT(p), h);
        printTree(RIGHT(p), h);
        lvl--;
    }
}