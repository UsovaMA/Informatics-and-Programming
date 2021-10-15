#include <stdio.h>
#include <math.h>
#include <malloc.h>


int main() //start programm
{

	int n, a, k;
	int* list;

	printf("Input size of list: ");
	scanf_s("%d", &n);

	list = (int)malloc(n * sizeof(int));

	printf("Input the range of array: ");
	scanf_s("%d", &a);

	printf("Input k: ");
	scanf_s("%d", &k);

	srand(time(0));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % (2*a) - a;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d element = %d\n", i + 1, list[i]);
	}

	for (int i = 0; i < k; i++) {
		int tmp = list[n - 1];
		for (int j = n - 1; j > -1; j--) {
			list[j] = list[j - 1];
		}
		list[0] = tmp;
	}

	printf("\nshifted list: \n");
	for (int i = 0; i < n; i++) {
		printf(" %d element = %d\n", i + 1, list[i]);
	}


	for (int i = 0; i < n / 2; i++) {
		int tmp = list[i];
		list[i] = list[n - i - 1];
		list[n - i - 1] = tmp;
	}

	printf("\nresult: \n");
	for (int i = 0; i < n; i++) {
		printf(" %d element = %d\n", i + 1, list[i]);
	}
	free(list);
}