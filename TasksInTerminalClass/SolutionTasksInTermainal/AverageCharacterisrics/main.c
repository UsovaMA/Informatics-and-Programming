#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	//input
	printf("Programma nahojdenia srednih characteristic 3 chisel\n Vvedite 3 chisla (cherez probel)\n");
	scanf_s("%d %d %d", &a, &b, &c);
	float averSquare, averArith, averFab, averSqrt;
	//sol
	averArith = (float)(a + b + c) / 3; //average arithmetics
	averSquare = (float)(pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3; // average squares
	averFab = (float)(fabs(a) + fabs(b) + fabs(c)) / 3; // avrage modulei
	averSqrt = (float)(sqrt(a) + sqrt(b) + sqrt(c)) / 3; // average kornei
	//output
	printf("Srednee arifmeticheskoe znachenie = %.2f\nSrednee kvadratov etih chisel =%.2f\nSrednee modulei = %.2f\nSrednee kornei etih chisel = %.2f", averArith, averSquare, averFab, averSqrt);
	return 0;
}
