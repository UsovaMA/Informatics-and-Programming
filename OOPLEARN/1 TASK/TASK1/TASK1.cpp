#include <iostream>
#include <cmath>
#include <conio.h>
#include <cstdlib>
using std::cout;
using std::endl;
using std::pair;
class Note {
private:
	int b1{};
	int  b2{};
	int  b3{};
public:
	Note(int x, int y, int z) : b1(x), b2(y), b3(z)
	{
		cout << "constructor 1 vizvan" << endl;
	};
	Note(const Note& info) {
		cout << " construct copir vizvan" << endl;
		b1 = info.b1;
		b2 = info.b2;
		b3 = info.b3;

	}
	auto getPair() { return  (b1, b2, b3); }
};
int main()
{
	Note f1(10, 20, 30);
	cout << " " << endl;
	Note f2(20, 30, 40);
	cout << " " << endl;
	Note f3 = f1;
	cout << " " << endl;
cout << f1.getPair().first << f1.getPair().second << f1.getPair().Trird << endl;
cout << f2.getPair().first << f2.getPair().second << f2.getPair().Trird << endl;
cout << f3.getPair().first << f3.getPair().second << f3.getPair().Trird << endl;
	return EXIT_SUCCESS;
};

