#include"Helper.h"
#include"GameLoop.h"

void GameLoop::startGame(Game game, Player player) {

	Helper *helper = new Helper();
	int subOption;

	helper->clearScreen();

	char* name = new char[50];
	helper->print("Enter your Name: ");
	cin >> name;
	player.setPlayer(name);

	do {
		game.getSubMenu();
		helper->print("Choose your option: ");
		cin >> subOption;
		switch (subOption)
		{
		case 1:
			helper->clearScreen();
			game.startGame();
			break;
		case 2:
			//exit
			break;
		default:
			helper->print("Please choose valid options");
			break;
		}

	} while (subOption != 2);
	helper->clearScreen();
	delete helper;
}