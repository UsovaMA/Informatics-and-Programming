#include <iostream>
using namespace std;

class Computer
{
   
    int model;
    int shirina;
    int glybina;
    int visota;
public:
    Computer()
    {
        model = 0;
        shirina = 0;
        glybina = 0;
        visota = 0;
    }

    Computer( int model, int shirina, int glybina, int visota)
    {
       
      
        this->model = model;
        this->shirina = shirina;
        this->glybina = glybina;
        this->visota = visota;
    }

    Computer(const Computer& orig)
    {
      
      
        this->model = orig.model;
        this->shirina = orig.shirina;
        this->glybina = orig.glybina;
        this->visota = orig.visota;
    }

    ~Computer()
    {
       
    }

    void vivod()
    {
        cout <<   ". " << model << ". " << shirina << ". " << glybina << ". " << visota << endl;
    }
};

int main()
{
    Computer p1(349, 245, 24, 5);
    p1.vivod();

    system("pause");
    return 0;
}