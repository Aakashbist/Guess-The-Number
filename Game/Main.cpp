#include"GameLoop.h"
#include"Helper.h"
#include<Windows.h>
#include<ctype.h>
#include "Settings.h"

using namespace std;

void main()
{

	Game *game = new Game;
	Player *player = new Player();
	player->setName("Bikash");
	player->setScore(player->getScore());
	
	Helper *helper = new Helper;
	GameLoop *gameLoop = new GameLoop;
	
	SetConsoleTitle("GUESS THE NUMBER");
	
	game->welcome();
	int option;

	do {
		game->getMenu();
		option = helper->validateAndGetNumber("Choose your option : ");
		/*while(option!=3)
		{
		*/	switch (option)
			{
			case 1:
				gameLoop->startGame(*game, *player);
				break;
			case 2:
				helper->clearScreen();
				game->getInstruction();
				system("pause");
				helper->clearScreen();
				break;
			default:
				helper->print("Please choose valid options");
				break;
			}
		//}

	} while (option != 3);
	delete player,game,helper;
	}