#pragma once

#include "Race.h"
class Item
{
private:
	int id;
	std::string name;
	int level;
	int buyPrice;
	int sellPrice;
	bool questItem;
	int rarity;
public:
	Item(int id = 0,std::string name = "NONE", int level = 0, int buyPrice = 0, int sellPrice = 0, bool questItem = 0, int rarity = 0);
	~Item();
	//GET
	inline std::string getItemName() const { return this->name; }
	inline int getItemLevel() const { return this->level; }
	inline int getBuyPrice() const { return this->buyPrice; }
	inline int getSellPrice() const { return this->sellPrice; }
	inline bool getQuestItem() const { return this->questItem; }
	inline int getRarity() const { return this->rarity; }
	inline int getId() const { return this->id; }
	
	//PURE METHOD{
	virtual Item* clone() const = 0;
	//GET STRING
	virtual inline std::string getString() const { return "ERROR"; }
	//GET TYPE
	virtual inline std::string getType() const { return "item"; }
	//}
};

enum itemRarity {common = 1,uncommon,rare,magical,epic,immortal};

