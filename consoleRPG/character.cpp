#include "character.h"



Character::Character()
{
	//NAME
	this->name = {};
	//ABOUT CHARACTER
	this->sex = 0;
	this->position = 0;
	//LEVELING
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	//HP/MP/DMG/DEF
	this->hp = 0;
	this->hpMax = 0;
	this->mp = 0;
	this->mpMax = 0;
	this->dmg = 0;
	this->dmgMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->agility = 0;
	//STATS
	this->mainAttribute = 0;
	this->strenght = 0;
	this->dexterity = 0;
	this->intelligence = 0;
	this->luck = 0;
	//POINTS
	this->statPoints = 0;
	this->skillPoints = 0;
	this->gold = 0;
	//STAF
	this->characterWeapon = new Weapon();
	this->characterHead = new Armor();
	this->characterChest = new Armor();
	this->characterArms = new Armor();
	this->characterLegs = new Armor();
	this->characterBoots = new Armor();
	this->indexEquipWeapon = -1;
	this->indexEquipArms = -1;
	this->indexEquipBoots = -1;
	this->indexEquipHead = -1;
	this->indexEquipChest = -1;
	this->indexEquipLegs = -1;
}


Character::~Character()
{
}


//Character intialization/UPDATE
void Character::characterInitialization(std::string& name)
{
	this->name = name;
	characterRace.raceInitialization(); //Choosing race;
	std::cout << "\nYour Race:" << characterRace.printRace() << "\n";
	std::cout << "Sex:\n1:Male\n2:Female\n";
	std::cout << "Enter your characters sex:";
	std::cin >> this->sex;
	this->level = 1;
	this->exp = 0;
	this->expNext = 100;
	setAttribute();
	this->luck = 10;
	this->hpMax = 50 * this->strenght + 250 * getLevel();
	this->hp = this->hpMax;
	this->mpMax = 30 * this->intelligence + 70 * getLevel();
	this->mp = mpMax;
	this->dmg = this->mainAttribute * 5;
	this->dmgMax = this->dmg * 1.4;
	this->defence = 2 * this->strenght + this->dexterity / 2;
	this->accuracy = this->strenght + this->dexterity + this->luck;
	this->agility = 2 * this->dexterity + this->strenght / 2;
	
	this->statPoints = 5;
	this->skillPoints = 0;
	this->gold = 100;

	this->quests.questListInitializate(this->characterRace.getCurrentRace());
	system("CLS");

}

void Character::whichMainAttribute()
{
	if (characterRace.getCurrentRace() == 1)
	{
		this->mainAttribute = this->strenght + this->equipmentStrenght();
	}
	else if (characterRace.getCurrentRace() == 2)
	{
		this->mainAttribute = this->dexterity + this->equipmentDexterity();
	}
	else if (characterRace.getCurrentRace() == 3)
	{
		this->mainAttribute = this->intelligence + this->equipmentIntelligence();
	}
	else if (characterRace.getCurrentRace() == 4)
	{
		this->mainAttribute = this->strenght + this->equipmentStrenght();
	}
	else if (characterRace.getCurrentRace() == 5)
	{
		this->mainAttribute = this->dexterity + this->equipmentDexterity();
	}
}

void Character::setAttribute()
{
	if (characterRace.getCurrentRace() == 1)
	{
		this->strenght = 10;
		this->dexterity = 8;
		this->intelligence = 7;
		this->mainAttribute = this->strenght;
		this->position = 1;
	}
	else if (characterRace.getCurrentRace() == 2)
	{
		this->strenght = 7;
		this->dexterity = 10;
		this->intelligence = 8;
		this->mainAttribute = this->dexterity;
		this->position = 2;
	}
	else if (characterRace.getCurrentRace() == 3)
	{
		this->strenght = 7;
		this->dexterity = 8;
		this->intelligence = 10;
		this->mainAttribute = this->intelligence;
		this->position = 3;
	}
	else if (characterRace.getCurrentRace() == 4)
	{
		this->strenght = 14;
		this->dexterity = 5;
		this->intelligence = 6;
		this->mainAttribute = this->strenght;
		this->position = 4;
	}
	else if (characterRace.getCurrentRace() == 5)
	{
		this->strenght = 9;
		this->dexterity = 9;
		this->intelligence = 7;
		this->mainAttribute = this->dexterity;
		this->position = 5;
	}
}

