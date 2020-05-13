#include "HumanT.h"
Weapon weapon;
Armor armor;
void HumanT::HumanTMenu(Character& character)
{
	std::cout << "===Welcome to Human town===\n";
	std::cout << "1:Travel\n";
	std::cout << "2:Journal\n";
	std::cout << "3:Quests\n";
	std::cout << "4:Inventory\n";
	std::cout << "5:Main menu\n";
	std::cout << "Your choice:";
	std::cin >> this->choice;
	while (std::cin.fail() || choice < 1 || choice > 5)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nWrong choice!\n";
		std::cout << "Your choice:";
		std::cin >> choice;

	}
	switch (this->choice)
	{
	case 1:
		fight.fightInitialization(character);
		system("CLS");
		while (fight.getFighting())
		{
			fight.fightStart(character);
		}
		break;
	case 2:
		/*character.inventoryAddItem(Weapon(777,111,10,10,10,10,"LOL_WEAPON"));
		character.inventoryAddItem(Armor(1, 1, 11,5,5,5,5, "LOL_HELMET"));
		character.inventoryAddItem(Armor(1, 2, 11, 5, 5, 5, 5, "LOL_CHEST"));
		character.inventoryAddItem(Armor(1, 3, 11, 5, 5, 5, 5, "LOL_ARMS"));
		character.inventoryAddItem(Armor(1, 4, 11, 5, 5, 5, 5, "LOL_LEGS"));
		character.inventoryAddItem(Armor(1, 5, 11, 5, 5, 5, 5, "LOL_BOOTS"));
		character.loadItem(1000);
		character.loadItem(1001);
		character.loadItem(1500);
		character.loadItem(1501);
		character.loadItem(1502);
		character.loadItem(1503);
		character.loadItem(1504);
		character.loadItem(1506);*/
		system("PAUSE");
		system("CLS");
		break;
	case 3:
		system("CLS");
		Quests::humanMain(character);

		break;
	case 4:
		system("CLS");
		inventory(character);
		break;
	case 5:
		this->isPlayingGame = false;
		system("CLS");
		break;
	default:
		std::cout << "Wrong option\n";
		break;
	}

}

void HumanT::inventory(Character& character)
{
	character.showInventory();
	std::cout << "\n\n";
	std::cout << "1:Weapons\n";
	std::cout << "2:Armors\n";
	std::cout << "3:Remove item\n";
	std::cout << "4:Equip\n";
	std::cout << "5:Return\n";
	std::cout << "Your choice:";
	std::cin >> this->choice;
	while (std::cin.fail() || choice < 1 || choice > 5)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nWrong choice!\n";
		std::cout << "Your choice:";
		std::cin >> choice;

	}
	switch (this->choice)
	{
	case 1:
		system("CLS");
		character.showWeapons();
		system("PAUSE");
		system("CLS");
		inventory(character);
		break;
	case 2:
		system("CLS");
		character.showArmors();
		system("CLS");
		system("PAUSE");
		inventory(character);
		break;
	case 3:
		std::cout << "\nItems nr to remove:";
		std::cin >> this->choice;
		while (std::cin.fail() || choice < 1 || choice > character.inventorySize())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\nWrong choice!\n";
			std::cout << "Your choice:";
			std::cin >> choice;

		}
		character.inventoryRemoveItem(this->choice);
		system("CLS");
		inventory(character);
		break;
	case 4:
		std::cout << "\nChoice weapon or armor to equip:";
		std::cin >> this->choice;
		while (std::cin.fail() || choice < 1 || choice > character.inventorySize())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\nItem doesn't exist!\n";
			std::cout << "Your choice:";
			std::cin >> choice;

		}
		character.equipEquipment(choice);
		system("CLS");
		inventory(character);
		break;
	case 5:
		system("CLS");
		break;
	default:
		break;
	}

}


HumanT::HumanT()
{
	choice = 0;
	isPlayingGame = true;
}


HumanT::~HumanT()
{
}
void HumanT::HumanTPlaying()
{
	isPlayingGame = true;
}
