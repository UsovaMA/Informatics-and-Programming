#include <stdio.h>
#include <math.h>
#include <malloc.h>


int main() 
{
	int i, s, d, k, m1, i1;
	int* m;
	
	printf("vvedite razmer i diapozon massiva ");
	scanf_s("%d %d", &s,&d);
    printf("na skolko sdvig: ");
	scanf_s("%d", &k);
    srand(time(0));
	m = (int)malloc(s * sizeof(int));
	for (i = 0; i < s; i++) {
		m[i] = rand() % (2 * d) - d;
	}
    for (i = 0; i < s; i++) {
		printf(" %d %d\n", i + 1, m[i]);
	}
    for (i = 0; i < k; i++) {
		m1 = m[s - 1];
		for (i1 = s - 1; i1 > -1; i1--) {
			m[i1] = m[i1 - 1];
		}
		m[0] = m1;
	}
    printf("sdvinutiy massiv \n");
	for (i = 0; i < s; i++) {
		printf(" %d %d\n", i + 1, m[i]);
	}
    for (i = 0; i < s / 2; i++) {
		m1 = m[i];
		m[i] = m[s - i - 1];
		m[s - i - 1] = m1;
	}
	for (i = 0; i < s; i++) {
		printf(" %d %d\n", i + 1, m[i]);
	}
	return 0;
}