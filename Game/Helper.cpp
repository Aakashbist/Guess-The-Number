#include "Helper.h"

void Helper::print(string message)
{
	cout << "\n" << "    " << message;
}

void Helper::clearScreen()
{
	system("CLS");
}