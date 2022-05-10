#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "Russian");
	int PC_Number_1, User_Number_1, mode, NumberOfAttempts;
	NumberOfAttempts = 0;

	printf ("������� ����� ������:\n1 - ��������� ���������� ����� � �� ��������� ��� �������\n2 - ��������� �������� ������� ��������� ���� �����\n����� ������: ");
	scanf_s("%d", &mode);

	switch (mode)
	{
		case 1:
		{
			srand(time(0));
			PC_Number_1 = rand() % 1000;

			do
			{
				printf ("������� �����, ������� �� ������ ������ �������� ��������� (�� 1 �� 1000): ");
				scanf_s("%d", &User_Number_1);
			

				if (PC_Number_1 == User_Number_1)
				{
					printf("�� �������!");
					NumberOfAttempts++;
					printf("\n���������� �������: %d", NumberOfAttempts);
				}
				else
				{
					if (PC_Number_1 < User_Number_1)
					{
						printf("���������� ����� �������� \n");
						NumberOfAttempts++;
					}
					else
					{
						if (PC_Number_1 > User_Number_1)
						{
							printf("���������� ����� �������� \n");
							NumberOfAttempts++;
						}
					}
				}
			} while (PC_Number_1 != User_Number_1);
			break;
		} 

		case 2:
		{
			char sign;
			int change = 500, PC_Number_2 = 500, User_Number_2;
			printf ("�� ������ �������� ����� �� 1 �� 1000.\n���� ���� ����� ����� ���� ������� ����������� ��������� ������� '='\n���� ������ ������� '>'\n���� ������ ������� '<'");
			do
			{
				printf ("\n���� �����:%d ?\n", PC_Number_2);
				scanf_s("%ch", &sign);

				change = change * 0.9;
				if (change < 1) change = 1;

					if (PC_Number_2 > 1000) PC_Number_2 = 1000;

						if (PC_Number_2 < 1) PC_Number_2 = 1;

							if (sign == '=')
							{
								printf("\n���� �����!");
								NumberOfAttempts++;
								printf("\n����� �������: %d", NumberOfAttempts);
							}
							else
							{
								if (sign == '>')
								{
									printf("\n������ ���� ����� ������.");
									PC_Number_2 = PC_Number_2 - change;
									NumberOfAttempts++;
								}
								else
								{
									if (sign == '<')
									{
										PC_Number_2 = PC_Number_2 + change;
										NumberOfAttempts++;
									}
								}
							}

			} while (sign != '=');
			break;
		} 
		

			default:
			{
				printf("����� �������� ����� 1 ��� 2, ���������� ��� ���.");
				break;
			}
			
	}


	_getch();
	return 0;
}