#include <stdio.h>
#include <malloc.h>
#include <math.h>



int main() {
	int* m;
	int n;

	printf("vvedite razmer massiva ");
	scanf_s("%d", &n);

	m = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("vvedite %d element: ", i + 1);
		scanf_s("%d", &m[i]);
	}

	for (int i = n - 1; i > -1; i--) {

		printf(" %d\n", m[i]);

	}
	return 0;
}
