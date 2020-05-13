#include "game.h"


void Game::mainMenu()
{
	
	
	if (character[activeCharacter].getExpNext() == 0) { std::cout << "=====You need create your character!=====\n"; }
	else if (character[activeCharacter].getExp() >= character[activeCharacter].getExpNext()) { std::cout << "=======NEW LEVEL AVAILABLE=======\n"; }
	std::cout << "==MAIN MENU==" << "\n";
	std::cout << "1:Play" << "\n";
	std::cout << "2:Show stats" << "\n";
	std::cout << "3:Level up!" << "\n";
	std::cout << "4:Use stat points" << "\n";
	std::cout << "5:Select character" << "\n";
	std::cout << "6:Delete character" << "\n";
	std::cout << "7:Create new character" << "\n";
	std::cout << "8:Save characters" << "\n";
	std::cout << "9:Load characters" << "\n";
	std::cout << "10:Quit" << "\n\n";

	std::cout << "Your choice:";
		std::cin >> choice;
		while (std::cin.fail() || choice < 1 || choice > 12)
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
			humanT.HumanTPlaying();
			if (character[activeCharacter].getExpNext() == 0)
			{
				system("CLS");
				std::cout << "\nYou need to create your character\n";
			}
			else if (character[activeCharacter].getPositionInt() == 1){
				system("CLS");
				while (humanT.getPlayingGame())
				{		
					humanT.HumanTMenu(character[activeCharacter]);
				}
				
			}
			break;
		case 2:
			system("CLS");
			character[activeCharacter].showStats();
			break;
		case 3:
			system("CLS");
			character[activeCharacter].levelUp();
			break;
		case 4:
			system("CLS");
			character[activeCharacter].increaseStats();
			break;
		case 5:
			system("CLS");
			selectCharacter();
			system("CLS");
			break;
		case 6:
			if (character.size() > 1)
			{
				system("CLS");
				deleteCharacter();
			}
			else
			{
				system("CLS");
				std::cout << "\nYou can't delete character!\n";
			}
			break;
		case 7:
			system("CLS");
			this->createCharacter();
			system("CLS");
			break;
		case 8:
			if (character[activeCharacter].getExpNext() > 0)
			{
				system("CLS");
				std::cout << "If you save your characters, your past save will be deleted\nAre your accepter it?\n1:Yes\n2:No\n";
				std::cin >> this->choice;
				if (this->choice == 1)
				{
					this->saveCharacter();
				}
				system("CLS");
			}
			else
			{
				system("CLS");
				std::cout << "At first you need create character!\n";
			}
			break;
		case 9:
			this->loadCharacter();
			system("CLS");
			break;
		case 10:
			isPlaying = false;
			break;
		case 11:
			int x;
			std::cout << "Exp:";
			std::cin >> x;
			character[activeCharacter].increaseExp(x);
			system("CLS");
			break;
		case 12:
			
			character[activeCharacter].restoreHp();
			system("CLS");
			//std::cout << "\n" << character[activeCharacter].quests.getHumanMainProgress() << " " << character[activeCharacter].quests.getHumanMainComplete() << "\n";
			break;
		default:
			system("CLS");
			std::cout << "No options for your choice \n\n";
			break;
		}
	}

void Game::createCharacter()
{
	std::string name = "";
	std::cout << "Enter name of your character:";
	std::cin >> name;
	
	if (character[0].getLuck() < 10) {
		character[0].characterInitialization(name);
	}
	else
	{
		chekingName(name);
		character.push_back(character0);
		character[character.size() - 1].characterInitialization(name);
		activeCharacter = character.size() - 1;
	}
}

void Game::selectCharacter()
{
	int choice;
	std::cout << "Select your character:\n";
	for (size_t i = 0; i < character.size(); i++)
	{
		std::cout << i + 1 << ":" << character[i].getName() << "\n";
	}
	std::cout << "Your choice:";
	std::cin >> choice;
	if (choice < 1 || choice > character.size())
	{
		std::cout << "\n\nWrong choice\n\n";
	}
	else
	{
		activeCharacter = choice - 1;
	}

}

void Game::deleteCharacter()
{
	int choice;
	std::cout << "Select character to delete:\n";
	for (size_t i = 0; i < character.size(); i++)
	{
		std::cout << i + 1 << ":" << character[i].getName() << "\n";
	}
	std::cout << "Your choice:";
	std::cin >> choice;
	if (choice < 1 || choice > character.size())
	{
		std::cout << "\n\nWrong choice\n\n";
	}
	else
	{
		character.erase(character.begin()+choice-1);
	}
	
}


void Game::saveCharacter()
{
	std::ofstream fout("character.txt");
	if (!fout.is_open())
	{
		std::cout << "\nCan't open file with save!\n";
	}
	else
	{
		for (size_t i = 0; i < character.size(); i++)
		{
			character[i].characterSave(fout);
		}
	}

	fout.close();
}

void Game::loadCharacter()
{
	int i = 0;
	character.clear();
	std::ifstream fin("character.txt");
	if (!fin.is_open())
	{
		std::cout << "\nCan't open file with save!\n";
	}
	else
	{
		
		while (!fin.eof())
		{
			std::cout << "CHARACTER I:" << i << "\n";
			system("PAUSE");
			character.push_back(character0);
			character[i].characterLoad(fin);
			
			i++;
		}
		character.pop_back();
		for (size_t i = 0; i < character.size(); i++)
		{
			if(character[i].getIndexEquipWeapon() > -1)
				character[i].equipEquipment(character[i].getIndexEquipWeapon() + 1);
			if (character[i].getIndexEquipHead() > -1)
				character[i].equipEquipment(character[i].getIndexEquipHead() + 1);
			if (character[i].getIndexEquipChest() > -1)
				character[i].equipEquipment(character[i].getIndexEquipChest() + 1);
			if (character[i].getIndexEquipArms() > -1)
				character[i].equipEquipment(character[i].getIndexEquipArms() + 1);
			if (character[i].getIndexEquipLegs() > -1)
				character[i].equipEquipment(character[i].getIndexEquipLegs() + 1);
			if (character[i].getIndexEquipBoots() > -1)
				character[i].equipEquipment(character[i].getIndexEquipBoots() + 1);
		}
		
	}

	fin.close();
}














Game::Game()
{
	isPlaying = true;
	choice = 0;
	activeCharacter = 0;
	character.push_back(character0);

}


Game::~Game()
{
}


void Game::chekingName(std::string& name)
{
	
	int i = 0;
	while(i != character.size())
	{
		if (sameName(character[i].getName(), name))
		{
			std::cout << "\nOops!This name is already taken\n";
			std::cout << "Enter new name of your character:";
			std::cin >> name;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

bool Game::sameName(std::string str1, std::string str2)
{
	str1 = upName(str1);
	str2 = upName(str2);
	if (str1 == str2) { return true; }
	else {
		return false;
	}
}

std::string Game::upName(std::string str)
{
	std::string converted;
	for (size_t i = 0; i < str.size(); i++)
	{
		converted += toupper(str[i]);
	}
	return converted;
	
}