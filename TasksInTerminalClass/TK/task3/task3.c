#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  int n, iw = 1;

	while (iw) {

		printf("������� �����\n");
		printf("��� ������ ����� 0 0");

	  int ie = 0;
		do {if (ie) 
				    printf("������,�������� ���");
			        printf("������� ������������� �����");
			        scanf("%d", &n);

			if (n == 0) iw = 0; break;
			ie = (n <= 0);
        }
		
	while (ie);

	  int inv = 0, d = 10;

		while (n) {

			inv *= d;
			inv += n % d;
			n = n / d;
		}
	if (iw) printf("��������� %d\n", inv);
    if (ie) printf("�����\n");
	}

	return 0;
}