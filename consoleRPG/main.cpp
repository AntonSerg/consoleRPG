#include "game.h"


int main()
{

	Game game;
	while (game.getIsPlaying())
	{
		game.mainMenu();

	}
	return 0;
}

