#include "Armor.h"


Armor::Armor(int id,int type, int defence,int strenght,int dexterity,int intelligence,int luck, std::string name , int level, int buyPrice, int sellPrice, bool questItem, int rarity)
	:Item(id,name,level,buyPrice,sellPrice,questItem,rarity)
{
	this->defence = defence;
	this->type = type;
	this->strenght = strenght;
	this->dexterity = dexterity;
	this->intelligence = intelligence;
	this->luck = luck;
}
Armor::~Armor()
{
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}
std::string Armor::getType() const
{
	return "armor";
}
std::string Armor::getString()const
{
	std::string string;
	string = "Defence:" + std::to_string(this->defence) + " Type:" + std::to_string(this->type);
	return string;
}