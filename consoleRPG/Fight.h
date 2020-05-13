#pragma once
#include "Enemy.h"

class Fight
{
private:
	bool fight;
	int choice;
	int turn;
	int countEnemy;
	int luckExit;
	int lostGold;
	int playerLuck;
	int enemyDefence;
	int playerDmg;
	int enemyDmg;
	std::vector<Enemy> enemy;
	Enemy enemyPB;

public:
	Fight();
	~Fight();
	//FUNCTION
	void Fight::fightStart(Character& character);
	void Fight::fightInitialization(Character& character);
	void Fight::attackEnemy(Character& character);
	void Fight::showMobs();
	void Fight::searchNewMobs(Character& character);
	void Fight::leaveFromFightLuck(Character& character);
	void Fight::leaveFromFightGold(Character& character);
	void Fight::fightFalse();
	//GET
	inline bool getFighting() const { return this->fight; }
};

