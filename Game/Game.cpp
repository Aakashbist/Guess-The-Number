#include "Game.h"
#include"Helper.h"
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#define instructionFile "Instruction.txt"
#define winFile			"Win.txt"
#define loseFile		"Lose.txt"
#define menuFile		"Menu.txt"
#define subMenuFile		"SubMenu.txt"
#define welcomeFile		"Welcome.txt"

using namespace std;

int firstcorrectAttempt = 0;

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

void GAME::getSubMenu()
{
	readFile(subMenuFile);
}


void GAME::welcome()
{
	readFile(welcomeFile);
}

void GAME::startGame()
{
	HELPER helper;

	srand(time(NULL));
	
	int num, guess, counter = 0;	
	num = rand() % 10;
	while (counter != 3)
	{
		helper.print("\n\n\tPlease enter your guess: ");
		cin >> guess;
		if (num != guess) 
		{
			if (guess < num) 
			{
				helper.print("Wrong Guess. your guess is below the exact guess");
							}
			else 
			{
				helper.print("wrong guess.your guess is above the exact guess ");
			}
			counter++;
			firstcorrectAttempt ++;
		}
		else 
		{
			helper.print(" \nCongratulation ");		
			firstcorrectAttempt ++;
			break;
		}
		
		
	}

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