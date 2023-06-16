//Definitions for the Player Class
#include "Player.h"

Player::Player()
{
	firstName = " ";
	lastName = " ";
	fullName = " ";
	symbol = ' ';
	wins = 0;
	losses = 0;
	draws = 0;
}


Player::Player(string newFirst, string newLast, string newFull, 
	char newSym, int newWin, int newLoss, int newDraw)
{

	firstName = newFirst;
	lastName = newLast;
	fullName = newFull;
	symbol = newSym;
	wins = newWin;
	losses = newLoss;
	draws = newDraw;
}


Player::~Player() 
{
}


string Player::getFirstName() const 
{
	return firstName;
}


string Player::getLastName() const 
{
	return lastName;
}


string Player::getFullName() const 
{
	return fullName;
}


char Player::getSymbol() const 
{
	return symbol;
}


int Player::getWins() const 
{
	return wins;
}


int Player::getLosses() const 
{
	return losses;
}


int Player::getDraws() const
{
	return draws;
}


void Player::setFirstName(string newFirst) 
{
	firstName = newFirst;
}


void Player::setLastName(string newLast)
{
	lastName = newLast;
}


void Player::setFullName(string newFirst, string newLast) 
{
	fullName = newFirst + " " + newLast;
}


void Player::setSymbol(char newSym) 
{
	symbol = newSym;
}


void Player::setWins(int newW)
{
	wins = newW;
}


void Player::setLosses(int newL) 
{
	losses = newL;
}


void Player::setDraws(int newD) 
{
	draws = newD;
}


void Player::win() 
{
	++wins;
}


void Player::loss() 
{
	++losses;
}


void Player::draw() 
{
	++draws;
}