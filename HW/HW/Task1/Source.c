#include <math.h>
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");

	double pdsp = 600; //��������� ���
	double pdvp = 800; // ��������� ���
	double pder = 1000; // ��������� ������
	double h, w, t1 = 0.005, t2 = 0.015, t3 = 0.01, d, V1,V2,V3;
	double mas = 0;
	
	printf("������� ������ �����(�� 180 �� 220):\n");
	scanf_s("%lf", &h);
	
	printf("������� ������ �����(�� 80 �� 120):\n");
	scanf_s("%lf", &w);

	printf("������� ������� �����(�� 50 �� 90):\n");
	scanf_s("%lf", &d);
	if (h < 200) {
		h = h / 100;
		w = w / 100;
		d = d / 100;
		V1 = (h * w * t1) ;
		V2 =((h * d * t2) * 2) + ((w * d * t2) * 2) + ((d * w * t2) * 4);//� ������� �� ������� ������� �����,� ���� 15 �����������
		V3 = (h * w * t3);
	    mas = (V1 * pdvp) + (V2 * pdsp) + (V3 * pder);
		printf("mas=%lf", mas);
	}
	else if (h >= 200) {
		h = h / 100;
		w = w / 100;
		d = d / 100;
		V1 = (h * w * t1) ;
		V2 = ((h * d * t2) * 2) + ((w * d * t2) * 2) + ((d * w * t2) * 5);
		V3 = (h * w * t3);
		mas = (V1 * pdvp) + (V2 * pdsp) + (V3 * pder);
		printf("mas=%lf", mas);
	}
	return 0;
}