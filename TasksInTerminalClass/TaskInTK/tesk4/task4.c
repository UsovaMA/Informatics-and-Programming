#include <stdio.h>
#include <malloc.h>
#include <math.h>

// Start programm

int main() {
	int* list;
	int n, j = 0;

	printf("Input range of the list: ");
	scanf_s("%d", &n);

	list = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("Input %d element: ", i + 1);
		scanf_s("%d", &list[i]);
	}
	
	for (int i = n - 1; i > -1; i--) {

		printf("el = %d\n", list[i]);

	}
	return 0;
}