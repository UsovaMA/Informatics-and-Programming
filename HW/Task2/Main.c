#include <stdio.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int r, k, flag = 0, num, pop = 0; // Выбор режима, рандом, ввод числа и попытки
	printf("\t\t<<<--- Угадай число --->>> (от 1 до 1000)\n\n");
	printf("Как будем играть? (Выберите цифру из списка)\n 1. Отгадать число\n 2. Загадать число\n Ваш выбор: ");
	scanf_s("%d", &r);

	if (r == 1)
	{
		srand(time(0));
		k = rand() % 1000 + 1;
		printf(" <|  Начинаем игру!  |>\n");
		while (flag != 1)
		{
			printf("\nВведите число: ");
			scanf_s("%d", &num);
			if (num > k)
			{
				printf("Загаданное число меньше\n");
				pop++;
			}
			else if (num < k)
			{
				printf("Загаданное число больше\n");
				pop++;
			}
			else
			{
				printf("Вы угадали!\nКоличество попыток: %d\n\n", pop);
				flag = 1;
			}
		}
	}
	else if (r == 2)
	{
		char srav[1];
		int x1 = 1, x2 = 1000, mid = (x2 + x1) / 2;
		printf("Введите число (от 1 до 1000): ");
		scanf_s("%d", &num);
		printf("\n <|  Начинаем игру!  |>\n\n");
		while (flag != 1)
		{
			printf("\nВаше число: %d ?\nНапишите знак сравнения (< > =):  ",mid);
			char srav = getche();
			if (srav == 62)
			{
				x1 = mid;
				printf("\n%d\n", x1);
				pop++;
				mid = (x2 + x1) / 2;
			}
			else if (srav == 60)
			{
				x2 = mid;
				printf("\n%d", x1);
				pop++;
				mid = (x2 + x1) / 2;
			}
			else if (srav == 61)
			{
				printf("\n\nВаше загаданное число: %d\n", mid); 
				printf("Количество попыток: %d\n", pop);
				flag = 1;
			}
			else
			{
				printf("\nВведен неверный знак!\n");
			}
		}
	}
	else
	{
		printf("Выберите режим из предложенных!");
	}
	return 0;
}