#include <stdio.h>



/*Firma «Umelye ruchki» vypuskaet dvuhdvernye odezhnye shkafy. Sostav shkafa:

nakladnaya zadnyaya stenka iz DVP vysotoj h ot 180 do 220 sm, shirinoj w ot 80 do 120 sm i tolshchinoj 5 mm,
dve bokoviny iz DSP vysotoj h, glubinoj d ot 50 do 90 sm i tolshchinoj 15 mm,
nakladnye verhnyaya i nizhnyaya kryshki iz DSP shirinoj w, glubinoj d i tolshchinoj 15 mm,
dve nakladnye dveri iz dereva vysotoj h, obshchej shirinoj w i tolshchinoj 1 sm,
vnutrennie polki v shkafu cherez kazhdyj 40 sm iz DSP.
Schitaya, chto izvestny plotnosti DSP, DVP i dereva, najti massu shkafa.*/
int main() {
	float h, w ,d;
	int count_polki;
	int DVP = 1; // plotnost dvp = 1 gram na sm v kube 
	float DSP = 0.8; // plotnost dsp = 0.8 gram na sm v kube 
	float derevo = 0.45; // plotnost dereva = 0.45 gram na sm v kube (lipa)
	float width_back = 0.5; // tolshina zadnei stenki
	float width_side = 1.5; // tolshina bokovix stenok and top and bottom 
	int dist_polki = 40; // rasstoyanie mejdu polkami
	float width_door = 1;
	float width_polki = 1;
	printf("Programma nahojdenia massi shkafa\n\n");
	printf("Vvedite parametri zadney stenki(cherez probel): visota (ot 180 do 220), shirina (ot 80 do 120) \n ");
	scanf_s("%f %f", &h,&w);
	if (!((180 <= h) && (h <= 220)) || !((80 <= w) && (w <= 120))) {
		printf("Proverte pravilnost vvedenih dannih");
	}
	else {
		printf("Vvedite parametri glubini bokovih stenok(ot 50 do 90) \n ");
		scanf_s("%f", &d);
		if (!((50 <= d) && (d <= 90))) {
			printf("Proverte pravilnost vvedenih dannih");
		}
		else {
			count_polki = h / dist_polki ;
			float massa_back = h * w * width_back * DVP; // massa back wall in gramms 
			float massa_bok = h * d * width_side * DSP; // massa bokovih stenok
			float massa_tab = w * d * width_side * DSP; // massa top and bottom
			float massa_polki = count_polki * d * w * width_polki * DSP; // massa polok
			float massa_door = h * w * width_door * 2 * derevo; // massa dverei
			float massa_shkafa = massa_back + massa_bok + massa_door + massa_polki + massa_tab; 
			printf("Massa shkafa = %.2f kg", (float)(massa_shkafa/1000) );
		}
	}

	return 0;
}