#include <iostream>
using namespace std;

class Point {
public:
	int  x, y;
};
class Graph {
public:
	Graph () { cout << "Constructor  Graph:" << this << endl;}
	const char* getName() { return name.c_str(); } // получить имя примитива 
	void setName(string name) { this->name = name; }// задать имя примитива 
protected:
	string name;
};
class Styles : public virtual  Graph { // класс Styles  наследуется от Graph
public:
	Styles() {cout << "Construcrot Styles\n"; width = 1; color = 0; }
	Styles(short width, short color) {cout << "Constructor Styles 1\n"; this->width = width;}

	 const char* getobject() { return "Styles"; }
protected:
	short width;
	short color;
};
class Pos : public  virtual Graph { // класс  pos наследуется от graph 
public:
	Pos() { cout << "Constuctor Pos\n"; sp.x = sp.y = ep.x = ep.y = 0; }
	Pos(int x1, int y1, int x2, int y2) { cout << "Constructor Pos4\n"; sp.x = x1; sp.y = y1; }
	void setCoords(int x1, int y1, int x2, int y2) { sp.x = x1; sp.y = y1; ep.x = x2; ep.y = y2; } //с помощью сеттера задаем координаты графич примитива
	const char* getobject() { return "Pos"; }
protected:
	Point sp, ep;
};
class Line : public Styles, public Pos
{
public:
	Line() { cout << "Constructor Line\n"; }
	Line(short width, short color) : Pos(), Styles(width, color) { cout << "Constructor Line1\n"; } //наследование класса пос и стайлс
	void Draw() 
	{
		cout << "Draw line\n" << endl;
		cout << "Styles:\n" << width << "DA DA" << color << " Colot takoi" << endl;
		cout << "Coords:" << sp.x << "ONO" << sp.y << "AGA" << ep.x << "Tyda Ego" << ep.y << endl;
	}
};
//ето я создал два базовых класса styles и pos и  дочерний  Line
int main()
{
	setlocale(LC_ALL, "rus");
	Line line(1, 40);
	line.setCoords(1, 4, 8, 20);
	line.Draw();
	cout << ((Pos)line).getobject() << endl;
	Styles* ps = &line;
	cout << ps->getobject() << endl;
	cout << line.getName() << endl;
};
