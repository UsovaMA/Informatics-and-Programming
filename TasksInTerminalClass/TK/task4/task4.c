#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include<locale.h>



int main() 
{
    setlocale(LC_ALL, "Rus");
	int* m;
	int n, i, v;

	printf("введите размер массива ");
	scanf_s("%d\n", &n);

	m = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf(" m[%d] = ", i + 1);
		scanf_s("%d", &m[i]);
	}
	for (i = 0; i < n / 2; i++) {
		v = m[i];
		m[i] = m[n - i - 1];
		m[n - i - 1] = v;
	}

	for (int i = 0; i < m; i++) {
		if (n == i) break;
		printf("m[%d] %d \n",i+1, m[i]);
		
	}
	return 0;
}

