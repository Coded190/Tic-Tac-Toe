#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

const int SIZE = 10;

void displayBoard(char[], const int);
char currentStatus(char[], const int, int);
void printFullStats(Player, Player, int);
int startingPlayer(Player, Player);
int switchPlayer(int);
void displayWinningConfig(char[], const int);
void clearBoard(char[], const int);
int validate(int, char[]);
char to_LowerCase(char);
char to_UpperCase(char);
Player set_Player(int);

int main()
{
	char board[SIZE];
	clearBoard(board, SIZE);
	char again = ' ';
	char playAgain = ' ';
	int playerTurn;
	int totalGamesPlayed = 1;
	int startPlayer;
	int choice;
	int turns_played = 0;

	cout << "Welcome to the 3 by 3 Tic Tac Toe game!" << endl;
	Player player1 = set_Player(1);		// make this block dynamic, use a function
	player1.setSymbol('o');

	Player player2 = set_Player(2);
	player2.setSymbol('x');

	cout << endl;
	playerTurn = startingPlayer(player1, player2);

	do
	{
		do
		{
			playerTurn = switchPlayer(playerTurn);
			startPlayer = playerTurn;
			displayBoard(board, SIZE);

			if (playerTurn == 1)
			{
				cout << player1.getFirstName() << " please enter your choice: ";
			}
			else
			{
				cout << player2.getFirstName() << " please enter your choice: ";
			}
			cin >> choice;
			choice = validate(choice, board);
			turns_played++;					//change to take the row*column and if turns_played == max_turns there is a draw.********

			if (playerTurn == 1)
			{
				board[choice] = player1.getSymbol();
			}
			else
			{
				board[choice] = player2.getSymbol();
			}
			again = currentStatus(board, SIZE, turns_played);		//change variable inside currentStatus	

		} while (again == 'y');

		if (again == 'o' || again == 'x')		//change the receiving variables
		{
			if (again == 'o')
			{
				player1.win();
				player2.loss();
			}
			else if (again == 'x')
			{
				player2.win();
				player1.loss();
			}

			displayWinningConfig(board, SIZE);
			printFullStats(player1, player2, totalGamesPlayed);
		}
		else
		{
			displayBoard(board, SIZE);
			cout << "Tie Game!" << endl;
			player1.draw();
			player2.draw();
			printFullStats(player1, player2, totalGamesPlayed);

			if (startPlayer == 1)
			{
				playerTurn = startPlayer;
			}
			else
			{
				playerTurn = startPlayer;
			}
		}

		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;
		totalGamesPlayed++;
		turns_played = 0;
		clearBoard(board, SIZE);

	} while (playAgain == 'y' || playAgain == 'Y');

}


//**************************************************************
// This function sets the player's first and last name.		   *
// @param - void											   *
// @return - Player player									   *
//**************************************************************

Player set_Player(int player_number)
{
	cout << "Please enter the first and last name of Player ";
	cout << player_number << " (separate the names with a space) : ";
	string first, last;
	Player player;
	cin >> first >> last;
	player.setFirstName(first);
	player.setLastName(last);
	player.setFullName(first, last);

	return player;
}


//**************************************************************
// This function validates the user's input for correct		   *
// spot selection on the board.								   *
// @param - int c, char board[]								   *
// @return - int c											   *
//**************************************************************

int validate(int c, char board[])
{
	while (c < 1 || c > 9 ||
		   board[c] == 'x' ||
		   board[c] == 'o')
	{
		cout << "That is not a correct choice!\n";
		cout << "Please choose a spot on the board : ";
		cin >> c;
	}

	return c;
}

//**************************************************************
//This function clears the board once there is a win or draw,  *
// for the next game.                                          *
// @param - char board[], const int SIZE                       *
// @return - void                                              *
//**************************************************************

void clearBoard(char board[], const int SIZE)
{
	char index = '1';
	for (int i = 1; i <= 9; i++)
	{
		board[i] = index;
		index += 1;
	}
}


//**************************************************************
//This function determines which player is the starting player *
// based on lower last name value.                             *
// @param - Player player1, Player player2					   *
// @return - int playerTurn									   *
//**************************************************************

int startingPlayer(Player player1, Player player2)
{
	int start;
	if (player1.getLastName() > player2.getLastName())
	{
		start = 1;
	}
	else
	{
		start = 2;
	}

	return start;
}


//**************************************************************
//This function switches the playing player based on the       *
// previous round											   *
// @param - int playerTurn									   *
// @return - int playerTurn									   *
//**************************************************************

int switchPlayer(int playerTurn)
{
	if (playerTurn == 1)
	{
		playerTurn = 2;
	}
	else
	{
		playerTurn = 1;
	}
	return playerTurn;
}


//**************************************************************
//This function takes in the board array and SIZE, then output *
// the tictactoe board taking into account the players mark.   *
// @param - char[] board, const int SIZE					   *
// @return - void											   *
//**************************************************************

