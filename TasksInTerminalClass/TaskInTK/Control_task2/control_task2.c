#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() //start programm
{
	int n, count;
	int* list;
	int* indexes;
	printf("Input count of candidates: ");
	scanf_s("%d", &n);

	list = (int)malloc(n * sizeof(int));
	indexes = (int)malloc(n * sizeof(int));

	printf("Input number of places: ");
	scanf_s("%d", &count);


	for (int i = 0; i < n; i++) {
		int m1, m2, m3;
		printf("Candidate No %d", i + 1);
		scanf_s("%d %d %d", &m1, &m2, &m3);
		list[i] = m1 + m2 + m3;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d element = %d\n", i + 1, list[i]);
	}

	for (int i = 0; i < n; i++) {
		indexes[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			int tmp;
			if (list[j] < list[j + 1]) {
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
				tmp = indexes[j];
				indexes[j] = indexes[j + 1];
				indexes[j + 1] = tmp;
			}
		}
	}

	printf("\nfinished\n");
	for (int i = 0; i < n; i++) {
		printf(" %d element = %d\n", i + 1, list[i]);
	}

	printf("Minimum mark = %d\n", list[count - 1]);
	printf("Students: \n");

	for (int i = 0; i < count; i++) {
		printf("%d ", indexes[i]  + 1);
	}
	free(list);
	free(indexes);
}