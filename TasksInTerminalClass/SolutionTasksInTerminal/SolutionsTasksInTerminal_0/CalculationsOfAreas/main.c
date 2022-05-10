#include <stdio.h>
#include <math.h>
#include <locale.h>


	int main()
	{
		setlocale(LC_ALL, "Rus");
		int f;

		printf("Введите 1 для нахождения S треугольника, 2 прямоугольника, 3 круга = ");
		scanf_s("%d", &f);

		switch (f) 
		{
		  case 1:
				
				{
					float a, h, S;

					printf("Введите основание и высоту треугольника: \na = ");
					scanf_s("%f", &a);
					printf("h = ");
					scanf_s("%f", &h);

					S = 0.5 * a * h;

					printf("Площадь треугольника = %.2f", S);

				}
				break;

		        case 2:
				
					
					{
						float a, b, S;

						printf("Введите стороны прямоугольника: \n a = ");
						scanf_s("%f", &a);
						printf(" h = ");
						scanf_s("%f", &b);

						S = a * b;

						printf("Площадь прямоугольника = %.2f ", S);

					}
					break;

				    case 3:

					
						{
							float r, S, Pi = 3.14;

							printf("Введите радиус круга:\n r = ");
							scanf_s("%f", &r);

							S = pow(r, 2) * Pi;

							printf("Площадь круга = %.2f", S);

						}
						break;

					    default:
				      
						printf("Похоже вы ввели некорректные данные, пожалуйста попробуйте ещё раз.");
			
		}

		_getch();
		return 0;
	}