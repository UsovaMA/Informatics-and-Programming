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
    printf("�������� ����� (1 ��� 2) : ");
    scanf_s("%d", &mode);

    switch (mode)
    {
    case 1:
    {
        srand(time(NULL));
        rnd = rand()%1000;

        do
        {
            printf("������� ����� ���������� ���������� (�� 1 �� 1000) : \n");
            scanf_s("%d", &otv);

            if (rnd == otv)
            {
                printf(" �������\n");
                cnt++;
                printf("���� %d �������\n", cnt);
            }
            else
            {
                if (rnd < otv)
                {
                    printf(" ������ \n");
                    cnt++;
                }
                else if (rnd > otv)
                {
                 printf(" ������ \n");
                 cnt++;
                }
                
            }
        } while (rnd != otv);
    } break;

    case 2:
    {
        printf("��������� ����� (�� 1 �� 1000), ���� ����� ���������� ������� ����� ������ ������� > ���� ������ < � = ���� ����� ������ \n");
        do
        {
            srand(time(NULL));
            int rnd2 = rand()%1000;
            printf(" ����� %d ? \n", rnd2);
            scanf_s("%d", &znak);

            if (znak == '=')
            {
                printf(" ������� ! ");
                cnt++;
                printf("���� �������: %d", cnt);
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
        printf(" �������� ����� 1 ��� 2 ! ");
    }
    break;
    }
    return 0;
}  