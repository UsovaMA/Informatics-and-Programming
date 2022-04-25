#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  int n, m=0;

	printf("введите число: ");
	scanf_s("%d", &n);

	while (n >= 25) {
	    n -= 25;
	    m += 1;
	} 

	while (n >= 10) {
	    n -= 10;
	    m += 1;
    } 

	while (n >= 5) {
	    n -= 5;
	    m += 1;
	} 

	while (n >= 1) {
	    n -= 1;
	    m += 1;
	} 

	 printf("%d", m);

return 0;
}