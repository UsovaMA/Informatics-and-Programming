#include <stdio.h>
#include <math.h>
#include <locale.h>


	int main()
	{
		setlocale(LC_ALL, "Rus");
		int f;

		printf("������� 1 ��� ���������� S ������������, 2 ��������������, 3 ����� = ");
		scanf_s("%d", &f);

		switch (f) 
		{
		  case 1:
				
				{
					float a, h, S;

					printf("������� ��������� � ������ ������������: \na = ");
					scanf_s("%f", &a);
					printf("h = ");
					scanf_s("%f", &h);

					S = 0.5 * a * h;

					printf("������� ������������ = %.2f", S);

				}
				break;

		        case 2:
				
					
					{
						float a, b, S;

						printf("������� ������� ��������������: \n a = ");
						scanf_s("%f", &a);
						printf(" h = ");
						scanf_s("%f", &b);

						S = a * b;

						printf("������� �������������� = %.2f ", S);

					}
					break;

				    case 3:

					
						{
							float r, S, Pi = 3.14;

							printf("������� ������ �����:\n r = ");
							scanf_s("%f", &r);

							S = pow(r, 2) * Pi;

							printf("������� ����� = %.2f", S);

						}
						break;

					    default:
				      
						printf("������ �� ����� ������������ ������, ���������� ���������� ��� ���.");
			
		}

		_getch();
		return 0;
	}