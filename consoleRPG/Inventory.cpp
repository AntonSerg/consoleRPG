#include "Inventory.h"



Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItems = 0;
	this->itemArray = new Item* [cap];
	this->initialization();
}

Inventory::Inventory(const Inventory& obj)
{
	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArray = new Item*[cap];
	for (size_t i = 0; i < nrOfItems; i++)
	{
		this->itemArray[i] = obj.itemArray[i]->clone();
	}
	initialization(this->nrOfItems);
}

Item& Inventory::operator [] (const int index)
{
	if (index < 0 || index >= nrOfItems)
		throw("BAD INDEX");
	return *this->itemArray[index];
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArray[i];
	}
	delete[] itemArray;
}

void Inventory::expand()
{
	this->cap *= 2;
	Item **tempArray = new Item*[this->cap];
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		tempArray[i] = this->itemArray[i];
	}
	delete[] itemArray;

	this->itemArray = tempArray;
	this->initialization(this->nrOfItems);
}

void Inventory::initialization(int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArray[i] = nullptr;
	}
}
void Inventory::addItem(const Item &item)
{
	if (this->nrOfItems >= this->cap)
	{
		this->expand();
	}
	this->itemArray[this->nrOfItems++] = item.clone();
}
void Inventory::removeItem(const int index)
{
	if (index < 0 || index >(this->nrOfItems - 1))
	{
		std::cout << "\nIndex is wrong!\n";
	}
	else
	{
		delete this->itemArray[index];
		itemArray[index] = nullptr;
		for (size_t i = index; i < this->nrOfItems; i++)
		{
			this->itemArray[i] = this->itemArray[i + 1];
		}
		this->nrOfItems--;
		delete this->itemArray[this->nrOfItems];
	}
}

void Inventory::showInventory()const
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		std::cout << i+1 << ":" << "Name:" << itemArray[i]->getItemName() << " " << (itemArray[i]->getString()) << "\n";
	}

}

Item* Inventory::getItem(int index)
{
	return itemArray[index];
}
