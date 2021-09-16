#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main() {
	int a, p1, p2;
	float S;
	//input
	printf("Programma nahojdeniya ploshadey figur \n\n Ukazhite nomer figuri, ploshad kotoroy nujno nayti:\n1.Treugolnik\n2.Pramougolnik\n3.Okrujnost\n");
	scanf_s("%d", &a);
	//solution
	if (a == 1) {
		printf("Vvedite parametri treugolnika: visotu  i osnovanie (cherez probel)\n ");
		scanf_s("%d %d",&p1, &p2); // vvod visota and osnovanie
		S = p1 * p2 * 0.5 ; // ploshad treugolnika
		printf("Ploshad treugolnika = %.2f",S);
	}
	else {
		if (a == 2) {
			printf("Vvedite parametri pramougolnika: storona 1 i storona 2 (cherez probel)\n ");
			scanf_s("%d %d", &p1, &p2); // vvod storon
			S = p1 * p2 ; // ploshad pramoug
			printf("Ploshad pramougolnika = %.2f", S);
		}
		else {
			printf("Vvedite radius okrujnosti\n ");
			scanf_s("%d", &p1); // vvod radisus
			S = pow(p1,2) * M_PI; // ploshad okruj
			printf("Ploshad okrujnosti = %.2f", S);
		}
	}
	
	return 0;
}