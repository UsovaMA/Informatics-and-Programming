#include <stdio.h>
#include "windows.h"
#include <time.h>
#include <locale.h>
#define SIZE 5

int main()
{
	system("color 0B");
	setlocale(LC_CTYPE, "rus");
	int tmp, array[SIZE], Chart1 = 1, Chart2 = 1, Chart3 = 1, Index1, Index2;//array  ��� ���� ���������� ������� � � size �������� ������ �������
	printf("��� �� � ����������� ����� \n ����� 5 �������� ���� �����\n");//��� Chart ��� ���������� ��� ������ � �������� 
	for (int i = 0; i < SIZE; i++) 
	{
		scanf_s("%d", &array[i]);
	}
	for (int i = 0; i < SIZE; i++) 
	{
		if (i % 2 == 0)
		{
			Chart1 *= array[i];
		}
		else 
		{
			Chart2 *= array[i];
		}
		if (array[i] % 2 != 0) 
		{
			Chart3 *= array[i];
		}
	}
	printf("1.�������� ������� %d\n2.���������� �������  %d\n3.������� ������� %d\n", Chart1, Chart2, Chart3);
	printf("\n ����� ������� ���������\n");// ��� �������� ������� �������� ������ ����� ���������...
	scanf_s("%d %d", &Index1, &Index2);
	tmp = array[Index2];
	array[Index2] = array[Index1];
	array[Index1] = tmp;
	printf("\n ����� ������ ������� �������� �������:\n");//� ������� ���������� ��������� "������� ������� �� 2"
	for (int i = 0; i < SIZE / 2; i++) 
	{
		tmp = array[i];
		array[i] = array[i+SIZE/2];
		array[i+SIZE/2] = tmp;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}