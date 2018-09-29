# define _CRT_SECURE_NO_DEPRECATE

#include<string>


class Game {

private:
	

public:
	void getInstruction();
	void getWinMessage();
	void getLoseMessage();
	void getMenu();
	void getSubMenu();
	void welcome();
	void playGame(std::string,int);
	std::string readFile(std::string);
	
};