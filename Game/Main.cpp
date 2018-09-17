#include"GameLoop.h"
#include"Helper.h"
#include<Windows.h>

using namespace std;

void main()
{
	Player *player = new Player;
	Game *game = new Game;
	Helper *helper = new Helper;
	GameLoop *gameLoop = new GameLoop;
	game->welcome();
	int option;

	do {
		game->getMenu();
		helper->print("Choose your option: ");
		cin >> option;
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
		case 3:
			//ignore
			break;
		default:
			helper->print("Please choose valid options");
			break;
		}

	} while (option != 3);
	delete player;
	delete game;
	delete helper;
	delete game;
}