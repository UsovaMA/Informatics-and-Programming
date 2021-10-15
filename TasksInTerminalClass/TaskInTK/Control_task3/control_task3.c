#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() //start programm
{
	int n, count;
	int* list;
	int* indexes;
	printf("Input count of citizens: ");
	scanf_s("%d", &n);

	list = (int)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		int tmp;
		printf("%d Friends ", i + 1);
		scanf_s("%d", &tmp);
		list[i] = tmp;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d friends = %d\n", i + 1, list[i]);
	}

	int* friends;



	free(list);
}