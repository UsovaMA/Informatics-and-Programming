/*Copyright 2021 Vladimir Fomin*/

/*Actions with arrays:
Поменять местами правую и левую половину массива
	  Реализовать 2 способами:
		1. С использованием доп массива
		2. Без доп массива*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, el1, method;
	int* array;
	int* array_reverse;
	int el, tmp, tmp2;

	printf("This program swaps the right and left parts of the array\n");
	printf("Choose a solution method:\n 1.With second array\n 2.Without second array\n ");
	scanf_s("%d", &method);
	printf("Input size of the array\n");
	scanf_s("%d", &size);
	switch (method)
	{
	case 1:
		array = (int*)malloc(size * sizeof(int));
		array_reverse = (int*)malloc(size * sizeof(int));
		if (!array || !array_reverse) {
			printf("Error. Required memory is not allocated\n");
			exit(1);
		}
		for (int i = 0; i < size; i++) {
			array_reverse[i] = 0;
			array[i] = 0;
		}
		printf("Input array\n");
		for (int i = 0; i < size; i++) {
			scanf_s("%d", &el1);
			array[i] = el1;
		}
		for (int i = size / 2, j = 0; i < size; i++, j++) {
			array_reverse[j] = array[i];
		}
		for (int i = 0, j = size / 2 + size % 2; j < size; i++, j++) {
			array_reverse[j] = array[i];
		}
		printf("The resulting array: ");
		for (int i = 0; i < size; i++) {
			printf("%d ", array_reverse[i]);
		}
		free(array);
		free(array_reverse);
		break;
	case 2:
		array = (int*)malloc(size * sizeof(int));

		if (!array) {
			printf("Error. Required memory is not allocated\n");
			exit(1);
		}
		for (int i = 0; i < size; i++) {
			array[i] = 0;
		}
		printf("Input array\n");
		for (int i = 0; i < size; i++) {
			scanf_s("%d", &el);
			array[i] = el;
		}
		if (size % 2 == 0) {
			for (int i = 0, j = size / 2; j < size; i++, j++) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		else {
			for (int i = 0, j = size / 2; j < size; i++, j++) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			array[size - 1] = tmp;
			for (int i = size - 1; i >= size / 2 + 1; i--)
			{
				array[i] = array[i - 1];
			}
			array[size / 2 + 1] = tmp;
		}
		printf("The resulting array: ");
		for (int i = 0; i < size; i++) {
			printf("%d ", array[i]);
		}
		free(array);
		break;
	}
	return 0;
}