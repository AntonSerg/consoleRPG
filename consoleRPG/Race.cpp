#include "Race.h"



Race::Race()
{
	this->currentRace = 0;
	Races[0] = "No race";
	Races[1] = "Human";
	Races[2] = "Elf";
	Races[3] = "Dark Elf";
	Races[4] = "Dwarf";
	Races[5] = "Nigger";
}


Race::~Race()
{
}



void Race::raceInitialization()
{
	std::cout << "Races:\n1:Human\n2:Elf\n3:Dark Elf\n4:Dwarf\n5:Nigger\n";
	std::cout << "Enter characters race:";
	std::cin >> this->currentRace;
	while (std::cin.fail() || currentRace < 1 || currentRace > 5)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nWrong Race!\n";
		std::cout << "Enter characters race:";
		std::cin >> currentRace;

	}
}

