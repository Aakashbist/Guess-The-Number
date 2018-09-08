#include "Game.h"
#include<iostream>
#include <fstream>

#define instructionFile "Instruction.txt"
#define winFile			"Win.txt"
#define loseFile		"Lose.txt"
#define menuFile		"Menu.txt"
#define welcomeFile		"Welcome.txt"

using namespace std;


void GAME::getInstruction()
{
	readFile(instructionFile);
}

void GAME::getWinMessage()
{
	readFile(winFile);
}

void GAME::getLoseMessage()
{
	readFile(loseFile);
}


void GAME::getMenu()
{
	readFile(menuFile);
}


void GAME::welcome()
{
	readFile(welcomeFile);
}

void GAME::readFile(string fileName)
{
	ifstream fin;
	string line;
	fin.open(fileName);

	while (!fin.eof())
	{
		getline(fin, line);
		cout << line << "\n";
	}
	fin.close();
}