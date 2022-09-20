#include <iostream>
using namespace std;
class Basic {
private:
	int x, y;

public:
	void setcoord(int pt_x, int pt_y) { //метод класса
		x = pt_x;
		y = pt_y;


	}
	int getX() { return x; }
	int getY() { return y; }
};


int main()
{
	setlocale(LC_ALL, "russian");
	Basic yays;
	yays.setcoord(2, 7);
	cout << " значение х: " <<  yays.getX()  <<  " значение y: " << yays.getY()   << endl;

};