void Character::updateStats()
{
	int hpMaxTemp = 0;
	hpMaxTemp = this->hpMax;
	whichMainAttribute();
	this->hpMax = 50 * (this->strenght + this->equipmentStrenght()) + 250 * this->getLevel();
	hpMaxTemp -= this->hpMax;
	this->hp += -hpMaxTemp; //+HP_MAX_NEW - HP_MAX_OLD
	this->mpMax = 30 * (this->intelligence + this->equipmentIntelligence()) + 70 * this->getLevel();
	this->dmg = this->mainAttribute * 5 + this->characterWeapon->getDamage();
	this->dmgMax = this->dmg * 1.4;
	this->defence = 2 * (this->strenght + this->equipmentStrenght()) + (this->dexterity + this->equipmentDexterity()) / 2;
	this->accuracy = (this->strenght + this->equipmentStrenght()) + (this->dexterity + this->characterWeapon->getDexterity()) + (this->luck + this->equipmentLuck());
	this->agility = 2 * (this->dexterity + this->equipmentDexterity()) + (this->strenght + this->equipmentStrenght()) / 2;
}


//SAVE/LOAD
std::string Character::getAsString()
{
	std::string str = this->name + " " +
		std::to_string(this->characterRace.getCurrentRace()) + " " +
		std::to_string(this->sex) + " " +
		std::to_string(this->position) + " " +
		std::to_string(this->level) + " " +
		std::to_string(this->exp) + " " +
		std::to_string(this->expNext) + " " +
		std::to_string((this->hp - 50 * equipmentStrenght())) + " " +
		std::to_string(this->mp) + " " +
		std::to_string(this->strenght) + " " +
		std::to_string(this->dexterity) + " " +
		std::to_string(this->intelligence) + " " +
		std::to_string(this->luck) + " " +
		std::to_string(this->statPoints) + " " +
		std::to_string(this->skillPoints) + " " +
		std::to_string(this->gold) + " " +
		std::to_string(this->characterInv.getNrOfItems()) + " ";
	for (size_t i = 0; i < characterInv.getNrOfItems(); i++)
	{
		str += std::to_string(characterInv[i].getId()) + " ";
	}
		 str += std::to_string(this->indexEquipWeapon) + " ";
		 str += std::to_string(this->indexEquipHead) + " ";
		 str += std::to_string(this->indexEquipChest) + " ";
		 str += std::to_string(this->indexEquipArms) + " ";
		 str += std::to_string(this->indexEquipLegs) + " ";
		 str += std::to_string(this->indexEquipBoots);
	return str;
}


void Character::characterSave(std::ofstream& fout)
{
	fout << this->getAsString() << "\n";
}

void Character::characterLoad(std::ifstream& fin)
{
	this->characterWeapon = new Weapon();
	this->characterHead = new Armor();
	this->characterChest = new Armor();
	this->characterArms = new Armor();
	this->characterLegs = new Armor();
	this->characterBoots = new Armor();
	fin >> this->name;
	fin >> characterRace.currentRace;
	fin >> this->sex;
	fin >> this->position;
	fin >> this->level;
	fin >> this->exp;
	fin >> this->expNext;
	fin >> this->hp;
	fin >> this->mp;
	fin >> this->strenght;
	fin >> this->dexterity;
	fin >> this->intelligence;
	fin >> this->luck;
	fin >> this->statPoints;
	fin >> this->skillPoints;
	fin >> this->gold;
	int nrOfItems = 0;
	int id = 0;
	fin >> nrOfItems;
	for (size_t i = 0; i < nrOfItems; i++)
	{
		fin >> id;
		this->loadItem(id);
	}
	fin >> this->indexEquipWeapon;
	fin >> this->indexEquipHead;
	fin >> this->indexEquipChest;
	fin >> this->indexEquipArms;
	fin >> this->indexEquipLegs;
	fin >> this->indexEquipBoots;
	this->loadStats();
	
	
}

void Character::loadStats()
{
	whichMainAttribute();
	this->hpMax = 50 * this->strenght + 250 * this->getLevel();
	this->mpMax = 30 * this->intelligence + 70 * this->getLevel();
	this->dmg = this->mainAttribute * 5;
	this->dmgMax = this->dmg * 1.4;
	this->defence = 2 * this->strenght + this->dexterity / 2;
	this->accuracy = this->strenght + this->dexterity + this->luck;
	this->agility = 2 * this->dexterity + this->strenght / 2;
}


