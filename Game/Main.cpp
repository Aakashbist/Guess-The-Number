#include"GameLoop.h"
#include"Helper.h"
#include<Windows.h>
#include<ctype.h>

using namespace std;

void main()
{
	SetConsoleTitle("GUESS THE NUMBER");
	Player *player = new Player;
	Game *game = new Game;
	Helper *helper = new Helper;
	GameLoop *gameLoop = new GameLoop;
	game->welcome();
	int option;

	do {
		game->getMenu();
		option = helper->validateAndGetNumber("Choose your option : ");
		while(option!=3)
		{
			switch (option)
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
		}

	} while (option != 3);
	delete player;
	delete game;
	delete helper;
	delete game;
}