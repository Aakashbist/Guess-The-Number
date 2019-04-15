#include "Helper.h"
#include<Windows.h>
#include<stdio.h> 
#include<stdlib.h>

using namespace std;


// using this function instead of cout
void Helper::print(string message)
{
	cout << "\n\t" << message;
}

//clear screen 
void Helper::clearScreen()
{
	system("CLS");
}

void Helper::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//to validate numbers in options
int Helper::validateAndGetNumber(string label)
{
	string num;
	bool allDigits;
	print(label);
	cin >> num;
	while (1)
	{
		allDigits = true;
		for (size_t i = 0; i < num.size(); i++) {
			if (!isdigit(num[i])) {
				allDigits = false;
			}
		}
		if (allDigits) {
			break;
		}
		else {
			print("Please enter valid number.");
			print(label);
			cin >> num;
		}
	}

	return std::stoi(num);
}

//validate character input
string Helper::validateAndGetString(string label)
{
	string num;
	bool allAlpha;
	print(label);
	cin >> num;
	while (1)
	{
		allAlpha = true;
		for (size_t i = 0; i < num.size(); i++) {
			if (!isalpha(num[i])) {
				allAlpha = false;
			}
		}
		if (allAlpha) {
			break;
		}
		else {
			print("Please enter valid letters.");
			print(label);
			cin >> num;
		}
	}
	return num;
}
