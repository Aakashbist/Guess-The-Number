#include"CPlayer.h"
#include"Game.h"
#include<fstream>
#include<ctype.h>
#include<filesystem>

#define highscoreFile "HighScore.txt"

using namespace std;
ofstream fout;
ifstream fin;
string name;
int score;

void PLAYER::setPlayer()
{
	cout << "\tEnter your name: ";
	cin >> name;
	if (checkPlayer(name)) {
		cout << "\n\tWelcome Back " << name << "  Score: " << getScore() << "  Level: " << getLevel() << "!!\n";
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

bool PLAYER::checkPlayer(string player)
{
	string name;
	int score, level;
	fin.open(highscoreFile);
	if (highscoreFile)
	{

		while (!fin.eof())
		{
			fin >> name;
			fin >> score;
			fin >> level;
			if (name == player) {
				return true;
			}
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
