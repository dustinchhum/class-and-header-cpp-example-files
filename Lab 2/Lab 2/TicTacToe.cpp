/* CECS 282 Lab 2 T/TH 8:00 A.M - 10:15 A.M
   Dustin Chhum 011009178
*/
#include <iostream>;
using namespace std;

#include "TicTacToe.h";
int main(int argc, char* argv[]) {
	const int GAMEBOARD_SIZE = 3;
	const int END_OF_GAME = 9;
	int row = -1;
	int col = -1;
   int *Rpointer = &row;
   int *Cpointer = &col;
	char player = 'X';
	int repeat = 0;
	char gameBoard[GAMEBOARD_SIZE][GAMEBOARD_SIZE] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	do { 
		if (repeat % 2 == 1) {
			player = 'O';
		}
		if (repeat % 2 == 0) {
			player = 'X';
		}
		cout << " " << endl;
		PrintBoard(gameBoard);
		cout << player << "'s turn: ";
		GetMove(&row, &col);
		while (!MoveIsValid(gameBoard, row, col)) {
			cout << "That space is already taken!" << endl;
			cout << player << "'s turn: ";
			GetMove(&row, &col);
		}
		if (player == 'X') {
			gameBoard[row][col] = 1;
		}
		else {
			gameBoard[row][col] = -1;
		}
		repeat++;
	} while (repeat < END_OF_GAME);
}