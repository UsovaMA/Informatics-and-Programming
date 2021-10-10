// Copyright 2021 Vladimir Fomin

/*Actions with arrays:
Поменять местами правую и левую половину массива
      Реализовать 2 способами:
	    1. С использованием доп массива
		2. Без доп массива*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, el, j;	

	printf("This program swaps the right and left parts of the array\n");
	printf("Input size of the array\n");
	scanf_s("%d", &size);
	int* array;
	int* array_reverse;
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
	for (int i = 0; i < size ; i++) {
		scanf_s("%d", &el);
		array[i] = el;
	}
	for (int i = size / 2, j = 0; i < size; i++, j++) {
		array_reverse[j] = array[i];
	}
	if (size % 2 == 0) {
		for (int i = 0, j = size / 2 ; j < size; i++, j++) {
			array_reverse[j] = array[i];
		}
	}
	else {
		for (int i = 0, j = size / 2 + 1; j < size; i++, j++) {
			array_reverse[j] = array[i];
		}
	}
	printf("The resulting array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array_reverse[i]);
	}
	free(array);
	free(array_reverse);
	return 0;
}