#include "QuestList.h"

void QuestList::increasetHumanMainProgress()
{
	this->humanMainProgress++;
}

void QuestList::completeHumanMainQuest()
{
	this->humanMainComplete = true;
}

QuestList::QuestList()
{
	this->humanMainProgress = 0;
	this->humanMainComplete = false;
}


QuestList::~QuestList()
{
}

void QuestList::questListInitializate(int race)
{
	if (race == 1)
	{
		this->humanMainProgress = 1;
		this->humanMainComplete = false;
	}
	else if (race == 2)
	{
		this->humanMainProgress = 0;
		this->humanMainComplete = false;
	}
	else if (race == 3)
	{
		this->humanMainProgress = 0;
		this->humanMainComplete = false;
	}
	else if (race == 4)
	{
		this->humanMainProgress = 0;
		this->humanMainComplete = false;
	}
	else if (race == 5)
	{
		this->humanMainProgress = 0;
		this->humanMainComplete = false;
	}
}

