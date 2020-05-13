#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <fstream>
class QuestList
{
private:
	//QUESTS PROGRESS
	int humanMainProgress;
	//QUESTS COMPLETE
	bool humanMainComplete;
public:
	//INITIALIZATE
	void questListInitializate(int race);
	//HUMAN MAIN QUEST:
	void QuestList::increasetHumanMainProgress();
	void QuestList::completeHumanMainQuest();

	//GET INF QUESTS
	inline int getHumanMainProgress() const { return this->humanMainProgress; }
	inline bool getHumanMainComplete() const { return this->humanMainComplete; }
	QuestList();
	~QuestList();
};

