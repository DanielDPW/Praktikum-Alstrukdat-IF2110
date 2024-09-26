#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    

    while (a <= b)
    {
        printf("%d", a);
        if ((a % 2) == 1)
        {
            a += 1;
        } else
        {
            a *= 2;
        }
        if (!(a > b)){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}