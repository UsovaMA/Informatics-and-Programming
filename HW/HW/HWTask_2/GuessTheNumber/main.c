#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "Russian");
	int PC_Number_1, User_Number_1, mode, NumberOfAttempts;
	NumberOfAttempts = 0;

	printf ("Введите номер режима:\n1 - программа загадывает число и вы пытаетесь его угадать\n2 - программа пытается угадать загаданое вами число\nНомер режима: ");
	scanf_s("%d", &mode);

	switch (mode)
	{
		case 1:
		{
			srand(time(0));
			PC_Number_1 = rand() % 1000;

			do
			{
				printf ("Введите число, которое по вашему мнению загадала программа (от 1 до 1000): ");
				scanf_s("%d", &User_Number_1);
			

				if (PC_Number_1 == User_Number_1)
				{
					printf("Вы угадали!");
					NumberOfAttempts++;
					printf("\nКоличество попыток: %d", NumberOfAttempts);
				}
				else
				{
					if (PC_Number_1 < User_Number_1)
					{
						printf("Попробуйте число поменьше \n");
						NumberOfAttempts++;
					}
					else
					{
						if (PC_Number_1 > User_Number_1)
						{
							printf("Попробуйте число побольше \n");
							NumberOfAttempts++;
						}
					}
				}
			} while (PC_Number_1 != User_Number_1);
		} break;

		case 2:
		{
			char sign;
			int change = 500, PC_Number_2 = 500, User_Number_2;
			printf ("Вы должны загадать число от 1 до 1000.\nЕсли ваше число равно тому которое предположил компьютер введите '='\nЕсли меньше введите '>'\nЕсли больше введите '<'");
			do
			{
				printf ("\nВаше число:%d ?\n", PC_Number_2);
				scanf_s("%ch", &sign);

				change = change * 0.9;
				if (change < 1) change = 1;

					if (PC_Number_2 > 1000) PC_Number_2 = 1000;

						if (PC_Number_2 < 1) PC_Number_2 = 1;

							if (sign == '=')
							{
								printf("\nВаше число!");
								NumberOfAttempts++;
								printf("\nЧисло попыток: %d", NumberOfAttempts);
							}
							else
							{
								if (sign == '>')
								{
									printf("\nПохоже ваше число меньше.");
									PC_Number_2 = PC_Number_2 - change;
									NumberOfAttempts++;
								}
								else
								{
									if (sign == '<')
									{
										PC_Number_2 = PC_Number_2 + change;
										NumberOfAttempts++;
									}
								}
							}

			} while (sign != '=');
		} 
		break;

			default:
			{
				printf("Нужно написать число 1 или 2, попробуйте ещё раз.");
			}
			break;
	}


	_getch();
	return 0;
}