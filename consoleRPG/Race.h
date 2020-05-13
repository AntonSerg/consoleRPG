#pragma once
#include "QuestList.h"

class Race
{
private:
	//RACES:
	
	std::string Races[6];
	
public:
	Race();
	~Race();
	//METHODS
	void raceInitialization();
	//currentRace
	int currentRace;

	//GET INF
	inline int getCurrentRace() const { return this->currentRace; }
	inline std::string Race::printRace() const { return this->Races[currentRace]; }
};