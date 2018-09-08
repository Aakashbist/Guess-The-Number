#include"CPlayer.h"
#include"Game.h"
#include<fstream>
#include<ctype.h>
#include <filesystem>

#define filename "HighScore.txt"
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
		fout.open(filename, ios::app);
		fout << name << " 0 " << "0 " << endl;//sudip 45 755
		cout << "Welcome " << name << "!!\n";
	}
}

void PLAYER::setScore(int _score)
{
	score = _score;
}

string PLAYER::getName(void)
{
	return name;
}

int PLAYER::getScore(void)
{
	fin.open(filename);
	fin >> score;
	cout << score;
	return 0;
}

bool PLAYER::checkPlayer(string player)
{
	string name;
	int score, level;
	fin.open(filename);
	if (filename)
	{

		while (!fin.eof())
		{//aakash 0 234
			fin >> name;//aakash
			fin >> score;//0
			fin >> level;//234
			if (name == player)
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
