#include <stdio.h>
#include <math.h>

int main() //start programm
{
	int sum, kol;
	kol = 0;
	printf("Input a witcher coast: ");
	scanf_s("%d", &sum);
	while (sum >= 25) {
		sum -= 25;
		kol += 1;
	}
	while (sum >= 10) {
		sum -= 10;
		kol += 1;
	} 
	while (sum >= 5) {
		sum -= 5;
		kol += 1;
	} 
	while (sum >= 1) {
		sum -= 1;
		kol += 1;
	} 

	printf("%d", kol);

return 0;
}