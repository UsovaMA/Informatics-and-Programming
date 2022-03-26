#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int size, * mass, rnum, m, pos = 0, input;
	int max = 9, min = 1, count = 0, position;
	while (1) {
		printf("введите длину числа(от 2 до 5): ");
		scanf_s("%d", &size);
		if (size >= 2 && size <= 5) {
			mass = (int*)malloc(size * sizeof(int));
			break;
		}
		else {
			printf("Ошибка ввода.\n");
		}
	}
	for (m = 0; m < size; m++) {
		mass[m] = 999;
	}
	while (count != size) {
		rnum = rand() % (max - min + 1) + min;
		int c = 0;
		for (m = 0; m < size; m++) {
			if (rnum != mass[m]) {
				c += 1;
				if (c == size) {
					count += 1;
					mass[pos] = rnum;
					pos += 1;
				}
			}
		}
	}
	printf("\n");
	for (m = 0; m < size; m++) {
		printf("%d", mass[m]);
	}
	while (1) {
		printf("\nвведите число:");
		scanf_s("%d", &input);
		position = size;
		int cow = 0;
		int bull = 0;
		while (input > 0) {
			int k = input % 10;
			input /= 10;
			position -= 1;
			for (m = 0; m < size; m++) {
				if (k == mass[m] && position == m) {
					bull += 1;
				}
				else if (k == mass[m] && position != m) {
					cow += 1;
				}
			}
		}
		printf("коров:%d", cow);
		printf("\nбыков:%d", bull);
		if (bull == size) {
			break;
		}
	}
	return 0;
}