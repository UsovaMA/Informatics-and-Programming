#include <stdio.h>
#include "windows.h"
#include <time.h>
#include <locale.h>
#define SIZE 5

int main()
{
	system("color 0B");
	setlocale(LC_CTYPE, "rus");
	int tmp, array[SIZE], Chart1 = 1, Chart2 = 1, Chart3 = 1, Index1, Index2;//array  как сама переменная массива и её size велечина самого массива
	printf("Вот мы и встретились снова \n Введи 5 значений ТОКА ЦИФРЫ\n");//тип Chart как переменные для работы с массивом 
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
	printf("1.Создание массива %d\n2.Заполнение массива  %d\n3.Простые функции %d\n", Chart1, Chart2, Chart3);
	printf("\n Введи индексы элементов\n");// При введении похожих индексов массив может сломаться...
	scanf_s("%d %d", &Index1, &Index2);
	tmp = array[Index2];
	array[Index2] = array[Index1];
	array[Index1] = tmp;
	printf("\n Будем менять местами половины массива:\n");//с помощью пересборки благодаря "делению массива на 2"
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