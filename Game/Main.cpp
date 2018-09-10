#include"GameLoop.h"
#include"Helper.h"
#include<Windows.h>

using namespace std;

void main()
{
	PLAYER player;
	GAME game;
	HELPER helper;
	game.welcome();
	int option;

	do {
		game.getMenu();
		helper.print("Choose your option: ");
		cin >> option;
		switch (option)
		{
		case 1:
			GAMELOOP gameLoop;
			gameLoop.startGame(game, player);
			break;
		case 2:
			helper.clearScreen();
			game.getInstruction();
			system("pause");
			helper.clearScreen();
			break;
		case 3:
			//ignore
			break;
		default:
			helper.print("Please choose valid options");
			break;
		}

	} while (option != 3);
}
