#include <stdio.h>
#include <locale.h>
#include <math.h>
#define scale 1000000
#define range 40

int main() //Start of programm
{
	/*Вводим русский язык в проект*/
	setlocale(LC_ALL, "Russian");

	/*Introducing variables*/

	int doorWood, shelfDsp, h, d,
		w, thickness3 = 1;

	float backCBdvp, sideCBdsp, downCBdsp,
		thickness1 = 0.5, thickness2 = 1.5;


	int flag = 0;
	/*Asking the user to enter the height and width, checking if the range is correct*/

	do {
		printf("Enter width and height (height: 180-220; width: 80-120)(through a space): ");
		scanf_s("%d %d", &h, &w);
		if ((h > 179 && h < 221) && (w > 79) && (w < 121))
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*Asking the user to enter the depth, checking that the range is correct*/

	do {
		printf("Enter depth: ");
		scanf_s("%d", &d);
		if (d > 49 && d < 90)
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*We ask the user to enter the density of chipboard, fiberboard and wood*/

	int dsp, dvp, wood;

	printf("Уnter the density of Chipboard Fiberboard and Wood: ");
	scanf_s("%d %d %d", &dsp, &dvp, &wood);

	/*Считаем объем всех частей шкафа*/

	backCBdvp = (h * w * thickness1) / scale;
	sideCBdsp = (h * d * thickness2) / scale;
	downCBdsp = (w * d * thickness2) / scale;
	doorWood = (h * w * thickness3) / scale;

	/*Since the thickness of the shelves is not given, we give it to the user to enter it: */

	float thickness4;

	printf("input shelf's thickness: ");
	scanf_s("%f", &thickness4);

	shelfDsp = (d * w * thickness4) / scale;

	/*Let's introduce a variable for the number of shelves*/

	float shelfAmount;

	shelfAmount = h / range;

	/*Find the weight of the cabinet */

	float m;

	m = (backCBdvp * dvp) + ((sideCBdsp * 2) * dsp) + ((downCBdsp * 2) * dsp) + ((doorWood * 2) * wood) + (floor(shelfAmount) * shelfDsp * wood);

	printf("Cupboard's weight - %.1f", m);

	return 0;
}