void displayBoard(char board[], const int SIZE)
{
	int a = 9;
	int b = 8;
	int c = 7;

	cout << "*---*---*---*" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "| " << board[a] << " | " << board[b];
		cout << " | " << board[c] << " |" << endl;
		cout << "*---*---*---*" << endl;
		a -= 3;
		b -= 3;
		c -= 3;
	}
}


//**************************************************************
// This function converts the symbol to lowercase to determine *
// all winning configurations.								   *
// @param - char c											   *
// @return - char c											   *
//**************************************************************

char to_LowerCase(char c)
{
	if (c >= 'a' && c <= 'z')		//change these to characters for readability
	{
		return c;
	}
	else
	{
		return c + ('a' - 'A');
	}
}


//**************************************************************
// This function converts the symbol to uppercase to determine *
// all winning configurations.								   *
// @param - char c											   *
// @return - char c											   *
//**************************************************************

char to_UpperCase(char c)		//add this to the documentation
{
	if (c >= 'A' && c <= 'Z')		//change these to characters for readability
	{
		return c;
	}
	else
	{
		return c - ('a' - 'A');
	}
}



//**************************************************************
//This function checks the rows, columns, and both diagonal	   *
// directions to determine if there is a winner. If no winner, *
//  function checks if there is a draw. If no draw, function   *
// returns signal to continue game.							   *
// @param - char[] board, const int SIZE					   *
// @return - char signal									   *
//**************************************************************

char currentStatus(char board[], const int SIZE, int turns_played)
{

	int a = 9;
	int b = 8;
	int c = 7;
	for (int i = 0; i < 3; i++)
	{
		if (board[a] == board[b] && board[b] == board[c])
		{
			if (board[a] == 'o')
			{
				return 'o';
			}
			else
			{
				return 'x';
			}
		}
		a -= 3;
		b -= 3;
		c -= 3;
	}

	a = 9;
	b = 6;
	c = 3;
	for (int i = 0; i < 3; i++)
	{
		if (board[a] == board[b] && board[b] == board[c])
		{
			if (board[a] == 'o')
			{
				return 'o';
			}
			else
			{
				return 'x';
			}
		}
		a -= 1;
		b -= 1;
		c -= 1;
	}

	a = 9;
	b = 5;
	c = 1;
	for (int i = 0; i < 2; i++)
	{
		if (board[a] == board[b] && board[b] == board[c])
		{
			if (board[a] == 'o')
			{
				return 'o';
			}
			else
			{
				return 'x';
			}
		}
		a -= 2;
		c += 2;
	}
	if (turns_played == 9)
	{
		return 'd';
	}
	else
	{
		return 'y';
	}
}

//**************************************************************
//This function displays the winning configuration, showing	   *
// the symbol in all caps.									   *
// @param - char[] board, const int SIZE					   *
// @return - void											   *
//**************************************************************

void displayWinningConfig(char board[], const int SIZE)
{
	int a = 9;
	int b = 8;
	int c = 7;
	for (int i = 0; i < 3; i++)
	{
		if (to_LowerCase(board[a]) == to_LowerCase(board[b]) &&
			to_LowerCase(board[b]) == to_LowerCase(board[c]))
		{
			board[a] = to_UpperCase(board[a]);
			board[b] = to_UpperCase(board[b]);
			board[c] = to_UpperCase(board[c]);
		}
		a -= 3;
		b -= 3;
		c -= 3;
	}

	a = 9;
	b = 6;
	c = 3;
	for (int i = 0; i < 3; i++)
	{
		if (to_LowerCase(board[a]) == to_LowerCase(board[b]) &&
			to_LowerCase(board[b]) == to_LowerCase(board[c]))
		{
			board[a] = to_UpperCase(board[a]);
			board[b] = to_UpperCase(board[b]);
			board[c] = to_UpperCase(board[c]);
		}
		a -= 1;
		b -= 1;
		c -= 1;
	}

	a = 9;
	b = 5;
	c = 1;
	for (int i = 0; i < 2; i++)
	{
		if (to_LowerCase(board[a]) == to_LowerCase(board[b]) &&
			to_LowerCase(board[b]) == to_LowerCase(board[c]))
		{
			board[a] = to_UpperCase(board[a]);
			board[b] = to_UpperCase(board[b]);
			board[c] = to_UpperCase(board[c]);
		}
		a = 7;
		c = 3;
	}
	displayBoard(board, SIZE);
}


//**************************************************************
//This function displays the full game stats, player		   *
// information, and the games played.						   *
// @param - Player player1, Player player2, int gamesPlayed	   *
// @return - void											   *
//**************************************************************

void printFullStats(Player player1, Player player2, int totalGamesPlayed)
{
	cout << "Game Stats!" << endl;
	cout << "Total Games Played: " << totalGamesPlayed << endl << endl;

	cout << player1.getFullName() << endl;
	cout << "Wins: " << player1.getWins() << endl;
	cout << "Losses: " << player1.getLosses() << endl;
	cout << "Draws: " << player1.getDraws() << endl << endl;

	cout << player2.getFullName() << endl;
	cout << "Wins: " << player2.getWins() << endl;
	cout << "Losses: " << player2.getLosses() << endl;
	cout << "Draws: " << player2.getDraws() << endl << endl;
}