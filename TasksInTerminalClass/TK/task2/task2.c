

#include <stdio.h>
#include <math.h>

int main()
{
	int n, m;
	m = 0;
	printf("vvedite chislo: ");
	scanf_s("%d", &n);
	if (n >= 25)
		do {
			n -= 25;
			m += 1;
		} while (n >= 25);

		if (n >= 10)
			do {
				n -= 10;
				m += 1;
			} while (n >= 10);

			if (n >= 5)
				do {
					n -= 5;
					m += 1;
				} while (n >= 5);

				if (n >= 1)
					do {
						n -= 1;
						m += 1;
					} while (n >= 1);

					printf("%d", m);

					return 0;
}