#include <iostream>
using namespace std;
class Character {
private:
	int health;
	int armor;
	int attack;
	static size_t count;
	Backpack objects;
};
class Backpack {
	size_t count; // кол-во объектов 
	const size_t capacity; // вместимость 

};
class object {
	string name; //имя
	const size_t weight; // вес
};
class Potion : public object {
	string type;
	int pointBonus;
	int timeofAction;
};
class Weapon : public object {
	int  weaponDurability;
	int weaponAttacl;
	};
class Shaman : public Character {
	int mana;
	int totemHealth;
	int totemAttack;
};
class Warrior : public Character {
	int weaponDurabillity;
	int weaponAttack;
	int shieldpoints;
};

int main()
{

}