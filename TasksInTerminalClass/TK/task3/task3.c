#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, iw = 1;
	while (iw) {
		printf("vvedite nomer\n");
		printf("dlya vihoda vvedi 0");
		int ie = 0;
		do {
			if (ie) printf("oshibka, poprobui eshe");
			printf("vvedite polojitelnii nomer");
			scanf("%d", &n);
			if (n == 0) iw = 0; break;
			ie = (n <= 0);

		} while (ie);
		int inv = 0, d = 10;
		while (n) {
			inv *= d;
			inv += n % d;
			n = n / d;
		}
		if (iw) printf("rezultat %d\n\n", inv);
		if (ie) printf("vihod\n\n");
	}

	return 0;
}