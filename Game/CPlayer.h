#include<iostream>
#include<string>

class PLAYER {

private:
	std::string name;
	int score, level;

public:
	void setPlayer();
	void setScore(int);

	void setLevel();

	std::string getName(void);
	int getScore(void);
	bool checkPlayer(std::string);
	int getLevel(void);

};