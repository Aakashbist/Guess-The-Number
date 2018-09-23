#include "Helper.h"
#include<Windows.h>

void Helper::print(string message)
{
	cout << "\n\t" << message;
}

void Helper::clearScreen()
{
	system("CLS");
}

void Helper::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}