//INCREASE
void Character::levelUp()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->statPoints++;
		this->skillPoints++;
		this->expNext = this->expNext * 2;
		this->updateStats();
	}
	else
	{
		std::cout << "\nYou can't up your level now\n";
	}
}

void Character::increaseStats()
{
	if (this->getStatP() > 0)
	{
		int choice;
		std::cout << "Which stat you want to upgrade?\n"
			<< "1:Strenght \n"
			<< "2:Dexterity \n"
			<< "3:Intelligence \n"
			<< "4:Luck \n"
			<< "Your choice:";
		std::cin >> choice;
		while (std::cin.fail() || choice < 1 || choice > 4)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\nWrong choice!\n";
			std::cout << "Your choice:";
			std::cin >> choice;

		}
		switch (choice)
		{
		case 1:
			this->strenght++;
			this->statPoints--;
			this->updateStats();
			break;
		case 2:
			this->dexterity++;
			this->statPoints--;
			this->updateStats();
			break;
		case 3:
			this->intelligence++;
			this->statPoints--;
			this->updateStats();
			break;
		case 4:
			this->luck++;
			this->statPoints--;
			this->updateStats();
			break;
		default:
			std::cout << "Wrong choice!";
			break;
		}
	}
	else
	{
		std::cout << "You have " << this->statPoints << "!\n";
	}
}

void Character::increaseExp(int x)
{
	this->exp += x;
	if (this->exp < 0)
	{
		this->exp = 0;
	}
}

void Character::increaseGold(int x)
{
	this->gold += x;
	if (this->gold < 0)
	{
		this->gold = 0;
	}
}

