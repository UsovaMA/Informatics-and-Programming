#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {

	setlocale(LC_ALL, "russian");

	int number, a;
	int IsError = 0, IsWork = 1;

	while (IsWork) {

		printf("Привет! Давайте сделаем инверсию числа!\n");
		printf("Для выхода введите 0\n ");

		// input data
		do {
			if (IsError) printf("Неверный ввод! Попробуйте ещё!");

			printf("\nВведите число: ");
			scanf_s("%d", &number);

			if (number == 0) {
				IsWork = 0;
				break;
			}
			IsError = (number <= 0);

			

		} while (IsError);
		

		// algorithm / action
		while (number > 10) {
			    if (number > 10) {
					a = number % 10;
					printf("%d", a);
					number = number / 10;
				}
		}


		// result
		printf("%d\n", number);
		
	}
	return 0;
}