#include<locale.h>
#include<stdio.h>
#include<math.h>
#define pi 3.14

int main()
{
	setlocale(LC_ALL, "RU");
	int vst, osn, Str, strn1, strn2, Sprm, R, number;
	float So;
	printf("������� ����� ������  1 - ����������� | 2 - ������������� | 3 - ���������� \n");
	scanf_s("%d", &number);
	switch (number)
	{
	case 1:
	{
		printf("������� ������ � ��������� ������������ : ");
		scanf_s("%d %d", &vst, &osn);
		Str = vst * osn / 2;
		printf(" ������� ������������ = %f \n", Str);
	} break;

	case 2:
	{
		printf("������� ������� �������������� : ");
		scanf_s("%d %d", &strn1, &strn2);
		Sprm = strn1 * strn2;
		printf(" ������� �������������� = %d \n", Sprm);
	} break;

	case 3:
	{
		printf("������� ������ ���������� : ");
		scanf_s("%d", &R);
		So = pi * R * R * 0.5;
		printf(" ������� ���������� = %f \n", So);
	} break;

	return 0;
	}	
}
 

