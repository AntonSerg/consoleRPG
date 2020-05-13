#include "Enemy.h"

void Enemy::mob1Initialization(Character& character)
{
	this->name = "mob1";
	this->level = rand() % (character.getLevel() + 3) + (this->getMinLevel(character));
	this->hpMax = 150 * this->level;
	this->hp = this->hpMax;
	this->dmg = 20 * this->level;
	this->dmgMax = 30 * this->level;
	this->defence = 10 * this->level;
	this->accuracy = 10 * this->level;
	this->agility = 10 * this->level;
	this->exp = rand() % ((10 * (this->level + this->level)) / 3) + ((10 * (this->level + this->level)) / 4);
	this->gold = rand() % 8 * this->level + this->level * 2;
}

int Enemy::getMinLevel(Character& character)
{
	if ((character.getLevel() - 3) > 0)
	{
		return (character.getLevel() - 3);
	}
	else if ((character.getLevel() - 2) > 0)
	{
		return (character.getLevel() - 2);
	}
	else if ((character.getLevel() - 1) > 0)
	{
		return (character.getLevel() - 1);
	}
	else if ((character.getLevel()) > 0)
	{
		return (character.getLevel());
	}
	else 
	{
		throw "EROR!!!";
	}
}
void Enemy::takeDamageEnemy(int x)
{
	this->hp += x;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}
Enemy::Enemy()
{
	this->name = "";
	this->level = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->dmg = 0;
	this->dmgMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->agility = 0;
	this->gold = 0;
	this->exp = 0;
}


Enemy::~Enemy()
{
}
