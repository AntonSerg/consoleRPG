#pragma once
#include "Fight.h"

class HumanT : public Quests
{
private:
	int choice;
	bool isPlayingGame;
	Fight fight;

public:
	//FUNCTIONS
	void HumanTPlaying();
	void HumanTMenu(Character& character);
	void inventory(Character& character);


	//GETFUNC
	inline bool getPlayingGame() const { return this->isPlayingGame; }
	HumanT();
	~HumanT();
};

