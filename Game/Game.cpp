#include"Game.h"
#include"Helper.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include"Settings.h"

using namespace std;

int firstcorrectAttempt = 0;

void Game::getInstruction()
{
	readFile(instructionFile);
}

void Game::getWinMessage()
{
	readFile(winFile);
}

void Game::getLoseMessage()
{
	readFile(loseFile);
}


void Game::getMenu()
{
	readFile(menuFile);
}

void Game::getSubMenu()
{
	readFile(subMenuFile);
}


void Game::welcome()
{
	readFile(welcomeFile);
}

void Game::startGame()
{
	Helper helper;

	srand(time(NULL));

	int num, guess, counter = 0;
	num = rand() % MAX_VALUE;
	helper.print("You can guess the number from 0 -20.");
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
		}
		else {
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

void Game::readFile(string fileName)
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