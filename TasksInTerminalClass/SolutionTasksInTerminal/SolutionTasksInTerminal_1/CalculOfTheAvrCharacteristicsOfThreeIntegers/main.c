#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Rus");

	int OpNumbber;
	 
	printf("Выберите чиисло в соответствии с операцией: \n1 - сред арифм трех чисел\n2 - сред арифм квадратов трех чисел\n3 - сред арифм модулей трех чисел\n4 - сред арифм корней трех чисел\nчисло: ");
	scanf_s("%d", &OpNumbber);

	switch (OpNumbber)
	{

		case 1:
		{
			float number1, number2, number3, AVR;

			printf ("Введите три числа через пробел: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVR = (number1 + number2 + number3) / 3;

			printf("Результат: %.2f", AVR);
				
		}
		break;

		case 2:
		{
			float number1, number2, number3, AVRSQR;

			printf ("Введите три числа через пробел: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVRSQR = (pow(number1, 2) + pow(number2, 2) + pow(number3, 2)) / 3;

			printf("Результат: %.2f", AVRSQR);
		}
		break;

		case 3:
		{
			float number1, number2, number3, AVRModule;

			printf ("Введите три числа через пробел: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVRModule = (fabsf(number1) + fabsf(number2) + fabsf(number3)) / 3;

			printf("Результат: %.5f", AVRModule);
		}
		break;

		case 4:
		{
			float number1, number2, number3, AVGSQRT;

			printf ("Введите три числа больше нуля через пробел: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			
            AVGSQRT = (sqrtf(number1) + sqrtf(number2) + sqrtf(number3)) / 3;

			printf("Результат: %.2f", AVGSQRT);
			
		}
		break;

		default: 

		printf("Похоже вы ввели некорректные данные, пожалуйста попробуйте ещё раз.");
	}
	

	_getch();
	return 0;
}

