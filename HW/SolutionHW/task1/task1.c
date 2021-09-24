#include <stdio.h>
#include <locale.h>




int main()
{
	setlocale(LC_ALL, "Russian");

	//Плотности для материалов: ДВП, ДСП, Дерево (в гр/см^3)
	double dvpdens = 0.7, dspdens = 0.55, wooddens = 0.85;

	//Нужно ввести значения перед вычислениями св-ств задней стенки и проверить на соответсвие условиям
	int bdoorh, bdoorw;
	float bdoort = 0.5;
	double bdoorV, bdoorM;

	printf("Введите высоту задней стенки шкафа (в пределах от 180 до 220 см):\n");
	scanf_s("%d", &bdoorh);

	printf("Введите ширину задней стенки шкафа (в пределах от 80 до 120 см):\n");
	scanf_s("%d", &bdoorw);

	if ((180 <= bdoorh <= 220) && (80 <= bdoorw <= 120))
	{
		printf("Все данные соответствуют условию. Рассчивытваем объём задней стенки шкафа...\n");
	}
	else
	{
		printf("Введите данные снова, соблюдая условия.");
	}



	//Теперь рассчитаем объём и массу задней стенки
	bdoorV = bdoorh * bdoorw * bdoort;
	printf("Объем задней стенки шкафа будет равен = %.1lf куб.см\n", bdoorV);
	bdoorM = (bdoorV * dvpdens);												//Рассчитываем массу в граммах
	bdoorM = bdoorM * 0.001;												//Переводим массу в килограммы для приятных рассчетов
	printf("Масса задней стенки шкафа равна = %.3lf кг\n", bdoorM);


	//Ввести данные для боковин в сантиметрах и проверяем соотв условию
	int swalld;
	float swallw = 1.5;
	double swallV, swallM;
	//Обычно у шкафов высота боковин соответствует высоте задней панели, так что нам не стоит рассчитывать и вводить новую переменную для них.

	printf("Введите глубину боковин (от 50 до 90 см):\n");
	scanf_s("%d", &swalld);

	if (50 <= swalld <= 90)
	{
		printf("Данные удовлетворяют условию. Приступаем к рассчету...\n");
	}
	else
	{
		printf("Проверьте корректность данных на соответсвие условию.");
	}

	//Производим рассчеты боковин. По условию их 2, так что нужно получить массу сразу 2-х.
	swallV = bdoorh * swalld * swallw;
	swallM = (swallV * dspdens) * 2;

	printf("Объем одной боковины шкафа будет равен = %.1lf куб.см\n", swallV);
	printf("Масса двух боковин шкафа равна = %.3lf кг\n", swallM);


	//Переменные для верхней и нижней крышки. Вводим значения в см, условий нет.
	int lidw, lidd;
	float lidt = 1.5;
	double lidV, lidM;

	printf("Введите ширину крышек шкафа:\n");
	scanf_s("%d", &lidw);

	printf("Введите глубину крышек шкафа:\n");
	scanf_s("%d", &lidd);

	//Делаем рассчет
	lidV = lidw * lidd * lidt;
	lidM = (lidV * dspdens) * 2;
	printf("Объем крышки шкафа равен = %.1lf куб.см\n", lidV);
	printf("Масса крышек будет равна = %.3lf кг\n", lidM);


	//Переменные для накладных дверей. Их 2, условий нет. 
	int doorh, doorw, doort = 1;
	double doorV, doorM;
	
	printf("Введите высоту двери:\n");
	scanf_s("%d", &doorh);

	printf("Введите ширину двери:\n");
	scanf_s("%d", &doorw);

	//Рассчет объема и массы дверей шкафа 
	doorV = doorh * doorw * doort;
	doorM = (doorV * wooddens) * 2;
	printf("Объем одной двери шкафа = %.1lf куб.см\n", doorV);
	printf("Масса двух дверей шкафа = %.3lf кг\n");


	//Переменная кол-ва полок в шкафу. Каждая полка ставится раз через 40 см. 
	int shelfamount;
	double shelfV, shelfM;

	//Считаем кол-во полок которые можем уместить.
	shelfamount = bdoorh / 40;
	//Длина и ширина полок равна длине и ширине крышек. Нет смысла вводить новые переменные
	printf("В шкаф уместится %d полок. Размеры полок %d в ширину, 1 см в высоту, %d в длину\n", shelfamount, lidw, lidd);

	shelfV = lidw * lidd;
	shelfM = (shelfV * dspdens) * shelfamount;

	printf("Объем полки равен = %.1lf куб.см\n", shelfV);
	printf("Масса полок равна = %.3lf кг\n", shelfM);

	//Остается сложить все части, чтобы получить массу шкафа.

	double ShkafM;
	ShkafM = bdoorM + swallM + lidM + doorM + shelfM;

	printf("Масса всего шкафа будет равна = %.3lf кг", ShkafM);
	return 0;
};