#include"Game.h"
#include"Helper.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include <cstdio>
#include <ctime>
#include<string>
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
	readFile(instructionFile, true);
}

void Game::getWinMessage()
{
	readFile(winFile, true);
}

void Game::getLoseMessage()
{
	readFile(loseFile, true);
}


void Game::getMenu()
{
	readFile(menuFile, true);
}

void Game::getSubMenu()
{
	readFile(subMenuFile, true);
}


void Game::welcome()
{
	readFile(welcomeFile, true);
}

//for timer
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
	stopTimer = false;
	srand(time(NULL));
	std::thread first(displayTime);

	int num, guess, level, maxChance, totalchance, totalScore = score;

	string option = "y";
	do
	{
		counter = 0;
		level = (rand() % 3) + 1;//1 2 3
		num = (rand() % (level * 20));//20 40 60
		maxChance = level * 2;//2 4 6
		totalchance = level * 2;//2 4 6

		helper->print("\tLevel : " + to_string(level) + "\tScore: " + to_string(player->getScore()) + '\n');
		helper->print("You can guess the number from 0 - " + to_string(level * 20) + '\n');

		while (counter <= maxChance + 2)//0<=2||4||6 
		{

			string message = "You have " + to_string(totalchance--) + " out of " + to_string(maxChance) + " chance left";
			helper->print(message);
			guess = helper->validateAndGetNumber("\n\tPlease enter your guess: ");
			if (guess > 1000)
			{
				string message = "You can guess only number up to " + to_string(MAX_GUESS_AllOW) + "\n\n";
				helper->print(message);
			}
			else {
				if (num != guess)
				{
					if (guess < num)
					{
						helper->print("Wrong Guess. your guess is below the Number\n\n");
					}
					else
					{
						helper->print("Wrong Guess. your guess is above the Number\n\n");
					}
					counter++;

				}
				else {
					totalScore += (level * 5);
					player->setScore(totalScore);
					getWinMessage();
					break;
				}
			}
			if (counter == maxChance)
			{
				totalScore += (level * 2);
				player->setScore(totalScore);
				getLoseMessage();
				break;
			}
		}
		maxChance--;
		option = helper->validateAndGetString("Do you want to continue (y/n) : ");
		helper->clearScreen();
	} while ((option.compare("n") != 0 && option.compare("N") != 0));
	stopTimer = true;
	first.join();
	helper->clearScreen();
	delete helper;

	SetConsoleTitle("GUESS THE NUMBER");
}


// to read text from files 
string Game::readFile(string fileName, bool toPrint)
{
	ifstream fin;
	string line;
	fin.open(fileName);

	while (!fin.eof())
	{
		getline(fin, line);
		if (toPrint) {
			cout << line << "\n";
		}
	}
	fin.close();
	return line;
}

