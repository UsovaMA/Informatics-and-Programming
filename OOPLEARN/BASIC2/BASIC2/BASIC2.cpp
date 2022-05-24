//#include <iostream>
//using namespace std;
//
//class human {
//
//public:
//	string name;
//	int age;
//	float weight;
//
//	human() { name = " "; }
//	human(string name) { this->name = name; } // делигируем присвоение имени 
//	human(string name, int age) : human(name) { this->age = age; } // делигирующий конструктов  
//	human(string name, int age, float weight) : human(name,age) { this->weight = weight; }
//};
//int main()
//{
//setlocale(LC_ALL, "rus");
//
//human h(" alex ",25,98);
//cout << "imya: " << h.name << "\nvozrast: " << h.age << "\nves: " << h.weight << endl;
//};
//
//
#include <iostream>
using namespace std;

class basic {
public:
	basic(const basic& other) //конструктор копир начало...ссылаемся на озер 
	{
		cout << "constructor viavan" << this << endl;
	
	this->x = other.x;
	this->y = other.y; //конструктор копир конец
}
	basic(int px, int py): x(px), y(py){//инициализация с присвоением сразу 
		cout << "const s 2 element" << this << endl;
		
	}
	
	~basic() {
		cout << "destructor vizvan" << this << endl; 
	}


private:
	int x, y;

public:
	void setcoord(int x, int y) { this->x = x;	this->y = y; }

};
	int main()
	{
		setlocale(LC_ALL,"rus");
		basic yays(2,9);
	};