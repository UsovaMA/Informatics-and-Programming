#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE,"ru");

    float h, w, d;
    float v,p,m;
//1
    printf("задняя стенка\n");
    printf("высота от 180 до 220см:");
    scanf("%f", &h);
    printf("ширина от 80 до 120 см:");
    scanf("%f", &w);
    printf("толщина: 5 мм");
//2
    printf("\nдве боковины\n");
    printf("глубина от 50 до 90 см:");
    scanf("%f", &d);
    printf("высота: %f", d);
    printf("\nтолщина: 15 мм");
//3
    printf("\nнакладные верхняя и нижняя крышки\n");
    printf("ширина: %f", w);
    printf("\nглубина: %f", d);
    printf("\nтолщина: 15 мм");
//4
    printf("\nдве накладные двери:\n");
    printf("высота: %f",h);
    printf("\nширина: %f", w);
    printf("\nтолщина: 1 см");

    printf("\n4 внутренние полки:");
    printf("\nтолщина: 1 см");

    v = (d * h * w)/1000000;

    p = 0.075; //м

    m = (v*(p/73)); //ДСП = 73 кг

    printf("\nмасса кг/м^3: %f",m);

    return 0;
}

