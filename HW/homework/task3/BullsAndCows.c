#include <stdio.h>
#include <math.h>
#include <malloc.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

int *user_num_list, *pc_num_list, num;


int num_generate(int n) {
	int num = 0, i = 0;
	int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	srand(time(0));

	while (n > 0) {
		i = rand() % 10 + 1;
		while ((numbers[i] < 0) && (i < 10)) 
			i++;
		while ((numbers[i] < 0) && (i > -1))
			i--;
		num = num * 10 + numbers[i];
		numbers[i] = -1;
		n--;
	}

	return num;
}

void cows_and_bulls(int *pc_num, int *user_num, int n, int *cows_count, int *bulls_count) {

	*cows_count = *bulls_count = 0;

	for (int i = 0; i < n; i++) {

		if ((pc_num_list[i] == user_num_list[i]) && (user_num_list[i] > -1)) {
			*bulls_count += 1;
			user_num_list[i] = -1;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((pc_num_list[i] == user_num_list[j]) && (user_num_list[j] > -1)) {
				*cows_count += 1;
				user_num_list[j] = -1;
			}
		}
	}
}



int main()/*Start programm*/ {

	int n, user_num, cows = 0, bulls = 0;

	while (true) {
		printf("Input n (between 2 and 5): \n");
		scanf_s("%d", &n);
		if ((n >= 2) && (n <= 5))
			break;
		else
			printf("Wrong range!\n");
	}

	user_num_list = (int)malloc(n * sizeof(int));
	pc_num_list = (int)malloc(n * sizeof(int));
	num = num_generate(n);

	int i = 0;

	while (num != 0) {
		pc_num_list[i] = num % 10;

		num /= 10;
		i++;
	}


	while (true) {
		printf("Enter the number without repetitions: ");
		scanf_s("%d", &user_num);

		i = 0;


		while (user_num != 0) {
			user_num_list[i] = user_num % 10;
			user_num /= 10;
			i++;
		}

		cows_and_bulls(pc_num_list, user_num_list, n, &cows, &bulls);

		if (bulls == n) {
			printf("You guessed a number!");
			break;
		}
		else
			printf("count of cows = %d\n count of bulls = %d\n", cows, bulls);
	}


	return 0;
}