# define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<filesystem>
#include<Windows.h>

using namespace std;

class Helper {
public:
	void print(string message);
	void clearScreen();
	void gotoxy(int x, int y);
	int validateAndGetNumber(string label);
	string validateAndGetString(string label);
};