#include "Fight.h"

void Fight::fightStart(Character& character)
{
	std::cout << "===" << character.getName() << " HP " << character.getHp() << "/" << character.getHpMax() << " MP " << character.getMp() << "/" << character.getMpMax() << "===\n";
	std::cout << "===Fighting===\n";
	std::cout << "1:Attack\n";
	std::cout << "2:Show mobs\n";
	std::cout << "3:Search new mobs\n";
	std::cout << "4:Leave fight(try luck)\n";
	std::cout << "5:Leave fight(-" << character.getLevel() * this->lostGold * this->luckExit << " gold)\n";
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
		if (enemy.size() > 0)
		{
			system("CLS");
			this->attackEnemy(character);
		}
		else
		{
			system("CLS");
			std::cout << "You killed all enemies.Searching new enemies.\n";
			this->fightInitialization(character);
			this->attackEnemy(character);
		}
		break;
	case 2:
		this->showMobs();
		break;
	case 3:
		this->searchNewMobs(character);
		break;
	case 4:
		this->leaveFromFightLuck(character);
		break;
	case 5:
		this->leaveFromFightGold(character);
		break;
	default:
		system("CLS");
		std::cout << "\n\nWrong choice!\n\n";
		break;
	}
}

void Fight::attackEnemy(Character& character)
{
	for (size_t i = 0; i < enemy.size(); i++)
	{
		std::cout << "[" << i + 1 << "]" << "Name:" << enemy[i].getNameEnemy()
			<< " HP " << enemy[i].getHpEnemy() 
			<< "/" << enemy[i].getHpMaxEnemy()
			<< " Level:" << enemy[i].getLevelEnemy();
		std::cout << "\n";
	}
	std::cout << "Choose enemy to attack:";
	std::cin >> this->choice;
	while (std::cin.fail() || choice < 1 || choice > enemy.size())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nWrong choice!\n";
		std::cout << "Choose enemy to attack:";
		std::cin >> choice;

	}
	if(choice < 1 || choice > this->countEnemy + 1)
	{
		system("CSL");
		std::cout << "WRONG CHOICE!\n\n";
	}
	else
	{
		system("CLS");
		this->playerLuck = rand() % character.getLuck() * character.getLevel() + 1;
		this->enemyDefence = rand() % enemy[choice - 1].getDefenceEnemy() + 1;
		std::cout << "Player:" << playerLuck << "\nEnemy:" << enemyDefence << "\n";
		if (this->playerLuck > this->enemyDefence)
		{
			std::cout << "Player attacks first\n";
			this->playerDmg = -(character.getDmgFinal());
			std::cout << "Player hit enemy on " << playerDmg << " damage!\n";
			enemy[choice - 1].takeDamageEnemy(this->playerDmg);
				if (enemy[choice - 1].getHpEnemy() > 0)
				{
					this->enemyDmg = -(enemy[choice - 1].getDmgFinalEnemy());
					std::cout << "Enemy hit player on " << enemyDmg << " damage!\n";
					character.takeDamage(this->enemyDmg);
					if (character.getHp() <= 0)
					{
						character.dieCharacter();
						this->fightFalse(); //CHARACTER DEAD
					}
				}
				else
				{
					std::cout << "\nYou kill your enemy!\n"; //ENEMY DEAD
					character.increaseExp(enemy[choice - 1].getExpEnemy());
					character.increaseGold(enemy[choice - 1].getGoldEnemy());
					enemy.erase(enemy.begin() + choice - 1);
					this->countEnemy--;
				}
		}
		else
		{
			std::cout << "Enemy attacks first\n";
			this->enemyDmg = -(enemy[choice - 1].getDmgFinalEnemy());
			std::cout << "Enemy hit player on " << enemyDmg << " damage!\n";
			character.takeDamage(this->enemyDmg);
				if (character.getHp() > 0)
				{

					
					this->playerDmg = -(character.getDmgFinal());
					std::cout << "Player hit enemy on " << playerDmg << " damage!\n";
					enemy[choice - 1].takeDamageEnemy(this->playerDmg);
					if (enemy[choice - 1].getHpEnemy() <= 0)
					{
						std::cout << "\nYou kill your enemy!\n"; //ENEMY DEAD
						character.increaseExp(enemy[choice - 1].getExpEnemy());
						character.increaseGold(enemy[choice - 1].getGoldEnemy());
						enemy.erase(enemy.begin() + choice - 1);
						this->countEnemy--;
					}
				}
				else
				{
					character.dieCharacter();
					this->fightFalse(); //CHARACTER DEAD
				}
		}
	}
	system("PAUSE");
	system("CLS");
}

void Fight::searchNewMobs(Character& character)
{
	if ((character.getLuck() * character.getLuck()) / 3 > rand() % 100)
	{
		enemy.clear();
		this->fightInitialization(character);
		system("CLS");
	}
	else
	{
		system("CLS");
		std::cout << "\n\nTry your luck next time\n\n";
	}
}

void Fight::showMobs()
{
	system("CLS");
	std::cout << "Number of enemies:" << this->countEnemy << "\n";
	for (size_t i = 0; i < enemy.size(); i++)
	{
		std::cout << "Name:" << enemy[i].getNameEnemy()
			<< " HP " << enemy[i].getHpEnemy()
			<< "/" << enemy[i].getHpMaxEnemy()
			<< " Level:" << enemy[i].getLevelEnemy()
			<< " (exp:" << enemy[i].getExpEnemy() << " gold:" << enemy[i].getGoldEnemy() << ")";
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

void Fight::leaveFromFightLuck(Character& character)
{
	if (this->luckExit == 1)
	{
		if ((character.getLuck() * character.getLuck()) / 2 > rand() % 100 + 1)
		{
			system("CLS");
			std::cout << "\n\nYou are lucky\n\n";	
			this->fightFalse();			
		}
		else
		{
			system("CLS");
			std::cout << "\n\nTry your luck next time\n\n";
			luckExit++;
		}
	}
	else
	{
		system("CLS");
		std::cout << "\n\nYour attempts have run out\n\n";
	}
}
void Fight::leaveFromFightGold(Character& character)
{
	system("CLS");
	int x = -(character.getLevel() * this->lostGold * this->luckExit);
	character.increaseGold(x);
	std::cout << "You run and lost " << x << " gold!\n";
	this->fightFalse();
}


Fight::Fight()
{
	this->fight = false;
	this->choice = 0;
	this->turn = 0;
	this->countEnemy = 0;
	this->luckExit = 1;
	this->lostGold = 0;
	this->playerDmg = 0;
	this->enemyDmg = 0;
}


Fight::~Fight()
{
}

void Fight::fightInitialization(Character& character)
{
	enemy.clear();
	this->luckExit = 1;
	this->fight = true;
	this->countEnemy = rand() % 4 + 1;
	this->lostGold = rand() % 50 + 25;
	for (size_t i = 0; i < countEnemy; i++)
	{
		enemy.push_back(enemyPB);
		enemy[i].mob1Initialization(character);
	}
}
void Fight::fightFalse()
{
	this->fight = false;
}

