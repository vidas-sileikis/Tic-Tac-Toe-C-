#include "TicTacToe.h"
#include <iostream>
#include <iomanip>

void ticTacToe::play() //To start the play
{
	char playerChar;
	int playerRow;
	int playerCol;
	displayBoard();

	if (player == X)
		playerChar = 'X';
	else if (player == O)
		playerChar = 'O';

	cout << "\nPlayer " << playerChar << " enter move (row col): ";
	cin >> playerRow;
	cin >> playerCol;
	//cout << "OK: " << isValidMove(row, col);
	while (isValidMove(playerRow, playerCol) == false)
	{
		cout << "\nInvalid move! || Player " << playerChar << " enter move (row col): ";
		cin >> playerRow;
		cin >> playerCol;
	}
	board[playerRow - 1][playerCol - 1] = playerChar; //Set board piece to player X or O
	noOfMoves++;
	if (gameStatus(playerChar, playerRow, playerCol) == CONTINUE) //Check if player wins, draws or continues
		getXOMove(playerChar); //Only switch move to next player if game continues

}

void ticTacToe::displayBoard() const //To print the board
{
	cout << setw(5) << "1" << setw(4) << "2" << setw(4) << "3" << endl;
	//cout << "1" << setw(3) << "|" << setw(3) << "|" << endl;
	cout << "  _____________\n";
	for (int r = 0; r < 3; r++)
	{
		cout << setw(3) << "|";
		for (int k = 0; k < 3; k++)
		{
			cout << " " << board[r][k] << " |";
		}
		cout << endl;
		cout << r + 1 << " |___|___|___|";
		cout << endl;
	}
}

bool ticTacToe::isValidMove(int x, int y) const //To determine if a move is valid
{
	if ((x > 0) && (x <= 3) && (y <= 3) && (y > 0)) // Check if row and column are valid
	{
		if (board[x - 1][y - 1] == ' ') // Return true if empty space 
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

void ticTacToe::getXOMove(char moveSymbol) //To get a move for the next player 
{
	if (moveSymbol == 'X')
		player = O;
	else if (moveSymbol == 'O')
		player = X;
	play();

}
//bool ticTacToe::checkWinConditions() //Check if all the conditions match for player to win
bool ticTacToe::checkRightLeft(char xo, int row, int col) //Check if the right and left X's or O's match for the player
{
	if (row == 1) //Check row 1 if the column matches all cases of X's or O's
	{
		bool flag = false;
		for (int c = 0; c < 3; c++)
		{
			if (board[row - 1][col - 1] == board[row - 1][c]) //Check each case if column matches player move
			{
				flag = true;
			}
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	if (row == 2) //Check row 2 if the column matches all cases of X's or O's
	{
		bool flag = false;
		for (int c = 0; c < 3; c++)
		{
			if (board[row - 1][col - 1] == board[row - 1][c]) //Check each case if column matches player move
			{
				flag = true;
			}
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	if (row == 3) //Check row 3 if the column matches all cases of X's or O's
	{
		bool flag = false;
		for (int c = 0; c < 3; c++)
		{
			if (board[row - 1][col - 1] == board[row - 1][c]) //Check each case if column matches player move
			{
				flag = true;
			}
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	else
		return false;
}
bool ticTacToe::checkUpDown(char xo, int row, int col) //Check if the up and down X's or O's match for the player
{
	if (col == 1) //Check column 1 if the row matches all cases of X's or O's
	{
		bool flag = false;
		for (int r = 0; r < 3; r++)
		{
			if (board[row - 1][col - 1] == board[r][col - 1]) //Check each case if row matches player move
				flag = true;
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	if (col == 2) //Check column 2 if the row matches all cases of X's or O's
	{
		bool flag = false;
		for (int r = 0; r < 3; r++)
		{
			if (board[row - 1][col - 1] == board[r][col - 1]) //Check each case if row matches player move
				flag = true;
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	if (col == 3) //Check column 3 if the row matches all cases of X's or O's
	{
		bool flag = false;
		for (int r = 0; r < 3; r++)
		{
			if (board[row - 1][col - 1] == board[r][col - 1]) //Check each case if row matches player move
				flag = true;
			else //Return false if row and column do not match
				return false;
		}
		if (flag == true) //If all left and right match then return true otherwise false
			return true;
		else
			return false;
	}
	else
		return false;
}
bool ticTacToe::checkDiagonals(char xo, int row, int col) //Check if the diagonal X's or O's match for the player
{
	if (row == col)
	{
		bool flag = false;
		for (int j = 0; j < 3; j++)
		{
			if (board[row - 1][col - 1] == board[j][j]) //set flag to true if diagonals match
				flag = true;
			else //Return false if diagonals do not match
				return false;
		}
		if (flag == true) //If all diagonals match then return true otherwise false
			return true;
		else
			return false;

	}
	else if ((row == 3) && (col == 1))
	{
		if ((board[row - 1][col - 1] == board[2 - 1][2 - 1]) && (board[row - 1][col - 1] == board[1 - 1][3 - 1])) //check if the two other diagonals match (offset by 1 for array)
			return true;
		else
			return false;
	}
	else if ((row == 1) && (col == 3))
	{
		if ((board[row - 1][col - 1] == board[2 - 1][2 - 1]) && (board[row - 1][col - 1] == board[3 - 1][1 - 1])) //check if the two other diagonals match (offset by 1 for array)
			return true;
		else
			return false;
	}
	else
		return false;
}

status ticTacToe::gameStatus(char xo, int row, int col) //To determine the current status of the game
{
	if (checkUpDown(xo, row, col) || checkDiagonals(xo, row, col) || checkRightLeft(xo, row, col)) //Check each condition for player to win
	{
		char restartChoice;
		displayBoard();
		cout << "Player " << xo << " has won the game!";
		do
		{
			cout << "\nWould you like to restart the game(Y/N): ";
			cin >> restartChoice;
			restartChoice = toupper(restartChoice);
		} while ((restartChoice != 'Y') && (restartChoice != 'N'));
		if (restartChoice == 'Y')
		{
			cout << "\nRestarting the game.\n\n\n\n\n";
			reStart();
		}
		return WIN;
	}
	else if (noOfMoves == 9)
	{
		char restartChoice;
		displayBoard();
		cout << "This game is a draw!";
		do
		{
			cout << "\nWould you like to restart the game(Y/N): ";
			cin >> restartChoice;
			restartChoice = toupper(restartChoice);
		} while ((restartChoice != 'Y') && (restartChoice != 'N'));
		if (restartChoice == 'Y')
		{
			cout << "\nRestarting the game.\n\n\n\n\n";
			reStart();
		}
		return DRAW;
	}
	else
		return CONTINUE;
}

void ticTacToe::reStart() //To restart the game
{
	player = X; //Game starts with X
	noOfMoves = 0; //Reset moves
	for (int r = 0; r < 3; r++)
	{
		for (int k = 0; k < 3; k++)
		{
			board[r][k] = ' '; //Set each board piece to blank
		}
	}
	play();
}

ticTacToe::ticTacToe() //Postcondition: Initializes the board to an empty state.
{
	player = X; //Game starts with X
	noOfMoves = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int k = 0; k < 3; k++)
		{
			board[r][k] = ' '; //Set each board piece to blank
		}
	}
}