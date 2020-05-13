#pragma once
#include "Weapon.h"
#include "Armor.h"
class Inventory
{
private:
	int cap;
	int nrOfItems;
	Item **itemArray;
	//FUNC
	void expand();
	void initialization(int from = 0);
public:
	Inventory();
	Inventory(const Inventory& obj);
	~Inventory();
	//METHODS
	Item& operator [](const int index);
	void addItem(const Item &item);
	void removeItem(const int index);
	Item* getItem(int index);
	void showInventory()const;
	inline int getNrOfItems() const { return this->nrOfItems; }
};

