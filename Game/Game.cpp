#include"Game.h"
#include"Helper.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include"Settings.h"

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
	num = rand() % MAX_VALUE;
	while (counter != MAX_CHANCES)
	{
			helper.print("\nPlease enter your guess: ");
			cin >> guess;
			if (num != guess)
			{
				if (guess < num)
				{
					helper.print("Wrong Guess. your guess is below the Number");
				}
				else
				{
					helper.print("Wrong Guess. your guess is above the Number");
				}
				counter++;
				firstcorrectAttempt++;
			} else {
				getWinMessage();
				firstcorrectAttempt++;
				break;
			}	

			if (counter == 3)
			{
				getLoseMessage();
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