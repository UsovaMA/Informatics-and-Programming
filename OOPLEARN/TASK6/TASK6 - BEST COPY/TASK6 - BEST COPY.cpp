#include <iostream>
using namespace std;
class Room {
private:
	double lenght;
	double hight;
	int things;
public:
	Room(double len, double hig, int thin) {
		lenght = len;
		hight = hig;
		things = thin;
	}
	Room(Room& obj) {
		lenght = obj.lenght;
		hight = obj.hight;
		things = obj.things;
	}
		double Area() {
			return lenght * hight;
			}
		double Vechi() {
			return things;
		}
};
int main()
{
	Room r1(12, 10, 6);
	cout << "Area of Room 1 :" << r1.Area() << "Vechi  v comnate:" << r1.Vechi() << endl;
	Room r2 = r1;
	cout << "Area of Room 2 :" << r2.Area() << "Vechi  v comnate:" << r2.Vechi() << endl;
	Room r3(15, 20, 7);
	cout << "Area of Room 3: " << r3.Area() << "   Vechi  v comnate: " << r3.Vechi() << endl;
	return 0;
}