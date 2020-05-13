#pragma once
#include "Inventory.h"
class Character
{
	
private:
	//NAME
	std::string name;
	//INVENTORY
	Inventory characterInv;
	Armor* characterHead;
	int indexEquipHead;
	Armor* characterChest;
	int indexEquipChest;
	Armor* characterArms;
	int indexEquipArms;
	Armor* characterLegs;
	int indexEquipLegs;
	Armor* characterBoots;
	int indexEquipBoots;
	Weapon* characterWeapon;
	int indexEquipWeapon;
	//ABoUT CHARACTER
	int sex;
	Race characterRace;
	int position;
	//LEVELING
	int level;
	int exp;
	int expNext;
	//HP/MP/DMG/DEF
	int hp;
	int hpMax;
	int mp;
	int mpMax;
	int dmg;
	int dmgMax;
	int defence;
	int accuracy;
	int agility;
	//STATS
	int mainAttribute;
	int strenght;
	int dexterity;
	int intelligence;
	int luck;
	//POINTS
	int statPoints;
	int skillPoints;
	int gold;

public:
	Character();
	~Character();
	//QUESTS LIST
	QuestList quests;
	//METHODS{
	//Character intialization/UPDATE
	void Character::characterInitialization(std::string& name);
	void Character::whichMainAttribute();
	void Character::setAttribute();
	void Character::updateStats();
	//SAVE/LOAD
	std::string Character::getAsString();
	void Character::characterSave(std::ofstream& fout);
	void Character::characterLoad(std::ifstream& fin);
	void Character::loadStats();
	//increase
	void Character::levelUp();
	void Character::increaseStats();
	void Character::increaseExp(int x);
	void Character::increaseGold(int x);
	void Character::takeDamage(int x);
	void Character::restoreHp();
	//Inventory
	int Character::inventorySize();
	void Character::showInventory();
	void Character::showWeapons();
	void Character::showArmors();
	void Character::loadItem(int id);
	void Character::inventoryAddItem(const Item& item);
	void Character::inventoryRemoveItem(int i);
	//EQUIP
	void Character::equipEquipment(int i);
	int Character::equipmentStrenght();
	int Character::equipmentDexterity();
	int Character::equipmentIntelligence();
	int Character::equipmentLuck();
	//OTHER
	void Character::showStats();
	void Character::dieCharacter();
	//}
	//GETINF
	inline std::string getName() const { return this->name; }
	inline int getRace() const { return this->characterRace.getCurrentRace(); }
	inline std::string getPrintRace() const { return characterRace.printRace(); }
	inline int getPositionInt() const { return this->position; }
	std::string Character::getPositionString();
	inline int getSex() const { return this->sex; }
	inline int getLevel() const { return this->level; }
	inline int getExp() const  { return this->exp; }
	inline int getExpNext() const { return this->expNext; }
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }
	inline int getMp() const { return this->mp; }
	inline int getMpMax() const { return this->mpMax; }
	inline int getDmg() const { return this->dmg; }
	inline int getDmgMax() const { return this->dmgMax; }
	inline int getDmgFinal() const { return (rand() % (this->dmgMax - this->dmg + 1) + this->dmg ); }
	inline int getDefence() const { return this->defence; }
	inline int getAccuracy() const { return this->accuracy; }
	inline int getAgility() const { return this->agility; }
	inline int getMainAttribute() const { return this->mainAttribute; }
	inline int getStr() const { return this->strenght; }
	inline int getDex() const { return this->dexterity; }
	inline int getInt() const { return this->intelligence; }
	inline int getLuck() const { return this->luck; }
	inline int getStatP() const { return this->statPoints; }
	inline int getSkillP() const { return this->skillPoints; }
	inline int getGold() const { return this->gold; }

	inline int getIndexEquipWeapon() const { return this->indexEquipWeapon; }
	inline int getIndexEquipHead() const { return this->indexEquipHead; }
	inline int getIndexEquipChest() const { return this->indexEquipChest; }
	inline int getIndexEquipArms() const { return this->indexEquipArms; }
	inline int getIndexEquipLegs() const { return this->indexEquipLegs; }
	inline int getIndexEquipBoots() const { return this->indexEquipBoots; }

	


};