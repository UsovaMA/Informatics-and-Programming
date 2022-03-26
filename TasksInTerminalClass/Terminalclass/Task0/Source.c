#include <math.h>
#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
    double  pi = 3.14, a, b, c, r, m, v, S1, S2, S3, p;
	printf("введите стороны треугольника(a,b,c)");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);

	printf("введите стороны прямоугольника(v,m)");
	scanf_s("%lf", &v);
	scanf_s("%lf", &m);
	printf("введите радиус окружности (r)");
	scanf_s("%lf", &r);

	p = (a + b + c)/2;
	S1 = sqrt(p*(p - a)*(p - b)*(p - c));
	S2 = v * m;
	S3 = pi * (r * r);
	printf("площадь треугольника равна %lf\n",S1);
	printf("площадь круга равна %lf\n", S3);
	printf("площадь прямоугольника равна %lf\n", S2);
	return 0;
}