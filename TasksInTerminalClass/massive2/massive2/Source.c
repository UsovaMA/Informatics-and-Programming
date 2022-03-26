#include <stdio.h>
#include <conio.h>
#include<locale.h>
#define Num 7
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    setlocale(LC_ALL, "ru");
    int Mass[Num], i = 0, k = 0, Mass2[Num], max;

    for (i = 0; i < Num; ++i)
    {
        printf_s(" \n¬ведите %d число : ", i + 1);
        scanf_s("%d", &Mass[i]);
    }
    max = Mass[0];
    for (i = 1; i < Num; ++i)
    {
        if (Mass[i] > max)
        {
            max = Mass[i];
            k = i;
        }
    }
    printf_s("\n");
    for (i = 0; i < Num; i++)
    {
        Mass2[i] = Mass[i];
        printf_s(" %d ", Mass[i]);
    }

    for (i = 0; i < k; i++)
    {
        Mass[i] = Mass2[i + Num - k];
    }

    for (i = k; i < Num; i++)
    {
        Mass[i] = Mass2[i - k];
    }

    printf_s("\n");
    for (i = 0; i < Num; i++)
    {
        printf_s("%d ", Mass[i]);
    }

    _getch();
    return 0;
}