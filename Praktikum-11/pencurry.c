#include <stdio.h>
#include "bintree.h"

int mencurry(BinTree T) {
    if (isTreeEmpty(T)) {
        return 0;
    } else if (isOneElmt(T)) {
        return ROOT(T);
    } else {
        int curi = ROOT(T);
        if (!isTreeEmpty(LEFT(T)) && !isTreeEmpty(LEFT(LEFT(T)))) {
            curi += mencurry(LEFT(LEFT(T)));
        }
        if (!isTreeEmpty(LEFT(T)) && !isTreeEmpty(RIGHT(LEFT(T)))) {
            curi += mencurry(RIGHT(LEFT(T)));
        }
        if (!isTreeEmpty(RIGHT(T)) && !isTreeEmpty(LEFT(RIGHT(T)))) {
            curi += mencurry(LEFT(RIGHT(T)));
        }
        if (!isTreeEmpty(RIGHT(T)) && !isTreeEmpty(RIGHT(RIGHT(T)))) {
            curi += mencurry(RIGHT(RIGHT(T)));
        }
        int notcuri = 0;
        if (!isTreeEmpty(LEFT(T))) {
            notcuri += mencurry(LEFT(T));
        }
        if (!isTreeEmpty(RIGHT(T))) {
            notcuri += mencurry(RIGHT(T));
        }

        if (curi >= notcuri) {
            return curi;
        } else {
            return notcuri;
        }
    }
}
