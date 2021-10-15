#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() //start programm
{ 

	int *list_1, *list_2;
	int range;

	printf("Input range of array: ");
	scanf_s("%d", &range);

	list_1 = (int*)malloc(range * sizeof(int));
	list_2 = (int*)malloc(range * sizeof(int));

//Solution without second array:
	for (int i = 0; i < range; i++) {
		printf("\nInput %d element:", i + 1);
		scanf_s("%d", &list_1[i]);
	}

	for (int i = 0; i < range / 2; i++) {
		int tmp = list_1[i];
		list_1[i] = list_1[range - i - 1];
		list_1[range - i - 1] = tmp;
	}

	for (int i = 0; i < range; i++) {
		printf(" %d element = %d\n", i + 1, list_1[i]);
	}
}