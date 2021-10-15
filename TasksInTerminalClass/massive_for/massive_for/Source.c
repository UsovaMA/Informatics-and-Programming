#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru");
	int n,  cnt = 0, mass[] = { 5,6,7,8,1,2,3,4 }; 
	float len = sizeof(mass) / sizeof(int); 
	

	if ((int)len % 2 != 0)
	{
		int sr = len / 2 + 1; 
		while (len != sr + cnt)
		{
			n = mass[cnt];
			mass[cnt] = mass[(int)sr + cnt];
			mass[(int)sr + cnt] = n;
			cnt++;
		}
	}
	else
	{
		int sr = len / 2; 
		while (sr + cnt != len)
		{
			n = mass[cnt];
			mass[cnt] = mass[sr + cnt];
			mass[sr + cnt] = n;
			cnt++;
		}
	}
	printf(" \n Без дополнительного массива \n");
	for (int i = 0; i != len; i++) 
	{
		printf("%d ", mass[i]);
	}

	

	int* dmass = (int*)malloc((int)len * sizeof(int)); 
	cnt = 0;
	free(dmass);

	if ((int)len % 2 != 0)
	{
		int sr = len / 2;
		while (sr + cnt != len)
		{
			dmass[cnt] = mass[sr + cnt + 1];
			dmass[(int)len - cnt] = mass[sr - cnt];
			cnt++;
		}
		dmass[sr] = mass[sr];
	}
	else
	{
		int sr = len / 2;
		while (sr + cnt - 1 != len)
		{
			dmass[cnt] = mass[sr + cnt];
			dmass[(int)len - cnt] = mass[sr - cnt];
			cnt++;
		}
	}
	printf("\n С дополнительным массивом \n ");
	for (int i = 0; i != len; i++) 
	{
		printf("%d ", dmass[i]);
	}
}