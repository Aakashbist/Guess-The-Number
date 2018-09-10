#include"Helper.h"
#include"GameLoop.h"

void GAMELOOP::startGame(GAME game, PLAYER player) {

	HELPER helper;
	int subOption;

	helper.clearScreen();
	player.setPlayer();
	do {
		game.getSubMenu();
		helper.print("Choose your option: ");
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
			helper.print("Please choose valid options");
			break;
		}

	} while (subOption != 2);
	helper.clearScreen();
}