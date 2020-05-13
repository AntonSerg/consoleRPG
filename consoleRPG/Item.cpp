#include "Item.h"



Item::Item(int id,std::string name, int level, int buyPrice, int sellPrice, bool questItem, int rarity)
{
	this->id = id;
	this->name = name;
	this->level = level;
	this->buyPrice = buyPrice;
	this->sellPrice = sellPrice;
	this->questItem = questItem;
	this->rarity = rarity;
}


Item::~Item()
{
}
