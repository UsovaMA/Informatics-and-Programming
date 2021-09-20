#include <stdio.h>
#include <math.h>
#define scale 1000000

/*Начало программы */
int main()
{
	/*Вводим русский язык в проект*/

	/*Вводим переменные, которые нужны в начале*/

	int doorWood, shelfDsp, h, d,
		w, thickness3 = 1;

	float backCBdvp, sideCBdsp, downCBdsp,
		thickness1 = 0.5, thickness2 = 1.5;


	int flag = 0;
	/*Просим пользователя ввод высоты и ширины, проверяя правильность диапазона*/

	do {
		printf("Enter width and height (height: 180-220; width:80-120)(through a space): ");
		scanf_s("%d %d", &h, &w);
		if ((h > 179 && h < 221) && (w > 79) && (w < 121))
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*Просим пользователя ввод глубины, проверяя правильность диапазона*/

	do {
		printf("Enter depth: ");
		scanf_s("%d", &d);
		if (d > 49 && d < 90)
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*Просим пользователя ввести плотность ДСП, ДВП и дерева*/

	int dsp, dvp, wood;

	printf("Уnter the density of Chipboard Fiberboard and Wood: ");
	scanf_s("%d %d %d", &dsp, &dvp, &wood);

	/*Считаем объем всех частей шкафа*/

	backCBdvp = (h * w * thickness1) / scale;
	sideCBdsp = (h * d * thickness2) / scale;
	downCBdsp = (w * d * thickness2) / scale;
	doorWood = (h * w / 2 * thickness3) / scale;

	/*Так как не дана толщина полок - даем ввести ее пользователю: */

	float thickness4;

	printf("input shelf's thickness: ");
	scanf_s("%f", &thickness4);

	shelfDsp = (d * w * thickness4) / scale;

	/*Введем переменную для количества полок*/

	float shelfAmount;

	shelfAmount = h / 40;

	/*Находим объем шкафа: */

	float m;

	m = (backCBdvp * dvp) + ((sideCBdsp * 2) * dsp) + ((downCBdsp * 2) * dsp) + ((doorWood * 2) * wood) + (floor(shelfAmount) * shelfDsp * wood);

	printf("Cupboard's weight - %.1f", m);

	return 0;
}