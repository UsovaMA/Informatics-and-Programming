#include<stdio.h>
#include <math.h>
#include <locale.h>
main()
{
    int m = 0, n;
    setlocale(LC_ALL, "Russian");
    scanf_s("%d", &n);
    while (n)
    {
        m = 10 * m + n % 10;
        n /= 10;
    }
    printf("инверсия числа n=%d",m);
}