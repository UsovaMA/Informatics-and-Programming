#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main() 
{
    setlocale(LC_ALL, "rus");
    int rnd, otv, mode, cnt = 0;      
    char znak;   
    printf("Выберите режим (1 или 2) : ");
    scanf_s("%d", &mode);

    switch (mode)
    {
    case 1:
    {
        srand(time(NULL));
        rnd = rand()%1000;

        do
        {
            printf("Введите число загаданное программой (от 1 до 1000) : \n");
            scanf_s("%d", &otv);

            if (rnd == otv)
            {
                printf(" Угадали\n");
                cnt++;
                printf("Было %d попыток\n", cnt);
            }
            else
            {
                if (rnd < otv)
                {
                    printf(" Меньше \n");
                    cnt++;
                }
                else if (rnd > otv)
                {
                 printf(" Больше \n");
                 cnt++;
                }
                
            }
        } while (rnd != otv);
    } break;

    case 2:
    {
        printf("Загадайте число (от 1 до 1000), если число выведенное роботом будет меньше введите > если больше < и = если робот угадал \n");
        do
        {
            srand(time(NULL));
            int rnd2 = rand()%1000;
            printf(" Число %d ? \n", rnd2);
            scanf_s("%d", &znak);

            if (znak == '=')
            {
                printf(" Угадали ! ");
                cnt++;
                printf("Было попыток: %d", cnt);
            }
            else
            /*{
                if (znak == '>')
                {
                    rnd2++;
                    printf("%d \n", rnd2);
                    cnt++;
                }
                if (znak == '<')
                {
                    rnd2--;
                    printf("%d \n", rnd2);
                    cnt++;
                }
            } */

        } while (znak != '=');
    } break;

    default:
    {
        printf(" Выберите режим 1 или 2 ! ");
    }
    break;
    }
    return 0;
}  