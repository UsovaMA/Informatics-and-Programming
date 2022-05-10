#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#define R 5

int main()
{
    int n, i, d, k, Bufer;
    int a[R];

    setlocale(LC_ALL, "Rus");
    srand(time(0));
    
    printf ("Сдвиг: \n");
    scanf_s("%d", &n);
    printf ("Массив: a\n");
    for (i = 0; i < R; i++)
    {

        a[i] = rand() % 200 - 100;;
        printf("%d ", a[i]);
    }

    printf("\nПеревернутый массив:\n", a[i]);
   
   
    int rev = 0;
    for (i = 0; i < R / 2; i++) {
        rev = a[i];
        a[i] = a[R - i - 1];
       a[R - i - 1] = rev;
    }

    for (i = R - 1; i > -1; i--)
        {
            printf("%d  ", a[i]);

        }
    
    printf("\n\nНовый массив:\n");
    for (i = 0; i < R; i++)
        printf("%d ", a[i]);
    return 0;

}