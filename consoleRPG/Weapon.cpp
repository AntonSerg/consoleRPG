#include "Weapon.h"

std::string Weapon::getString()const
{
	std::string string;
	string = "Damage:" + std::to_string(this->damage);
	return string;
}

std::string Weapon::getType() const
{
	return "weapon";
}

Weapon::Weapon(int id, int damage, int strenght, int dexterity, int intelligence, int luck, std::string name, int level, int buyPrice, int sellPrice, bool questItem, int rarity)
	: Item(id,name,level,buyPrice,sellPrice,questItem,rarity)
{
	this->damage = damage;
	this->strenght = strenght;
	this->dexterity = dexterity;
	this->intelligence = intelligence;
	this->luck = luck;
}

Weapon::~Weapon()
{
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}
