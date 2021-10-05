#include<math.h>;
#include<stdio.h>;
#include<locale.h>;




int main() {
	setlocale(LC_ALL, "RUS");
	int c1 = 0,  c5 = 0, c10 = 0,x;
	char c25 = 0;
	scanf_s("%d", &x);
	while (x > 0)
	{
		if (x - 25 > 0)
		{
			x = x - 25;
			c25++;

		}
		else if (x - 10 > 0) 
		{
			x = x - 10;
			c10++;
		}
		else if (x - 5 > 0)
		{
			x = x - 5;
			c5++;
		}
		else
		{
			x = x - 1;
			c1++;
		}
		printf(&c25, &c10, &c5, &c1);
	}


	



		


	


	

	
	

	


	
	
	








}
