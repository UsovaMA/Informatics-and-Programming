#include <stdio.h> 
#include <math.h>
//Opredelit', kakovo vzaimnoe raspolozhenie dvuh okruzhnostej s zadannymi koordinatami centrov i radiusami.

int main() {
	float x1, x2, y1, y2, rad1, rad2;
	float dist;
	//input
	printf("Programma opredelenia vzaimnogo raspolojenia dvuh okrujnostei\n\n");
	printf("Vvedite parametri okrujnostei: \n koordinati centra 1 okrujnosti and radius (x  y radius (cherez probel)\n");
	scanf_s("%f %f %f", &x1, &y1, &rad1);
	printf("Vvedite parametri okrujnostei: \n koordinati centra 2 okrujnosti and radius (x  y radius (cherez probel)\n");
	scanf_s("%f %f %f", &x2, &y2, &rad2);
	// solution
	dist = (float)(sqrt(pow((x2 - x1),2) + pow((y2 - y1),2))); // rasstoynie mezhdu centrami okrujnostei
	//output
	if (dist > (rad1 + rad2)) {
		printf("Kazhdaya iz okruzhnostej lezhit vne drugoj\n");
	}
	else {
		if (dist == rad1 + rad2) {
			printf("Vneshnee kasanie dvuh okruzhnostej\n");
		}
		else {
			if (dist == rad1 - rad2 ) {
				printf("Vnutrennee kasanie dvuh okruzhnostej\n");

			}
			else {
				if ((rad1 - rad2 ) < dist && dist < (rad1 + rad2)) {
					printf("Okruzhnosti peresekayutsya v dvuh tochkah\n");

				}
				else {
					if (dist < rad1 - rad2) {
						printf("2 Okrujnost lejit vnutri 1\n");

					}
					else {
						printf("1 okrujnost lejit vnutr 2\n");

					}
				}
			}
		}
	}
	
	return 0;
}
