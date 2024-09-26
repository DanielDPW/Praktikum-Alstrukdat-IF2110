#include <stdio.h>

int fibonacci(int n, int a, int b);

int main(void)
{
    int n, a, b;
    do
    {
        scanf("%d %d %d", &n, &a, &b);
    } while (n < 1 || n > 20 || a > b || a < 1 || a > 100 || b < 1 || b > 100);
    
    printf("%d\n", fibonacci(n, a, b));
    return 0;
}

int fibonacci(int n, int a, int b)
{
    if (n == 1)
    {
        return a;
    } else if (n == 2)
    {
        return b;
    } else
    {
        return fibonacci(n - 1, a, b) + fibonacci (n - 2, a, b);
    }
}