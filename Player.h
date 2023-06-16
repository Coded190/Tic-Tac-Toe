//Header File for the Player Class --> Declarations

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player 
{
private:
	string firstName, lastName, fullName;
	char symbol;
	int wins, losses, draws;

public:
	Player();

	Player(string, string, string, char, int, int, int);

	~Player();

	string getFirstName() const;

	string getLastName() const;

	string getFullName() const;

	char getSymbol() const;

	int getWins() const;

	int getLosses() const;

	int getDraws() const;

	void setFirstName(string) ;

	void setLastName(string) ;

	void setFullName(string, string) ;

	void setSymbol(char) ;

	void setWins(int) ;

	void setLosses(int) ;

	void setDraws(int) ;

	void win();

	void loss();

	void draw();
};
#endif