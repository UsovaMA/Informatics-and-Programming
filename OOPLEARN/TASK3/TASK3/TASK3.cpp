#include <iostream>
using namespace std;
class Children {
private:
	char name[20];
	char famil[20];
	double age;
public:
	void showdata();
	void getdata();
};
int main()
{
	setlocale(LC_ALL, "rus");
	Children Child1;
	Children Child2;
	Child1.showdata();
	Child1.getdata();
	return 0;
}
//определеяем методы класса 
void Children::showdata()
{
	cout << "Name:";
	cin.getline(name, 20);
	cout << "Famil:";
	cin.getline(famil, 20);
	cout << " Age: ";
	cin >> age;
	cin.get();
}
void Children::getdata()
{
	cout << name << "  " << famil << "  " << age << " age;\n ";
}