#include <iostream>
#include <string>
using namespace std;
class Money
{
public:

	double amount_of_money;
	double summ;
	int rub;
	int cop;

	Money()
	{
		amount_of_money = 0, rub = 0, cop = 0, summ = 0;
	}

	Money(int _rub, int _cop, double _amount_of_money)
	{

		rub = _rub;
		cop = _cop;
		amount_of_money = _amount_of_money;

	}
	void rub_cop(int _rub, int _cop)
	{
		_rub = amount_of_money + _rub;
		_rub = _rub + _cop / 100;
		_cop = _cop % 100;
	}

	Money& operator=(const Money& right)
	{

		if (this == &right) {
			return *this;
		}
		rub = right.rub;
		cop = right.cop;
		return *this;
	}
	Money operator+(const Money&)
	{
		void rub_cop(int _rub, int _cop);
		amount_of_money = amount_of_money + rub;
		amount_of_money = (amount_of_money * 100) + cop;
	}

	Money operator-(const Money&)
	{
		void rub_cop(int _rub, int _cop);
		if (cop > 0)
		{
			rub - 1;
			cop + 100;
		}
		amount_of_money = amount_of_money - rub;
		amount_of_money = (amount_of_money * 100) - cop;
	}









};

