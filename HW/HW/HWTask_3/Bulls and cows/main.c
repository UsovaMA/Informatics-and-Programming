#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>


int main()
{
	setlocale(LC_ALL, "Russian");

	int* crand = NULL, leght = 0, user_num = 0, digit = 0, * user_numarr = NULL, user_numfarr = 0, f = 0, cows = 0, bulls = 0, f1 = 0;

	printf("Играем в быки и коровы!\nСмысл игры угадать число которое загадал компьютер\nЕсли угадано число вместе с позицией то Bulls + 1, если угадано число но не позиция этого числа то Cows + 1\n\n");
	printf("Вам нужно выбрать из скольки цифр будет состоять загадываемое число, а потом пытаться угадать его вводя число с таким же кол-вом цифр.\n!!!Число не должно содержать 0 и все цифры должны быть различны\n\n");
	printf("Выберите длину загадываемого числа от 2 до 5: ");
	scanf_s("%d", &leght);
	if (leght >= 2 && leght <= 5)
	{
		srand(time(NULL));
		crand = (int*)malloc(leght * sizeof(int*));
		user_numarr = (int*)malloc(leght * sizeof(int*));
        
		for(int i = 0; i < leght; )
		{
			int f = 0;
			int MASS_Rand_Value = rand() % 9 + 1;

			for (int j = 0; j < i; j++)
			{
				if(crand[j] == MASS_Rand_Value)
				{
					f = 1;
					break;
				}
			}

			if (f == 0)
			{
				crand[i] = MASS_Rand_Value;
				i++;
			}

		}

		for (int i = 0; i < leght; i++)
		{
			printf("%d ", crand[i]);
		}
  
		while(bulls != leght)
		{
		
			printf("\n\nКомпьютер загадал число, попробуйте его отгадать.");
			printf("\nВведите ваше число(такого же размера как и загадываемое и не содержащее нулей): ");
			scanf_s("%d", &user_num);
			user_numfarr = user_num;
			while (user_num % 10 != 0)
			{
				user_num /= 10;
				digit++;
			}
			if (digit == leght)
			{
				bulls = 0;
				cows = 0;

				for (int i = digit - 1 ; 0 <= i; i--)
				{
					user_numarr[i] = user_numfarr % 10;
					user_numfarr /= 10;
				}

				for (int i = 0; i < digit; i++)
				{		
						if(crand[i] == user_numarr[i])
						{
							bulls += 1;
						}
						for (int j = 0; j < digit; j++)
						{
							if(crand[i] == user_numarr[j] && i != j)
							{
								cows += 1;	
							}
						}
				}
				printf("\nBulls = %d", bulls);
				printf("\nCows = %d", cows);
			    
			}	
			else
			{
				printf("\nПохоже вы ввели неподходящее число(больше или меньше загадываемого или содержащее ноль) пожалуйста попробуйте ещё раз...");
			}
			digit = 0;
	    }
		printf("\nВы угадали число!!!");
	} 
	else
	{
		printf("Нужно ввести чсло от 2 до 5 !!!");
	}
	return 0;
} 