#include<stdio.h>
#include<locale.h>
#include<math.h>
#define scale 1000000

int main()
{
	setlocale(LC_ALL, "russian");
	int dverWood, polkaDSP, h, d, w, tolshina3 = 1;
	float zadDSP, bokDSP, nizDSP, tolshina1 = 0.5, tolshina2 = 1.5;
	int flag = 0;
	do {
		printf("������� ������ � ������(������:180-220; ������:80-120)(����� ������):");
		scanf_s(" %d %d", &h, &w);
		if ((h > 179 && h < 221) && (w > 79) & (w > 121))
			flag = 1;
		else
			printf("������������ ��������\n");
	} while (flag != 1);

	do {
		printf("������� �������: ");
		scanf_s("%d", &d);
		if (d > 49 && d < 90)
		flag = 1;
		else
			printf("������������ ��������\n");
	} while (flag != 1);
	 
	int dsp, dvp, wood;
	printf("������� ��������� ��� � ��� � ������");
	scanf_s("%d %d %d", &dsp, &dvp, &wood);

	zadDSP = (h * w * tolshina1) / scale;
	bokDSP = (h * w * tolshina2) / scale;
	nizDSP = (w * d * tolshina2) / scale;
	dverWood = (h * w / 2 * tolshina3) / scale;

	float tolshina4;

	printf("������� �������� �����:");
	scanf_s(" %f", &tolshina4);
	polkaDSP = (d * w * tolshina4)/scale;
	float kolvopolok = h / 40;
	float m;
	m = (zadDSP * dvp) + ((bokDSP * 2) * dsp) + ((nizDSP * 2) * dsp) + ((dverWood * 2) * wood) + (floor(kolvopolok) * polkaDSP * wood);
	printf("��� �����-%.1f", m);
	return 0;

}