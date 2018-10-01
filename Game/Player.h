# define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>

class Player {

private:
	char* name;
	int score;



public:

	Player(char* = "Unknown", int = 0);

	void setName(char*);
	std::string getName(void);
	void setScore(int);
	int getScore(void);
	
};