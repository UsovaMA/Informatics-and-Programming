// Copyright 2021 Vladimir Fomin

/*Actions with arrays:
1. Найти произведение нечетных элементов массива
2. Найти поизведение элементов массива с нечетным индексом 
3. Найти произведение элементов массива нечетных о значению
4. Поменять местами элементы с заданными индексами
5. Поменять месами правую и левую половину массива
      Реализовать 2 способами:
	    1. С использованием доп массива
		2. Без доп массива*/

#include <stdio.h>

int main() {
	int size, UserChoice, el;	

	printf("Privetstvie\n");
	printf("Input size of the array\n");
	scanf_s("%d", &size);
	int* in_array = (int*)malloc(size * sizeof(int)) ;

	printf("Input array\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &el);
		in_array[i] = el;
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", in_array[i]);
	}

	
	free(in_array);
	return 0;
}