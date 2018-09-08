#include"CPlayer.h"
#include"Game.h"
#include"Helper.h"
#include<Windows.h>

using namespace std;

void main()
{
	PLAYER player;
	GAME game;
	HELPER helper;
	game.welcome();
	int option, subOption;

	do {
		game.getMenu();
		helper.print("\n\tChoose your option: ");
		cin >> option;
		switch (option)
		{
		case 1:
			helper.clearScreen();
			player.setPlayer();
			do {
				game.getSubMenu();
				helper.print("\n\tChoose your option: ");
				cin >> subOption;
				switch (subOption)
				{
				case 1:
					helper.clearScreen();
					game.startGame();
					break;
				case 2:
					//exit
					break;
				default:
					helper.print("\n\tPlease choose valid options");
					break;
				}

			} while (subOption != 2);
			system("pause");
			helper.clearScreen();
			break;
		case 2:
			helper.clearScreen();
			game.getInstruction();
			system("pause");
			helper.clearScreen();
			break;
		case 3:
			// ignore
			break;
		default:
			helper.print("\tPlease choose valid options");
			break;
		}

	} while (option != 3);
}
