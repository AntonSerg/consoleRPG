#pragma once
#include "Item.h"
class Armor :
	public Item
{
private:
	//DEFENCE
	int defence;
	//TYPE(HELM,CHEST....
	int type;
	//ATTRIBUTES
	int strenght;
	int dexterity;
	int intelligence;
	int luck;

public:
	Armor(int id = 0,int type = 0, int defence = 0,int strenght = 0,int dexterity = 0, int intelligence = 0, int luck = 0, std::string name = "NONE", int level = 0, int buyPrice = 0, int sellPrice = 0, bool questItem = 0, int rarity = 0);
	~Armor();

	Armor* clone() const;
	std::string getType() const;
	//GETINF
	std::string getString()const;
	inline int getArmorType()const { return this->type; }
	inline int getDefence()const { return this->defence; }
	inline int getStrenght()const { return this->strenght; }
	inline int getDexterity()const { return this->dexterity; }
	inline int getIntelligence()const { return this->intelligence; }
	inline int getLuck()const { return this->luck; }
};

enum armorType {helmet = 1,chest,arms,legs,boots};

