#include"CPlayer.h"
#include"Game.h"
#include<fstream>
#include<ctype.h>
#include"Helper.h"
#include<filesystem>

#define highscoreFile "HighScore.txt"

using namespace std;
ofstream fout;
ifstream fin;
string name;
int score;
int level;
HELPER helper;

void PLAYER::setPlayer()
{
	helper.print("Enter your name: ");
	cin >> name;
	if (checkPlayer(name)) {
		int score = getScore();
		int level = getLevel();

		string message = "Welcome Back " + name + "    Score: " + std::to_string(score) + "      Level: " + std::to_string(level) + "!!\n";
		helper.print(message);
	}
	else
	{
		fout.open(highscoreFile, ios::app);
		fout << name << " 0 " << "0 " << endl;
		cout << "Welcome " << name << "!!\n";
	}
}

void PLAYER::setScore(int value)
{
	score = value;
}

string PLAYER::getName(void)
{
	return name;
}

int PLAYER::getScore(void)
{
	fin.open(highscoreFile);
	fin >> score;
	cout << score;
	return 0;
}

bool PLAYER::checkPlayer(string playerName)
{
	fin.open(highscoreFile);
	while (!fin.eof())
	{
		fin >> name;
		fin >> score;
		fin >> level;
		if (name == playerName) {
			return true;
		}
	}
	return false;
}

int PLAYER::getLevel(void)
{
	return 0;
}

void PLAYER::setLevel()
{

}
