#include <iostream>
#include <string>
#include <locale.h>


using namespace std;


class Distance
{
private:

	int met;
	
public:
	Distance()
	{
		met = 0;	
	}

	Distance(int f, int var)
	{
		if (f==1)
		{
			met = var * 1000;
		}
		else
		{
			met = var * 1610;
		}
	}
	Distance(int metp)
	{

		met = metp;

	}

	
	void print()
	{
		cout << this->met << endl;
	}

	void to_miles(int var)
	{
		var = var / 1610;
	}

	void to_kilometrs(int var)
	{
		var = var / 1000;
	}

	

	Distance& operator+(const Distance& right)
	{
		Distance p;

		p.met = this->met + right.met;

		return p;
	}

	Distance& operator-(const Distance& right)
	{
		Distance p;
		
		if (right.met > this->met)
		{
			cout << "Расстояние не может быть отрицательным!!!" << endl;
		}
		else
		{
			p.met = this->met - right.met;

			return p;
		}
	
	}

	Distance& operator=(const Distance& right)
	{
		if (this == &right)
		{
			return *this;
		}

		this->met = right.met;

		return *this;
	}

	bool operator>(const Distance& right)
	{
		return (this->met > right.met);
	}

	bool operator<(const Distance& right)
	{
		return (this->met < right.met);
	}

	bool operator==(const Distance& right)
	{
		return (this->met == right.met);
	}

	bool operator!=(const Distance& right)
	{
		return (this->met != right.met);
	}

	bool operator>=(const Distance& right)
	{
		return (this->met >= right.met);
	}

	bool operator<=(const Distance& right)
	{
		return (this->met <= right.met);
	}

};



int main()
{

	setlocale(LC_ALL, "RUSSIAN");

	int f = 0;
	int var = 0;
	int f1 = 0;
	int var1 = 0;

	cout << "Введите тип расстояния 1 - километры, 2 - мили" << endl;
	cin >> f;
	cout << "Введите 1 расстояние" << endl;
	cin >> var;

		Distance a(f, var);
		
	cout << "Введите тип расстояния 1 - километры, 2 - мили" << endl;
	cin >> f1;
	cout << "Введите 1 расстояние" << endl;
	cin >> var1;

	    Distance b(f, var1);


		Distance r = a + b;

		


		r.print();

}