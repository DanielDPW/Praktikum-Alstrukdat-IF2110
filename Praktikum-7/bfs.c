#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;

int main()
{
    int N;
    scanf("%d", &N);

    char arr[MXN][MXN];
    boolean visited[MXN][MXN];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    
    Queue q;
    CreateQueue(&q);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'A') {
                ElType val;
                val.row = i;
                val.col = j;
                visited[i][j] = true;
                enqueue(&q, val);
            }
        }
    }
    int count = 0;
    boolean found = false;
    
    ElType leftover;
    while (!isEmpty(q)) {
        int qlen = length(q);
        for (int s = 0; s < qlen; s++) {
            int i = HEAD(q).row;
            int j = HEAD(q).col;
            dequeue(&q, &leftover);
            if (arr[i][j] == 'B') {
                found = true;
                break;
            } else {
                if (i != 0 && arr[i - 1][j] != '#' && !visited[i - 1][j]) {
                    ElType val;
                    val.row = i - 1;
                    val.col = j;
                    enqueue(&q, val);
                    visited[i - 1][j] = true;
                }
                if (j != N - 1 && arr[i][j + 1] != '#' && !visited[i][j + 1]) {
                    ElType val;
                    val.row = i;
                    val.col = j + 1;
                    enqueue(&q, val);
                    visited[i][j + 1] = true;
                }
                if (i != N - 1 && arr[i + 1][j] != '#' && !visited[i + 1][j]) {
                    ElType val;
                    val.row = i + 1;
                    val.col = j;
                    enqueue(&q, val);
                    visited[i + 1][j] = true;
                }
                if(j != 0 && arr[i][j - 1] != '#' && !visited[i][j - 1]) {
                    ElType val;
                    val.row = i;
                    val.col = j - 1;
                    enqueue(&q, val);
                    visited[i][j - 1] = true;
                }
            }
        }
        if (!found) {
            count++;
        } 
    }
    if (found) {
        printf("Ya\n");
        printf("%d\n", count);
    } else {
        printf("Tidak\n");
    }
    
    return 0;
}