#pragma once
#include "Quests.h"
class Enemy
{
private:
	std::string name;
	int level;
	int hp;
	int hpMax;
	int dmg;
	int dmgMax;
	int defence;
	int accuracy;
	int agility;
	int gold;
	int exp;
public:
	//INITIALIZATION
	void mob1Initialization(Character& character);
	int Enemy::getMinLevel(Character& character);
	//FUNCTION
	void Enemy::takeDamageEnemy(int x);
	//GETFUNC
	inline std::string getNameEnemy() const { return this->name; }
	inline int getLevelEnemy() const { return this->level; }
	inline int getHpEnemy() const { return this->hp; }
	inline int getHpMaxEnemy() const { return this->hpMax; }
	inline int getDmgEnemy() const { return this->dmg; }
	inline int getDmgMaxEnemy() const { return this->dmgMax; }
	inline int getDmgFinalEnemy() const { return (rand() % (this->dmgMax - this->dmg + 1) + this->dmg); }
	inline int getDefenceEnemy() const { return this->defence; }
	inline int getAccuracyEnemy() const { return this->accuracy; }
	inline int getAgilityEnemy() const { return this->agility; }
	inline int getExpEnemy() const { return this->exp; }
	inline int getGoldEnemy() const { return this->gold; }
	Enemy();
	~Enemy();
};

