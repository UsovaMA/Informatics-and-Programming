#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Rus");

	int OpNumbber;
	 
	printf("�������� ������ � ������������ � ���������: \n1 - ���� ����� ���� �����\n2 - ���� ����� ��������� ���� �����\n3 - ���� ����� ������� ���� �����\n4 - ���� ����� ������ ���� �����\n�����: ");
	scanf_s("%d", &OpNumbber);

	switch (OpNumbber)
	{

		case 1:
		{
			float number1, number2, number3, AVR;

			printf ("������� ��� ����� ����� ������: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVR = (number1 + number2 + number3) / 3;

			printf("���������: %.2f", AVR);
				
		}
		break;

		case 2:
		{
			float number1, number2, number3, AVRSQR;

			printf ("������� ��� ����� ����� ������: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVRSQR = (pow(number1, 2) + pow(number2, 2) + pow(number3, 2)) / 3;

			printf("���������: %.2f", AVRSQR);
		}
		break;

		case 3:
		{
			float number1, number2, number3, AVRModule;

			printf ("������� ��� ����� ����� ������: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			AVRModule = (fabsf(number1) + fabsf(number2) + fabsf(number3)) / 3;

			printf("���������: %.5f", AVRModule);
		}
		break;

		case 4:
		{
			float number1, number2, number3, AVGSQRT;

			printf ("������� ��� ����� ������ ���� ����� ������: ");
			scanf_s("%f %f %f", &number1, &number2, &number3);

			
            AVGSQRT = (sqrtf(number1) + sqrtf(number2) + sqrtf(number3)) / 3;

			printf("���������: %.2f", AVGSQRT);
			
		}
		break;

		default: 

		printf("������ �� ����� ������������ ������, ���������� ���������� ��� ���.");
	}
	

	_getch();
	return 0;
}

