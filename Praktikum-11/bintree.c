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

boolean isEqual(BinTree p1, BinTree p2) {
    if (isTreeEmpty(p1) && isTreeEmpty(p2)) {
        return true;
    } else if (!isTreeEmpty(p1) && !isTreeEmpty(p2)) {
        return ROOT(p1) == ROOT(p2) && (isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2)));
    } else {
        return false;
    }
}

int getMaximumDepth(BinTree p) {
    if (isTreeEmpty(p)) {
        return 0;
    } else {

        int left = getMaximumDepth(LEFT(p)) + 1;
        int right = getMaximumDepth(RIGHT(p)) + 1;

        if (left >= right) {
            return left;
        } else {
            return right;
        }
    }
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end) {
    if (start > end) {
        return NULL;
    }
    BinTree p, pleft, pright;
    int mid = (start + end) / 2;
    pleft = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
    pright = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
    return NewTree(arr[mid], pleft, pright);
}

int countNodes(BinTree p) {
    if (isTreeEmpty(p)) {
        return 0;
    } else if(isUnerLeft(p)) {
        return countNodes(LEFT(p)) + 1;
    } else if(isUnerRight(p)) {
        return countNodes(RIGHT(p)) + 1;
    } else {
        return countNodes(LEFT(p)) + countNodes(RIGHT(p)) + 1;
    }
}

void printPathToElement(BinTree p, ElType target) {
    static int path[100];
    static int depth = 0;
    static boolean found = false;

    if (isTreeEmpty(p)) {
        return;
    }

    path[depth] = ROOT(p);
    depth++;

    if (ROOT(p) == target) {
        for (int i = 0; i < depth; i++) {
            if (i > 0) {
                printf(" -> ");
            }
            printf("%d", path[i]);
        }
        found = true;
        printf("\n");
        return;
    }

    printPathToElement(LEFT(p), target);
    printPathToElement(RIGHT(p), target);

    depth--;

    if (!found && depth == 0) {
        printf("-1\n");
        return;
    }
}
