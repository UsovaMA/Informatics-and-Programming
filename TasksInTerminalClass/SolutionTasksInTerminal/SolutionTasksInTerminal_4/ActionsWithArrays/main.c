#include <stdio.h>
#include <locale.h>
#include <math.h>

#define SIZE 10
/*
*������ � �������� �������� ������� ��� ��������� 
* 
* ���������� ������ 
* 1. ��������� ��������� �������
* 2. ��������� �������� �������
* 3. ���������� ���� ������� �������� ��� ��������
* ------����� ����� ���� ������ ��������� 
* ------����� ����� ��������� � ������� ���������
* ------����� ����� ��������� � ������� ����������
* ------����� �������� ������� ������� � �������� ��� �� ��������������� 
* ------�������� �������� ������� ������� (��� ������, �������� �������)
* ------���������� ������(������ mass[] = 1, 2, 3 => mass[] = 3, 2, 1
* ------�������� ������� 1 
*/



int main()
{
	setlocale(LC_ALL, "Russian");

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
	for ( i = 0; i < size; i++)
	{
		printf("%.1f ", mass[i]);
	}
	float sum_even_el = 0.0;
	float sum_even_indx = 0.0;
	float sum_even_values = 0.0;
	for ( i = 0; i < size; i++)
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
	printf("\nSum of elements with even index: %.1f", sum_even_el);
	printf("\nSum of elements with even value: %d", sum_even_values);

	int indx;
	printf("\nImput index for replace: ");
	scanf_s("%d", &indx);

	float new_value;
	printf("\nImput new value for index: ");
	scanf_s("%f", &new_value);

	mass[indx] = new_value;
	
	printf("Your array now:");
	for  ( i = 0; i < size; i++)
	{

	}
	
	/*
	int massive[100] = { 0 };                      // ������ �� 100 ���������
	int mass_1 [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int mass_2 [5];								   // 5 ��������� ������
	int mass_3 [SIZE];

	// ������������ �������
	int size;
	printf ("Imput size of dinamic array: ");
	scanf_s("%d", &size);

	
	// ���������� ������������ �������
	float* mass; 
	// ��������� ������ ��� ������������ ������
	// malloc(size)
	// sizeof(float)
	mass = (float*)malloc(size * sizeof(float));
	
	// �������� ���������� �������
	int m1[10];
	int m2[SIZE];
	int m3[] = { 1, 2, 3, 4 };
	// * - ���������, int* - ��������� �� ����� �����
	int* m4; // ��������� �� ������ �������������� �������
	
	int sum = 0, indx = 0, new_value = 0;


    printf("%d", mass[0]);
	*/
	free(mass);
	return 0;
}