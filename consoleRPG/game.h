#pragma once
#include "HumanT.h"


class Game
{
private:
	int choice;
	bool isPlaying;
	std::vector<Character> character;
	Character character0;
	int activeCharacter;
	HumanT humanT;
public:
	Game();
	~Game();

	//functions:
	void mainMenu();
	void createCharacter();
	void selectCharacter();
	void deleteCharacter();
	void saveCharacter();
	void loadCharacter();

	//CHEKING NAME
	void chekingName(std::string& name);
	bool sameName(std::string str1, std::string str2);
	std::string upName(std::string str);

	//get var:
	inline bool getIsPlaying()const { return this->isPlaying; }
};
