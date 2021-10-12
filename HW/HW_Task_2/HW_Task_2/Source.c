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
        srand(time(0));
        rnd = rand() % 1000;

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
            int rnd2;
            srand(time(0));
            rnd2 = rand() % 1000;
            printf(" Число %d ? ", rnd2);
            scanf_s("%ch", &znak);

            if (znak == '=')
            {
                printf(" Угадали ! ");
                cnt++;
                printf("Было попыток: %d", cnt);
            }
            else
            {
                if (znak == '>')
                {
                   // ???
                    cnt++;
                }
                if (znak == '<')
                {
                   // ???
                    cnt++;
                }
            }

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