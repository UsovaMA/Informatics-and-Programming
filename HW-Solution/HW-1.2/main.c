#include <stdio.h>
#include <math.h>
/*Dana shahmatnaya doska. Dlya dvuh razlichnyh kletok K1, K2 doski i vybrannoj pol'zovatelem figury (korol', ferz', lad'ya, slon, kon')
opredelit':

Mozhet li figura za odin hod perejti iz K1 v K2?
Esli net, mogut li eto sdelat' kakie-to iz ostal'nyh figur? Esli mogut, vyvesti ih spisok.*/
int main() 
{
	int x1, x2, y1, y2, figure, korol, ferz, ladya, slon , kon, flag;
	korol = 0; ferz = 0; ladya = 0; slon = 0; kon = 0; flag = 0;
	printf("Programma opredeleniya vozmojnosteie figuri\n\n");
	printf("Vvdeite parametri pervoi kletki (cherez probrel):nomer bukvi stolbca (v alfavite) i nomer stroki\n ");
	scanf_s("%d %d", &x1, &y1);
	if (!((1 <= x1) && (x1 <= 8)) || !((1 <= y1) && (y1 <= 8))) 
	{
		printf("Proverte pravilnost vvedenih dannih");
	}
	else 
	{
		printf("Vvdeite parametri vtoroi kletki (cherez probrel):nomer bukvi stolbca (v alfavite) i nomer stroki \n");
		scanf_s("%d %d", &x2, &y2);
		if (!((1 <= x2) && (x2 <= 8)) || !((1 <= y2) && (y2 <= 8))) 
		{
			printf("Proverte pravilnost vvedenih dannih");
		}
		else 
		{
			printf("Viberite figuru: \n 1. Korol\n 2. Ferz \n 3. Ladya \n 4. Slon \n 5. Kon'\n");
			scanf_s("%d", &figure);
			if (!((1 <= figure) && (figure <= 5))) 
			{
				printf("Proverte pravilnost vvedenih dannih");
			}
			else 
			{
				if ((abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1))
				{ 
					korol++;// korol mojet
				}
				if ((abs(x1 - x2) == abs(y1 - y2)) || (x1 == x2) || (y1 == y2)) // proverka ferz'a
				{
					ferz++; // ferz mojet
				}
				if (((abs(x1 - x2)) == 1) && ((abs(y1 - y2)) == 2) || ((abs(x1 - x2)) == 2) && ((abs(y1 - y2)) == 1)) // proverka kona
				{
					kon++;
				}
				if ((x1 == x2) || (y1 == y2)) // proverka ladya
				{
					ladya++;
				}
				if ((abs(x1 - x2)) == (abs(y1 - y2)))  //proverka slona 
				{
					slon++;
				}
				if (!korol && !ferz && !ladya && !slon && !kon) { flag++; } // flag proveryaet vse figuri na vozmojnost hoda
				switch (figure) 
				{
				case 1: 
					if (korol) 
					{
					    printf("Da, korol mojet za 1 hod pereiti iz 1 kletki vo 2");
					    break;
				    }
					else 
					{
					    printf("Net, korol ne mojet pereiti iz 1 kletki vo 2\n figuri kotorie mogut:\n");
					    if (ferz) { printf("ferz\n"); }
					    if (ladya) { printf("Ladya\n"); }
					    if (kon) { printf("Kon\n"); }
					    if (slon) { printf("slon\n"); }
						if (flag) { printf("Ni odna figura ne mojet popast iz 1 kletki vo 2"); }
						break;
				    }
				case 2: 
					if (ferz)
					{
						printf("Da, ferz mojet za 1 hod pereiti iz 1 kletki vo 2");
						break;
					}
					else
					{
						printf("Net, ferz ne mojet pereiti iz 1 kletki vo 2\n figuri kotorie mogut:\n");
						if (korol) { printf("Korol\n");} 
						if (ladya) {printf("Ladya\n");} 
						if (kon) {printf("Kon\n");} 
						if (slon) {printf("slon\n");}
						if (flag) { printf("Ni odna figura ne mojet popast iz 1 kletki vo 2"); }
						break;
					}
				case 3:
					if (ladya)
					{
						printf("Da, ladya mojet za 1 hod pereiti iz 1 kletki vo 2");
						break;
					}
					else 
					{
						printf("Net, ladya ne mojet pereiti iz 1 kletki vo 2\n figuri kotorie mogut:\n");
						if (korol) { printf("Korol\n"); }
						if (ferz) { printf("Ferz\n"); }
						if (kon) { printf("Kon\n"); }
						if (slon) { printf("slon\n"); }
						if (flag) { printf("Ni odna figura ne mojet popast iz 1 kletki vo 2"); }
						break;
					}
				case 4:
					if (slon)
					{
						printf("Da, slon mojet za 1 hod pereiti iz 1 kletki vo 2");
						break;
					}
					else
					{
						printf("Net, slon ne mojet pereiti iz 1 kletki vo 2\n figuri kotorie mogut:\n");
						if (korol) { printf("Korol\n"); }
						if (ferz) { printf("Ferz\n"); }
						if (kon) { printf("Kon\n"); }
						if (ladya) { printf("slon\n"); }
						if (flag) { printf("Ni odna figura ne mojet popast iz 1 kletki vo 2"); }
						break;
					}
				case 5:
					if (kon)
					{
						printf("Da, kon mojet za 1 hod pereiti iz 1 kletki vo 2");
						break;
					}
					else
					{
						printf("Net, kon ne mojet pereiti iz 1 kletki vo 2\n figuri kotorie mogut:\n");
						if (korol) { printf("Korol\n"); }
						if (ferz) { printf("Ferz\n"); }
						if (ladya) { printf("Kon\n"); }
						if (slon) { printf("slon\n"); }
						if (flag) { printf("Ni odna figura ne mojet popast iz 1 kletki vo 2"); }
						break;
					}
				}
			}
		}
		
	}
	return 0;
}


