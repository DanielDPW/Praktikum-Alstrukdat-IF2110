#include <stdio.h>

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    int i, x, sum;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!(x % k == 0))
        {
            sum += x;
        }
    }
    printf("%d\n", sum);
    return 0;
}