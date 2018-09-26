# define _CRT_SECURE_NO_DEPRECATE

#include<string>

class Game {

private:
	void readFile(std::string);

public:
	void getInstruction();
	void getWinMessage();
	void getLoseMessage();
	void getMenu();
	void getSubMenu();
	void welcome();
	void startGame();
	
};