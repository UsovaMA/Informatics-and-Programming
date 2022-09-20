#include <iostream>
using namespace std;

class Tiles {
protected:
public:
  char brand[20];
    int size_h;
    int  size_w;
  double price;
  void getdata(); // метод класса 
};
int main()
{
    setlocale(LC_ALL, "rusian");
    Tiles Tshirt;
    strcpy_s(Tshirt.brand, "Tshirt");
    Tshirt.size_h = 5;
    Tshirt.size_w = 10;
    Tshirt.price = 100;
    Tiles Dress;
    strcpy_s(Dress.brand, "Dress");
    Dress.size_h = 7;
    Dress.size_w = 9;
    Dress.price = 115;
    Tshirt.getdata();
    Dress.getdata();
    return 0;
}

void  Tiles::getdata()
{
    cout << brand << " lONG: " << size_h  << " WILD: " << size_w <<  " $" << price << endl;
};

   

