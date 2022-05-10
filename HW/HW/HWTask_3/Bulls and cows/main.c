#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>


int main()
{
	setlocale(LC_ALL, "Russian");

	int* crand = NULL, leght = 0, user_num = 0, digit = 0, * user_numarr = NULL, user_numfarr = 0, f = 0, cows = 0, bulls = 0, f1 = 0;

	printf("������ � ���� � ������!\n����� ���� ������� ����� ������� ������� ���������\n���� ������� ����� ������ � �������� �� Bulls + 1, ���� ������� ����� �� �� ������� ����� ����� �� Cows + 1\n\n");
	printf("��� ����� ������� �� ������� ���� ����� �������� ������������ �����, � ����� �������� ������� ��� ����� ����� � ����� �� ���-��� ����.\n!!!����� �� ������ ��������� 0 � ��� ����� ������ ���� ��������\n\n");
	printf("�������� ����� ������������� ����� �� 2 �� 5: ");
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
		
			printf("\n\n��������� ������� �����, ���������� ��� ��������.");
			printf("\n������� ���� �����(������ �� ������� ��� � ������������ � �� ���������� �����): ");
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
				printf("\n������ �� ����� ������������ �����(������ ��� ������ ������������� ��� ���������� ����) ���������� ���������� ��� ���...");
			}
			digit = 0;
	    }
		printf("\n�� ������� �����!!!");
	} 
	else
	{
		printf("����� ������ ���� �� 2 �� 5 !!!");
	}
	return 0;
} 