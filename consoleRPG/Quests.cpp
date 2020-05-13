#include "Quests.h"


void Quests::humanMain(Character& character)
{
	if (character.quests.getHumanMainComplete())
	{
		system("CLS");
		std::cout << "+++You already complete this quest!+++\n";
	}
	else
	{
		if (character.quests.getHumanMainProgress() == 1)
		{
			system("CLS");
			std::cout << "+++Congratulation!You complete your first quest!+++\n";
			character.quests.increasetHumanMainProgress();
			character.quests.completeHumanMainQuest();
		}
	}
}







Quests::Quests()
{
}


Quests::~Quests()
{
}
