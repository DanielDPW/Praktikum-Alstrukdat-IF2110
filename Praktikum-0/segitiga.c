#include <stdio.h>

void whitespace(int n);
void asterisk(int n);

int main(void)
{
    int x;
    do{
        scanf("%d", &x);
    } while (x < 1 || x > 100);

    int i = 0;
    for (i = 0; i < x; i++)
    {
        whitespace(i);
        asterisk(2 * (x - i) - 1);
        printf("\n");
    }
    return 0;
}

void whitespace(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void asterisk(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
}