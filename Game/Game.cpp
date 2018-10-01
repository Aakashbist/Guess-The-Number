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
#include"Player.h"

using namespace std;

int firstcorrectAttempt = 0;
int counter = 0;
bool stopTimer = false;

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
	double duration;
	std::clock_t start = std::clock();
	while (!stopTimer) {
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		string time = "GUESS THE NUMBER              Time: " + std::to_string((int)duration) + " sec";
		SetConsoleTitle(time.c_str());
		Sleep(1000);
	}
}

void Game::playGame(string name, int score)
{
	Helper *helper = new Helper();
	Player *player = new Player();

	srand(time(NULL));
	std::thread first(displayTime);
	
	int num, guess,totalScore=score;
	string option="y";
	do
	{	
		num = rand() % MAX_VALUE;
		helper->clearScreen();
		helper->print("You can guess the number from 0 - 10.\n");
		counter = 0;
		while (counter < MAX_CHANCES) {
			guess = helper->validateAndGetNumber("Please enter your guess: ");
			if (guess > 1000) {
				string message = "You can guess only number between " + to_string(MAX_GUESS_AllOW) + "\n\n";
				helper->print(message);
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
					player->setScore(totalScore);
				}
				else {
					totalScore += 5;
					player->setScore(totalScore);
					getWinMessage();
					break;
				}
			}
			if (counter == MAX_CHANCES)
			{
				totalScore +=1;
				player->setScore(totalScore);
				getLoseMessage();
				break;
			}
		}

		option = helper->validateAndGetString("Do you want to continue (y/n) : ");

	} while ((option.compare("n") != 0 && option.compare("N") != 0));
	stopTimer = true;
	first.join();
	helper->clearScreen();
	delete helper;

	SetConsoleTitle("GUESS THE NUMBER");
}



string Game::readFile(string fileName)
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
	return line;
}

