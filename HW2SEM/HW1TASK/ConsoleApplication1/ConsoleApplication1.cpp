#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Vector

{
private:
	double X = 0;
	double Y = 0;
	double Z = 0;
	Vector() {};
public:
	Vector(double x, double y, double z)
	{
		X = x;
		Y = y;
		Z = z;

	}

	double Getlength()

	{
		return sqrt(X * X + Y * Y + Z * Z);
	}
	friend Vector operator + (Vector l, Vector r)
	{
		return Vector(l.X + r.X, l.Y + r.Y, l.Z + r.Z);
	}
	friend Vector operator - (Vector l, Vector r)
	{
		return Vector(l.X - r.X, l.Y - r.Y, l.Z - r.Z);
	}
	friend double operator *(Vector l, Vector r)
	{
		return(l.X * r.X + l.Y * r.Y * l.Z * r.Z);
	}
	void print()
	{
		cout << "X=" << X << "Y=" << Y << "Z=" << Z << endl;  

	}
	void compare(Vector one, Vector two)
	{
		float a = one.Getlength(), b = two.Getlength();
		if (one.Getlength() > two.Getlength())
			cout << a << " > " << b << endl;
		else if (one.Getlength() < two.Getlength())
			cout << a << " < " << b << endl;
		else
			cout << a << " = " << b << endl;
	}
};
	int main(int argc, char* argv[])
	{
		Vector v1 = Vector(1, 2, 3);
		Vector v2 = Vector(4, 5, 6);
		Vector v3 = v1+ v2;
		Vector v4 = v1 - v2;
		double m = v2 * v3;
		v3.print();
		v4.print();
		cout << "m=" << m;
		v3.compare(v3, v4);
		return 0;
	}