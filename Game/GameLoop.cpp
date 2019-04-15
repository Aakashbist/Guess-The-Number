#include"Helper.h"
#include"GameLoop.h"


// to run submenu 
void GameLoop::startGame(Game game, Player player) {
	string name = player.getName();
	Helper *helper = new Helper();
	int subOption;

	helper->clearScreen();

	do {
		int score = player.getScore();
		string message = " Welcome " + name + "\t your score is " + to_string(score) + "\n\n";
		helper->print(message);
		game.getSubMenu();
		subOption = helper->validateAndGetNumber("Choose your option : ");
		switch (subOption)
		{
		case 1:
			helper->clearScreen();
			game.playGame(name, score);
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