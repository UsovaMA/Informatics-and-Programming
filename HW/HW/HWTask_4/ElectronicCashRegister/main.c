#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define ARRSIZE 4

void producti(int* sht)
{
	printf("\n------------------------------------------------------------------------------\n");
	printf("RTX3060         ����� ���: %d", sht[0]);
	printf("\n------------------------------------------------------------------------------\n");
	printf("RadRX6600       ����� ���: %d", sht[1]);
	printf("\n------------------------------------------------------------------------------\n");
	printf("Gigabyte        ����� ���: %d", sht[2]);
	printf("\n------------------------------------------------------------------------------\n");
	printf("ASUSROG         ����� ���: %d", sht[3]);
	printf("\n------------------------------------------------------------------------------\n\n");
}

void info(float sale, int count, float price_sale)
{
	printf("\n\t���������� ������                            %0.1f %%", sale);
	printf("\n\t����������                                   %d ��.", count);
	printf("\n\t��������� � ������ ������                   %0.1f ���.", price_sale);
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));

	int fs, option = 0, shtrihr, sht_stop = 0, f;
	float itog = 0;


	char* tovar[ARRSIZE];

	tovar[0] = "RTX3060";
	tovar[1] = "RadRX6600";
	tovar[2] = "Gigabyte";
	tovar[3] = "ASUSROG";

	int* flag;
	flag = (float*)malloc(ARRSIZE * sizeof(float));

	int* count;
	count = (float*)malloc(ARRSIZE * sizeof(float));

	int* sht;
	sht = (float*)malloc(ARRSIZE * sizeof(float));

	int* price;
	price = (float*)malloc(ARRSIZE * sizeof(float));

	price[0] = 60000;
	price[1] = 50000;
	price[2] = 20000;
	price[3] = 25000;

	float* sale;
	sale = (float*)malloc(ARRSIZE * sizeof(float));

	float* prices;
	prices = (float*)malloc(ARRSIZE * sizeof(float));

	for (int i = 0; i < ARRSIZE; i++)
	{
		sale[i] = rand() % 50;
		prices[i] = price[i] * (1 - (sale[i] / 100));
		sht[i] = 0;
		flag[i] = 0;
	}

	int** shtrih = NULL;
	shtrih = (int**)malloc(ARRSIZE * sizeof(int*));
	for (int i = 0; i < ARRSIZE; i++)
		shtrih[i] = (int*)malloc(ARRSIZE * sizeof(int));

	printf("����� ���������� � ������������� ��� ����������\n\n");
	printf("������ �������: \n");

	sht_stop = 1000;
	for (int i = 0; i < ARRSIZE; i++) {
		for (int j = 0; j < ARRSIZE; j++)
		{
			shtrih[i][j] = rand() % 9 + 1;
			sht[i] = (shtrih[i][j] * sht_stop) + sht[i];
			sht_stop /= 10;
		}
		sht_stop = 1000;
	}

	producti(sht);

	printf("��� ���� ��� �� ����������� ����� ������� - <1>\n");
	printf("��� ���� ��� �� ������� �������� ���������������� ������ ������� - <2>\n");
	printf("��� ���� ��� �� �������� ������ � ������ � ��� ������� -<3>\n");
	printf("��� ���� ��� �� ������������ ��� �� ������� ������� - <4>\n");
	printf("��� ���� ��� �� ���������� �������� ����� � ������ ������� - <5>\n");
	printf("��� ���� ��� �� ���������� ������ ������� - <6>\n");
	printf("\n");
	do
	{
		printf("\n------------------------------------------------------------------------------");
		printf("\n������� �����:");
		scanf_s("%d", &option);


		switch (option)
		{
		case 1:
		{
			do
			{
				fs = 0;
				printf("\n������� ����� ���:");
				scanf_s("%d", &shtrihr);

				for (int i = 0; i < ARRSIZE; i++)
				{
					if (shtrihr == sht[i])
					{
						printf("\n����� ������������");
						f = i + 1;
					}
				}

				if (shtrihr == sht[0] && shtrihr == sht[1] && shtrihr == sht[2] && shtrihr == sht[3])
					fs = 1;
			} while (fs == 1);

			break;
		}

		case 2:
		{
			if (f > 0 && f < 5)
			{
				printf("\n%s                  %d ���.", tovar[f - 1], price[f - 1]);
				printf("\n���������� ������              %0.0f %%", sale[f - 1]);
			}
			else
			{
				printf("��� ������ ������������ �����");
			}

			break;
		}

		case 3:
		{
			if (f < 5 && f > 0)
			{
				printf("������� ���������� ���������������� ������, ������� ����� �������� � ���:");
				scanf_s("%d", &count[f - 1]);
				flag[f - 1] = 1;
				printf("\n����� �������� � ���");
			}
			else
			{
				printf("��� ������ ������������ �����");
			}
			break;
		}

		case 4:
		{  printf("\n\t\t���");
		for (int i = 0; i < ARRSIZE; i++)
			if (flag[i] == 1)
			{
				prices[i] = prices[i] * count[i];
				printf("\n%s", tovar[i]);
				info(sale[i], count[i], prices[i]);
			}

		if ((flag[0] == 0) && (flag[1] == 0) && (flag[2] == 0) && (flag[3] == 0))
		{
			printf("\n\t*��� ����*");
		}

		break;
		}

		case 5:
		{
			printf("\n\t\t���(��������)");

			for (int i = 0; i < ARRSIZE; i++)
			{
				if (flag[i] == 1)
				{
					printf("\n%s", tovar[i]);
					info(sale[i], count[i], prices[i]);
				}
				else
				{
					prices[i] = 0;
				}
				itog += prices[i];
			}

			printf("\n\n\n�����:                %.1f ������", itog);

			break;
		}

		case 6:
		{
			producti(sht);
			break;
		}
		default:
		{
			printf("������� ������� �����! ������� ����� �� 1 �� 6 ��� ���");
		}
		break;
		}
	} while (option != 5);
	_getch();
	return 0;
}