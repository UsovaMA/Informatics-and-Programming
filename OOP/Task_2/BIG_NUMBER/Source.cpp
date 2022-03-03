#include <iostream>
#include <string>

using namespace std;




class Decimal
{
	int num;
	unsigned char* massch;
	int* massint;
	int* massres;
	

public:

	Decimal(int size)
	{
	    
		num = size;
		massch = new unsigned char[num];	
		massint = new int[num];

		void fill();
		{
			char n;
			for (int i = 0; i < num; i++)
			{
				cin >> n;
				massch[i] = n;
			}

		}
		for (int i = 0; i < num; i++)
		{
		    massint[i] = (int)massch[i] - 48;
		}

		for (int i = 0, j = num - 1; i < j; i++, j--)   
 
		{
			int buf = massint[i];
			massint[i] = massint[j];
			massint[j] = buf;
		}
	}
	Decimal()
	{

		for (int i = 0; i < num; i++)
		{
			massres[i] = 0;
		}

	}
	
	
	

	void Out()
	{
		for (int i = 0; i < num; i++)
		{
			cout << massint[i] << endl;
		}
	}

	Decimal operator =(const Decimal first[] )
	{
		for (int i = 0; i < num; i++)
		{
			if (this == &first[i])
			{
				return *this;
			}
		}
		
		Decimal temp(num);
		
		for (int i = 0; i < num; i++)
		{
			
			this->massint[i] = first->massint[i];
			this->massch[i] = first->massch[i];
			this->num = first->num;
			this->num = first->massres[i];
		}
		return *this;
	}
	Decimal operator+(Decimal first[])
	{
		
		Decimal temp(num);

		for (int i = 0; i < num; i++)
		{
			temp.massint[i] = massint[i] + first->massint[i];
		}
		return temp;
	}

};

int main()
{

	Decimal a(5), b(5);
	
	Decimal p;

	
	
	

	

}

