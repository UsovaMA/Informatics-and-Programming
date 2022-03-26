#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#define SIZE 6
#define X 100


int main()
{
	setlocale(LC_ALL, "ru");
	char item[SIZE][X] =
	{ {" �������� Apple iPhone 13 128GB Midnight "}, {" �������� Apple AirPods Pro with Wireless Case "},
	{" �����-���� Apple Watch Series 7 GPS 41mm Green Alum./Clover Sport "}, {" ������� Apple iPad Air 10.9 Wi-Fi 64GB Rose Gold "},
	{" ������� Apple MacBook Air 13 M1/8/256 Gold "}, {" ��������� ���� Apple Mac Mini M1/8/256 "} };

	int price[SIZE] = { 79999, 18999, 36999, 44149, 89999, 75999 };
	int barcode[SIZE] = { 7131, 8142, 9153, 1164, 1105, 1206 };
	int discount[SIZE] = { 3, 7, 12, 4, 6, 2 };
	int memory[X] = { 0 };

	printf("\n ����������� ����� \n");
	printf("\n ���� �������� : \
		\n\n1. C���������� ����� \
		\n\n2. ������� �������� ���������������� ������ \
		\n\n3. �������� ������ � ������ � ��� \
		\n\n4. ������������ ��� �� ������� \
		\n\n5. ���������� �������� ����� � ������ \
		\n\n0. ��������� ����� ��.����� \n");
	int mode, b_code, n = 0, s_code, s = 0;
	do
	{
		printf("\n �������� ��� �������� : \n");
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			printf("������� �����-���: ");
			scanf_s("%d", &b_code);
			for (int s = 0; s < SIZE; s++)
			{
				if (b_code == barcode[s])
				{
					printf(" \n �����-��� ������������ \n ");
					s_code = b_code;
					break;
				}
				else if (s + 1 == SIZE)
				{
					printf(" ������ ");
				}
			}break;
		case 2:
			s = 0;
			printf("��������������� �����: \n");
			printf(" �������� | \t\t�������� \t\t | ��������� ������ | ������ \n ");
			while (s_code != barcode[s])
			{
				s++;
			}
			printf("# %d\t | %40s | %10d� | %5d%%", barcode[s], item[s], price[s], discount[s]);
			break;
		case 3:
			printf(" ����� �������� ");
			memory[n] = s_code;
			n++; 
			break;
		case 4:
			printf("\n ����������� ������ : \n");
			float sum = 0;
			for (int s = 0; s < SIZE; s++)
			{
				int z = 0;
				for (int r = 0; r < n; r++)
				{
					if (barcode[s] == memory[r])
					{
						z++;
					}
				}
				if (z > 0)
				{
					float sumpr = (float)price[s] * z;
					float respr = abs(((float)discount[s] / 100 - 1) * sumpr);
					sum += respr;
					printf("%s\t  %d x %d�\n", item[s], z, price[s]);
					printf("����� (� ������ ������) : %.2f�\n\n", respr);
				}
			}
			printf("�������� ��������� : %.2f", sum);
			break;
		case 5:
			printf("\n ���: \n\n");
			sum = 0;
			float sumd = 0;
			for (int s = 0; s < SIZE; s++)
			{
				int z = 0;
				for (int r = 0; r < n; r++)
				{
					if (barcode[s] == memory[r])
					{
						z++;
					}
				}
				if (z > 0)
				{
					float sumpr = (float)price[s] * z;
					float respr = abs(((float)discount[s] / 100 - 1) * sumpr);
					sum += sumpr;
					sumd += sumpr - respr;
					printf("%s\n", item[s]);
					printf("��������� : %.2f�\n", sumpr);
					printf("����� ������ : %.2f�\n", sumpr - respr);
					printf("���� : %.2f�\n", sumpr - (sumpr - respr));
				}
			}
			printf("\n ����� : %.2f�\n", sum);
			printf("\n C����� : %.2f�\n", sumd);
			printf("\n ����� : %.2f�\n", sum - sumd);
		}
	} while (mode != 5);
}