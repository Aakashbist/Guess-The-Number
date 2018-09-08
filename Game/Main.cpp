#include"CPlayer.h"
#include"Game.h"

using namespace std;

void main()
{
	PLAYER player;
	GAME game;
	game.welcome();
	int option;
	
	do {
		game.getMenu();
		cout << "\tChoose your option:";
		cin >> option;
		cout << "\n\n";
		switch (option)
		{
		case 1:
			player.setPlayer();

			break;
		case 2:
			
			game.getInstruction();
			break;
		default:
			cout << "Please choose valid options";
			break;
		}

	} while (option != 2);

	system("pause");

}