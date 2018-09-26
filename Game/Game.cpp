#include"Game.h"
#include"Helper.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include <cstdio>
#include <ctime>
#include<conio.h>
#include <thread>
#include<Windows.h>
#include"Settings.h"

using namespace std;

int firstcorrectAttempt = 0;
int counter = 0;

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


void displayTime() {
	Helper helper;
	Game game;
	double duration;
	std::clock_t start = std::clock();
	while (counter != MAX_CHANCES) {
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		string time = "GUESS THE NUMBER               Time: " + std::to_string((int)duration) + " sec";
		if ((int)duration >= GAME_END_TIME) {
			counter = MAX_CHANCES; // NOT GOOD WAY TO END GAME
			// ADD A BETTER END GAME CODE HERE
			helper.print("Time up!!");
			game.getLoseMessage();
			system("pause");
			game.getMenu();

		}
		SetConsoleTitle(time.c_str());
		Sleep(1000);
	}
}

void Game::startGame()
{
	counter = 0;
	Helper *helper = new Helper();
	srand(time(NULL));
	std::thread first(displayTime);

	int num, guess, option;
	num = rand() % MAX_VALUE;
	helper->print("You can guess the number from 0 - 20.");
	//and here 
	// run first 3 time and if lose or win ask user to continue y/n if y run the loop again
	do
	{
		while (counter < MAX_CHANCES) {
			helper->print("Please enter your guess: ");
			cin >> guess;
			if (guess > 1000) {
				{
					string message = " you can guess only number between " + to_string(MAX_GUESS_AllOW) + '\n';
					helper->print(message);
				}
			}
			else {
				if (num != guess)
				{
					if (guess < num)
					{
						helper->print("Wrong Guess. your guess is below the Number");
					}
					else
					{
						helper->print("Wrong Guess. your guess is above the Number");
					}
					counter++;
				}
				else {
					firstcorrectAttempt++;
					getWinMessage();
					break;
				}
			}
			if (counter == MAX_CHANCES)
			{
				getLoseMessage();
				break;
			}
		}

		helper->print("Do you want to continue: ");
		cin >> option;

	} while (option != 'n' || option != 'N');
	delete helper;
	first.join();
	SetConsoleTitle("GUESS THE NUMBER");
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

