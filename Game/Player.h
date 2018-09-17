# define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>

class Player {

private:
	char* name;
	int score, level;



public:

	Player(char* = "Unknown", int = 0, int = 0);
	~Player();

	void setName(char*);
	void setPlayer(char*);
	void setScore(int);


	void setLevel();

	char* getName(void);
	int getScore(void);
	bool checkPlayer(char*);
	int getLevel(void);

};