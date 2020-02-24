#include <string>

using namespace std;
enum status { WIN, DRAW, CONTINUE };
enum player {X, O};

class ticTacToe
{
public:
	void play(); //To start the play
	
	void displayBoard() const; //To print the board
	
	bool isValidMove(int x, int y) const; //To determine if a move is valid
	
	void getXOMove(char moveSymbol); //To get a move for the next player

	status gameStatus(char xo, int row, int col); //To determine the current status of the game
	
	bool checkDiagonals(char xo, int row, int col); //Check if the diagonal X's or O's match for the player

	bool checkRightLeft(char xo, int row, int col); //Check if the up and down X's or O's match for the player
	
	bool checkUpDown(char xo, int row, int col); //Check if the up and down X's or O's match for the player
	
	void reStart(); //To restart the game
	
	ticTacToe(); //Postcondition: Initializes the board to an empty state.

private:
	char board[3][3];
	int noOfMoves;
	int player;

};

