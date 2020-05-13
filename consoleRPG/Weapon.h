#pragma once
#include "Item.h"
class Weapon :
	public Item
{
private:
	//DAMAGE
	int damage;
	//ATTRIBUTES
	int strenght;
	int dexterity;
	int intelligence;
	int luck;
public:
	Weapon(int id = 0, int damage = 0, int strenght = 0, int dexterity = 0, int intelligence = 0,int luck = 0 , std::string name = "NONE", int level = 0, int buyPrice = 0, int sellPrice = 0, bool questItem = 0, int rarity = 0);
	~Weapon();

	Weapon* clone() const;

	//GETINF
	std::string getType() const;
	std::string getString()const;
	inline int getDamage()const { return this->damage; }
	inline int getStrenght()const { return this->strenght; }
	inline int getDexterity()const { return this->dexterity; }
	inline int getIntelligence()const { return this->intelligence; }
	inline int getLuck()const { return this->luck; }
};

