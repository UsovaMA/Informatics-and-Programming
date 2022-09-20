#include <iostream>
using namespace std;

class Character {
 
   
public:
    static size_t count;
    int health;
    int attack;
    int armor;
    virtual void Attack(Character opponent)
    {
        cout << "Персонаж атакует" << endl;
    }
    virtual void WereAttacked(int damage) {
        cout << "персонаж атакован" << endl;
    }

};
class Shaman : public Character {
    int  mana;
    int totemsHealth;
    int totemsAttack;
public:
    virtual void Attack(Character opponent)
    {
        cout << "Шаман атакует тотемом" << endl;
        totemsHealth = 10;
        totemsAttack = 10;
        armor = 15;
        mana--;
        opponent.WereAttacked(totemsAttack);
    }
    virtual void WereAttacked(int damage)
    {
        cout << "персонаж был атакован" << endl;
        if (totemsHealth >= damage) {
            totemsHealth -= damage;
        }
        else {
            if (armor == 0) 
            {
                health -= (damage - totemsHealth);
                totemsHealth = 0;
            }
            else {
                if (armor >= damage - totemsHealth) {
                    armor -= (damage - totemsHealth);
                    totemsHealth = 0;
                }
                else {
                    health -= (damage - armor - totemsHealth);
                    armor = 0;
                    totemsHealth = 0;
                }
            }
        }
    }
};
class Warrior : public Character {
    int weaponDyrability;
    int weaponAttack;
    int shield;
public:
    virtual void Attack() {
        cout << "Воин атакует" << endl;
    }
};



int main()
{
    Shaman till;
    cout << ""  << till.armor << endl;
}

