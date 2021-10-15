#include <stdio.h>
#include <malloc.h>
#include <math.h>



int main() {
	int* m, m1;
	int n, i, i1=0;

	printf("vvedite razmer massiva ");
	scanf_s("%d\n", &n);

	m = (int*)malloc(n * sizeof(int));
	m1 = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf(" m[%d] = ", i + 1);
		scanf_s("%d", &m[i]);
	}
	for (i = n - 1; i >= 0; i--, i1++) {
		m1[i1] = m[i];
	}
	for (i1 = 0; i1 < n; i1++) {
		printf("%d ", m1[i1]);
	}
	return 0;
}
