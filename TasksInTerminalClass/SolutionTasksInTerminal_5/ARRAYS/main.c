#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>


int main()
{
	setlocale(LC_ALL, ("Russian"));
#define SIZE 10
	/*
	*ѕроект с разбором основных функций над массивами
	*
	* ѕостановка задачи
	* 1. Ќаучитьс€ создавать массивы
	* 2. Ќаучитьс€ запон€ть массивы
	* 3. –еалиовать пару простых функиций над массиами
	* Ч----найти сумму всех чЄтных элементов
	* Ч----найти сумму элементов с чЄтными индексами
	* Ч----найти сумму элементов с чЄтными значени€ми
	* Ч----найти заданный элемент массива и заменить его на противоположный
	* Ч----помен€ть заданный элемент массива (дан индекс, изменить зачение)
	* Ч----развернуть массив(ѕример mass[] = 1, 2, 3 => mass[] = 3, 2, 1
	*/

		printf("Topic ARRAYS\n");

		int size;
		printf("Imput size of dinamic array: ");
		scanf_s("%d", &size);

		float* mass;

		mass = (float*)malloc(size * sizeof(float));

		int i;

		for (i = 0; i < size; i++)
		{
			mass[i] = i + 1;
		}
		
		for (i = 0; i < size; i++)
		{
			printf("%.1f ", mass[i]);
		}
		float sum_even_el = 0.0;
		float sum_even_indx = 0.0;
		float sum_even_values = 0.0;
		for (i = 0; i < size; i++)
		{
			if ((i + 1) % 2 == 0)
			{
				sum_even_el = sum_even_el + mass[i];
			}
			else
			{
				sum_even_indx = sum_even_indx + mass[i];
			}
			if ((int)mass[i] % 2 == 0)
			{
				sum_even_values = sum_even_values + mass[i];
			}


		}
		printf("\nSum of even elements: %.1f", sum_even_el);
		printf("\nSum of elements with even index: %.1f", sum_even_indx);
		printf("\nSum of elements with even value: %.1f", sum_even_values);

		int indx;
		printf ("\nImput index for replace: ");
		scanf_s("%d", &indx);

		float new_value;
		printf ("\nImput new value for index: ");
		scanf_s("%f", &new_value);

		mass[indx] = new_value;

		printf("Your array now:");
		for (i = 0; i < size; i++)
		{
             	printf("%.1f ", mass[i]);
		}

		printf ("\nImput index to replace for a the opposite value: ");
		scanf_s("%d", &indx);

		float opposite_value;

		mass[indx] = indx * (-1);
		
		printf("Your array now:");
		for (i = 0; i < size; i++)
		{
			printf("%.1f ", mass[i]);
		}

		int rev = 0;
		for (i = 0; i < size / 2; i++) {
			rev = mass[i];
			mass[i] = mass[size - i - 1];
			mass[size - i - 1] = rev;
		}
		printf("\nRevers array now:");
		for (i = 0; i < size; i++)
		{
			printf("%.1f ", mass[i]);
		}


		/*
		int massive[100] = { 0 }; // массив на 100 элементов
		int mass_1 [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int mass_2 [5]; // 5 элементов мусора
		int mass_3 [SIZE];

		// динамические массивы
		int size;
		printf ("Imput size of dinamic array: ");
		scanf_s("%d", &size);


		// объ€вление диамического массива
		float* mass;
		// выделение пам€ти под динамический массив
		// malloc(size)
		// sizeof(float)
		mass = (float*)malloc(size * sizeof(float));

		// варианты объ€влени€ массива
		int m1[10];
		int m2[SIZE];
		int m3[] = { 1, 2, 3, 4 };
		// * - указатель, int* - указатель на целое число
		int* m4; // указатель на начало целочисленного массива

		int sum = 0, indx = 0, new_value = 0;


		printf("%d", mass[0]);
		*/
		free(mass);
		
	


	return 0;
    }