void Character::takeDamage(int x)
{
	this->hp += x;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Character::restoreHp()
{
	this->hp = this->hpMax;
}


//INVENOTRY
int Character::inventorySize()
{
	return characterInv.getNrOfItems();
}

void Character::showInventory()
{
	for (size_t i = 0; i < this->characterInv.getNrOfItems(); i++)
	{
		std::cout << i + 1 << ":" << "Name:" << characterInv[i].getItemName() << " " << (characterInv[i].getString()) << "\n";
	}

}

void Character::showWeapons()
{
	for (size_t i = 0; i < this->characterInv.getNrOfItems(); i++)
	{
		if (characterInv[i].getType() == "weapon")
		{
			std::cout << i + 1 << ":" << "Name:" << characterInv[i].getItemName() << " " << (characterInv[i].getString()) << "\n";
		}
	}

}

void Character::showArmors()
{
	for (size_t i = 0; i < this->characterInv.getNrOfItems(); i++)
	{
		if (characterInv[i].getType() == "armor")
		{
			std::cout << i + 1 << ":" << "Name:" << characterInv[i].getItemName() << " " << (characterInv[i].getString()) << "\n";
		}
	}

}

void Character::loadItem(int id)
{
	std::string string;
	std::ifstream fin("items.txt");
	if (!fin.is_open())
	{
		std::cout << "\nCan't open file with save!\n";
	}
	else
	{
		while (!fin.eof())
		{
			fin >> string;
			std::cout << string << "\n";
			if (id >= 1000 && id < 1500)
			{
				if (string == std::to_string(id))
				{
					int damage;
					fin >> damage;
					int strenght;
					fin >> strenght;
					int dexterity;
					fin >> dexterity;
					int intelligence;
					fin >> intelligence;
					int luck;
					fin >> luck;
					std::string name;
					int level;
					int buyPrice;
					int sellPrice;
					int questItem;
					int rarity;
					fin >> name;
					fin >> level;
					fin >> buyPrice;
					fin >> sellPrice;
					fin >> questItem;
					fin >> rarity;
					inventoryAddItem(Weapon(id, damage, strenght, dexterity, intelligence, luck, name, level, buyPrice, sellPrice, questItem, rarity));
				}
				getline(fin, string);
			}
			else
			{
				if (string == std::to_string(id))
				{
					int type;
					fin >> type;
					int defence;
					fin >> defence;
					int strenght;
					fin >> strenght;
					int dexterity;
					fin >> dexterity;
					int intelligence;
					fin >> intelligence;
					int luck;
					fin >> luck;
					std::string name;
					int level;
					int buyPrice;
					int sellPrice;
					int questItem;
					int rarity;
					fin >> name;
					fin >> level;
					fin >> buyPrice;
					fin >> sellPrice;
					fin >> questItem;
					fin >> rarity;
					inventoryAddItem(Armor(id, type, defence, strenght, dexterity, intelligence, luck, name, level, buyPrice, sellPrice, questItem, rarity));
				}
				getline(fin, string);

			}
		}
		fin.close();


	}
}

void Character::inventoryAddItem(const Item& item)
{
	characterInv.addItem(item);
}

void Character::inventoryRemoveItem(int i)
{
	if (this->characterWeapon == &characterInv[i-1]
		|| this->characterHead == &characterInv[i-1]
		|| this->characterChest == &characterInv[i-1]
		|| this->characterArms == &characterInv[i-1]
		|| this->characterLegs == &characterInv[i-1]
		|| this->characterBoots == &characterInv[i-1]
		|| characterInv[i-1].getQuestItem())
	{
		std::cout << "\nYou can't remove this item \n";
		system("PAUSE");
	}
	else{
		characterInv.removeItem(i - 1);
	}
}

void Character::equipEquipment(int i)
{
	i = i - 1;
	if (characterInv[i].getType() == "weapon")
	{
		this->characterWeapon = dynamic_cast<Weapon*>(characterInv.getItem(i));
		this->indexEquipWeapon = i;
		this->updateStats();
	}
	else if (characterInv[i].getType() == "armor")
	{
		Armor* a;
		a = dynamic_cast<Armor*>(characterInv.getItem(i));
		switch (a->getArmorType())
		{
		case armorType::helmet:
			this->characterHead = dynamic_cast<Armor*>(characterInv.getItem(i));
			this->indexEquipHead = i;
			this->updateStats();
			break;
		case armorType::chest:
			this->characterChest = dynamic_cast<Armor*>(characterInv.getItem(i));
			this->indexEquipChest = i;
			this->updateStats();
			break;
		case armorType::arms:
			this->characterArms = dynamic_cast<Armor*>(characterInv.getItem(i));
			this->indexEquipArms = i;
			this->updateStats();
			break;
		case armorType::legs:
			this->characterLegs = dynamic_cast<Armor*>(characterInv.getItem(i));
			this->indexEquipLegs = i;
			this->updateStats();
			break;
		case armorType::boots:
			this->characterBoots = dynamic_cast<Armor*>(characterInv.getItem(i));
			this->indexEquipBoots = i;
			this->updateStats();
			break;
		default:
			std::cout << "\nERROR!Wrong armor type!\n";
			break;
		}
	}
	else
	{
		std::cout << "\n You can't equip this item!\n";
	}
}

int Character::equipmentStrenght()
{
	int str;
	str = this->characterWeapon->getStrenght() + this->characterArms->getStrenght()
		+ this->characterChest->getStrenght() + this->characterBoots->getStrenght()
		+ this->characterLegs->getStrenght() + this->characterHead->getStrenght();
	return str;
}

int Character::equipmentDexterity()
{
	int dex;
	dex = this->characterWeapon->getDexterity() + this->characterArms->getDexterity()
		+ this->characterChest->getDexterity() + this->characterBoots->getDexterity()
		+ this->characterLegs->getDexterity() + this->characterHead->getDexterity();
	return dex;
}

int Character::equipmentIntelligence()
{
	int intelligence;
	intelligence = this->characterWeapon->getIntelligence() + this->characterArms->getIntelligence()
		+ this->characterChest->getIntelligence() + this->characterBoots->getIntelligence()
		+ this->characterLegs->getIntelligence() + this->characterHead->getIntelligence();
	return intelligence;
}

int Character::equipmentLuck()
{
	int luck;
	luck = this->characterWeapon->getLuck() + this->characterArms->getLuck()
		+ this->characterChest->getLuck() + this->characterBoots->getLuck()
		+ this->characterLegs->getLuck() + this->characterHead->getLuck();
	return luck;
}


//OTHER
void Character::showStats()
{

	std::cout << "Name:" << this->getName()
		<< "\nRace:" << this->getPrintRace()
		<< "\nPosition:" << this->getPositionString()
		<< "\nLevel:" << this->getLevel()
		<< "\nExp:" << this->getExp() << "/"
		<< this->getExpNext()
		<< "\nHP:" << this->getHp() << "/" << this->getHpMax()
		<< "\nMP:" << this->getMp() << "/" << this->getMpMax()
		<< "\nDMG:" << this->getDmg() << " - " << this->getDmgMax()
		<< "\nDefence:" << this->getDefence()
		<< "\nAccuracy:" << this->getAccuracy()
		<< "\nAgility:" << this->getAgility()
		<< "\nStrenght:" << this->getStr() << " + " << this->equipmentStrenght()
		<< "\nDexterity:" << this->getDex() << " + " << this->equipmentDexterity()
		<< "\nIntelligence:" << this->getInt() << " + " << this->equipmentIntelligence()
		<< "\nLuck:" << this->getLuck() << " + " << this->equipmentLuck()
		<< "\nMainAttribute:" << this->getMainAttribute() << "\n\n"
		<< "\nStat points:" << this->getStatP()
		<< "\nSkill points:" << this->getSkillP()
		<< "\nGold:" << this->getGold() << "\n\n"
		<< "Equipment:"
		//WEAPON
		<< "\nWeapon:" << characterWeapon->getItemName()
		<< " Level:" << characterWeapon->getItemLevel()
		<< " Damage:" << characterWeapon->getDamage()
		<< " Strenght:" << characterWeapon->getStrenght()
		<< " Dexterity:" << characterWeapon->getDexterity()
		<< " Intelligence:" << characterWeapon->getIntelligence()
		<< " Luck:" << characterWeapon->getLuck() << "\n"
		//ARMOR
		<< "\nHelmet:" << characterHead->getItemName() << " Level:" << characterHead->getItemLevel() << " Defence:" << characterHead->getDefence() << " Strenght:" << characterHead->getStrenght() << " Dexterity:" << characterHead->getDexterity() << " Intelligence:" << characterHead->getIntelligence() << " Luck:" << characterHead->getLuck() << "\n"
		<< "Chest:" << characterChest->getItemName() << " Level:" << characterChest->getItemLevel() << " Defence:" << characterChest->getDefence() << " Strenght:" << characterChest->getStrenght() << " Dexterity:" << characterChest->getDexterity() << " Intelligence:" << characterChest->getIntelligence() << " Luck:" << characterChest->getLuck() << "\n"
		<< "Arms:" << characterArms->getItemName() << " Level:" << characterArms->getItemLevel() << " Defence:" << characterArms->getDefence() << " Strenght:" << characterArms->getStrenght() << " Dexterity:" << characterArms->getDexterity() << " Intelligence:" << characterArms->getIntelligence() << " Luck:" << characterArms->getLuck() << "\n"
		<< "Legs:" << characterLegs->getItemName() << " Level:" << characterLegs->getItemLevel() << " Defence:" << characterLegs->getDefence() << " Strenght:" << characterLegs->getStrenght() << " Dexterity:" << characterLegs->getDexterity() << " Intelligence:" << characterLegs->getIntelligence() << " Luck:" << characterLegs->getLuck() << "\n"
		<< "Boots:" << characterBoots->getItemName() << " Level:" << characterBoots->getItemLevel() << " Defence:" << characterBoots->getDefence() << " Strenght:" << characterBoots->getStrenght() << " Dexterity:" << characterBoots->getDexterity() << " Intelligence:" << characterBoots->getIntelligence() << " Luck:" << characterBoots->getLuck() << "\n";
	system("PAUSE");
	system("CLS");



}

void Character::dieCharacter()
{
	int x;
	x = (this->expNext / 100) * 4;
	this->increaseExp(-x);
	this->hp = hpMax / 3;
	system("CLS");
	std::cout << "===You die!===\n\n";
}





std::string Character::getPositionString()
{
	std::string currentPosition = "";
	if (this->position == 0)
	{
		currentPosition = "NONE";
		return currentPosition;
	}
	else if (this->position == 1)
	{
		currentPosition = "Human town";
		return currentPosition;
	}
	else if (this->position == 2)
	{
		currentPosition = "Elf town";
		return currentPosition;
	}
	else if (this->position == 3)
	{
		currentPosition = "Dark elf town";
		return currentPosition;
	}
	else if (this->position == 4)
	{
		currentPosition = "Dwarven town";
		return currentPosition;
	}
	else if (this->position == 5)
	{
		currentPosition = "Niggers town";
		return currentPosition;
	}
	else if (this->position == 6)
	{
		currentPosition = "Capital town";
		return currentPosition;
	}
	else
	{
		throw "WARNING!FRONG POSITION";
	}
}
