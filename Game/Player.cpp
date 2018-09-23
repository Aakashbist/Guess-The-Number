#include"Helper.h"
#include"Player.h"
#include"Game.h"
#include<fstream>
#include<ctype.h>
#include<filesystem>
#include"Settings.h"


using namespace std;
ofstream fout;
ifstream fin;
string name;
int score;
int level;
Helper helper;

//Constructors
Player::Player(char* name, int score, int level)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->score = score;
	this->level = level;
}

//Destructor
Player::~Player()
{
	delete[] name;
}

void Player::setPlayer(char* name)
{
	if (checkPlayer(name)) {
		int score = getScore();
		int level = getLevel();
		//	string message = "Welcome Back " + *name + "    Score: " + std::to_string(score) + "      Level: " + std::to_string(level) + "!!\n";
		//helper.print(message);
	}
	else
	{
		fout.open(highscoreFile, ios::app);
		fout << name << " 0 " << "0 " << endl;
		//helper.print("welcome, "+name+" !!");
		fout.close();
	}
}



void Player::setName(char* name) {
	strcpy(this->name, name);
}
void Player::setScore(int value)
{
	score = value;
}

char*  Player::getName(void)
{
	return name;
}

int Player::getScore(void)
{
	fin.open(highscoreFile);
	fin >> score;
	return score;
}

bool Player::checkPlayer(char* name)
{
	fin.open(highscoreFile);
	while (!fin.eof())
	{
		fin >> name;
		fin >> score;
		fin >> level;
		if (name == name) {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}

int Player::getLevel(void)
{
	return 0;
}

void Player::setLevel()
{

}