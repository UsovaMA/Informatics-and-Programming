#include <iostream>
#include <string>
using namespace std;
class TDecimal
{
public:
    enum { SIZE = 100 }; // в коде и спользую enum для перечисления числовых констант чтобы использовать их в вычислениях.

protected:
    unsigned char val[SIZE];// Именно что только положительное  
     // unsigned потому что вычисления наши не могут быть отрицательными , а char потому что нам нужен только целочисленный тип.

    unsigned size;

public:
    TDecimal(unsigned value = 0) //: size(0) 
    {
        this->size = 0;
        *this = value;
    }
    TDecimal(const string& value) //: size(0)
    {
        this->size = 0;
        *this = value;
    }
    //как я присваиваю определено ниже
//	//Если это цифры, то выполняется верхнее, если строка, то нижнее
//	//Если строковый тип переменной присваивается к переменной типа Tdecimal, то выполняется нижнее

    TDecimal& operator = (unsigned value) // цифры и именно положительное 
    {
        size = 0;
        while (value)
        {
            val[size++] = value % 10;
            value /= 10;
        }

        return *this;
    }
    TDecimal& operator = (const string& value) //строковый тип
    {
        size = value.size();
        for (unsigned i = 0; i < size; ++i)
        {
            val[i] = value[size - i - 1] - 48;
        }

        return *this;
    }

    unsigned operator [] (unsigned i)
    {
        unsigned char digit = 0;

        if (i < size)
        {
            digit = val[size - i];
        }

        return digit;
    }

    TDecimal& operator + (const TDecimal& dec) // сложение 
    {
        TDecimal result;

        unsigned mod = 0;

        result.size = (size < dec.size) ? dec.size : size;

        for (unsigned i = 0; i < result.size; ++i)
        {
            result.val[i] = val[i] + dec.val[i] + mod;

            mod = result.val[i] / 10;

            result.val[i] %= 10;
        }

        if (mod)
        {
            result.val[result.size++] = 1;
        }

        return result;
    }
    TDecimal& operator - (const TDecimal& dec) // вычитание 
    {
        TDecimal result;

        unsigned mod = 0;

        result.size = (size < dec.size) ? dec.size : size;

        for (unsigned i = 0; i < result.size; ++i)
        {
            result.val[i] = val[i] - dec.val[i] + mod;

            mod = result.val[i] / 10;

            result.val[i] %= 10;
        }

        if (mod)
        {
            result.val[result.size++] = 1;
        }

        return result;
    }
    const bool& operator== (const TDecimal& dec) // сравнение
    {
        TDecimal result;

        unsigned mod = 0;
        bool ch = true;
        result.size = (size < dec.size) ? dec.size : size;

        for (unsigned i = 0; i < result.size; ++i)
        {
            if (!(val[i] == dec.val[i]))
                ch = false;
        }

        return ch;
    }

    unsigned GetSize() const
    {
        return size;
    }

    friend ostream& operator << (ostream& os, const TDecimal& digit) // сравнение 
    {
        for (unsigned i = digit.size - 1; i < digit.size; --i)
        {
            os << (unsigned)digit.val[i];
        }
        return os;
    }
};
int main()
{
    //создаю 2 переменные "a" и "b" и кладëшь в них какое - то значение
    TDecimal a(123456789), b("929876789");

    cout << (a + b) << endl;
    cout << (b - a) << endl;
    a = b;
    cout << a << endl;

    if (a == b)
        cout << "a==b";
    else
        cout << "a!=b";
    return 0;
}




//#include <iostream>
//
//using namespace std;
//
//class TDecimal
//{
//public:
//	enum { SIZE = 100 }; // в коде и спользую enum для перечисления числовых констант чтобы использовать их в вычислениях.
//
//protected:
//	unsigned char val[SIZE]; // unsigned потому что вычисления наши не могут быть отрицательными , а char потому что нам нужен только целочисленный тип.
//	unsigned size;
//
//public:
//	TDecimal(unsigned value = 0) //: size(0)
//	{
//		this->size = 0;
//		*this = value;
//	}
//	TDecimal(const string& value) //: size(0)
//	{
//		this->size = 0;
//		*this = value;
//	}
//	//как я присваиваю определено ниже
//	//Если это цифры, то выполняется верхнее, если строка, то нижнее
//	//Если строковый тип переменной присваивается к переменной типа Tdecimal, то выполняется нижнее
//
//	TDecimal& operator = (unsigned value) // цифры и именно положительное 
//
//	{
//		size = 0;
//		while (value)
//		{
//			val[size++] = value % 10;
//			value /= 10;
//		}
//
//		return *this;
//	}
//	TDecimal& operator = (const string& value) //строковый тип
//	//Вот например для ровно
//	{
//		size = value.size();
//		for (unsigned i = 0; i < size; ++i)
//		{
//			val[i] = value[size - i - 1] - 48;
//		}
//
//		return *this;
//	}
//
//	friend TDecimal operator + (const TDecimal& dec, TDecimal& dec2) // сложение и вычитание использую friend потому что иначе он бы не получил доступ к переменной size т.к. она в привате.
//	{
//		TDecimal result;
//
//		unsigned mod = 0;
//
//		result.size = (dec2.size < dec.size) ? dec.size : dec2.size;
//
//		for (unsigned i = 0; i < result.size; ++i)
//		{
//			result.val[i] = dec2.val[i] + dec.val[i] + mod;
//
//			mod = result.val[i] / 10;
//
//			result.val[i] %= 10;
//		}
//
//		if (mod)
//		{
//			result.val[result.size++] = 1;
//		}
//
//		return result;
//	}
//
//	friend ostream& operator « (ostream& os, const TDecimal& digit) // сравнение
//	{
//		for (unsigned i = digit.size - 1; i < digit.size; —i)
//		{
//			os «(unsigned)digit.val[i];
//		}
//		return os;
//	}
//};
//
//int main()
//// создаю 2 переменные "a" и "b" и кладëшь в них какое - то значение
//// В cout вывожу сумму этих двух значений
//
//{
//	TDecimal a(5), b("44");
//
//	cout «(a + b) « endl;
//}