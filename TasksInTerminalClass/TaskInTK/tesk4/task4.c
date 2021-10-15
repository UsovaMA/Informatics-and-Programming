#include <stdio.h>
#include <malloc.h>
#include <math.h>

// Start programm

int main() {

	int *list_1, *list_2;
	int range;

	printf("Input range of array: ");
	scanf_s("%d", &range);

	list_1 = (int*)malloc(range * sizeof(int));
	list_2 = (int*)malloc(range * sizeof(int));

	for (int i = 0; i < range; i++) {
		printf("\nInput %d element:", i + 1);
		scanf_s("%d", list_1[i]);
	}
}