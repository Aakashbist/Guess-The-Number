#include"Helper.h"
#include"Player.h"
#include<fstream>
#include<ctype.h>
#include<filesystem>
#include"Settings.h"
#include"Game.h"

using namespace std;
ofstream fout;
ifstream fin;

//Constructors
Player::Player(char* name, int score)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->score = getScore();
	
}

void Player::setName(char* name) {
	strcpy(this->name, name);
	fout.open(playerNameFile);
	fout << name;
	fout.close();
}


string Player::getName(void)
{
	Game *game = new Game();
     string name= game->readFile(playerNameFile, false);
	 delete game;
	 return name;
}

void Player::setScore(int score)
{
	this->score = score;
	fout.open(highScoreFile);
	fout << score;
	fout.close();
}

int Player::getScore(void)
{
	fin.open(highScoreFile);
	fin >> score;
	fin.close();
	return score;
}

