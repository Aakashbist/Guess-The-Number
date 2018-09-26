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
		helper->print("Choose your option: ");
		cin >> option;
		//check code here
		if (!isdigit(option)) {
			helper->print("Please choose valid option: ");
		}
		else
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