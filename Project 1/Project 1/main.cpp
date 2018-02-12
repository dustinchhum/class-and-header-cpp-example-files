/* CECS 282-01 T/TH 8:00 - 10:15 Project 1
*	Dustin Chhum 011009178
*/
#include <iostream>;
#include <string>;

using namespace std;

#include "OthelloGame.h";

int main(int argc, char* argv[]) { // 38 LINES
	char player;
	int repeat = 0;
	int row, col;
	int passCondition = 0;
   string mainPlayer;
   char gameBoard[BOARD_SIZE][BOARD_SIZE] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, 
      { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0,-1, 1, 0, 0, 0 },
      { 0, 0, 0, 1,-1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }
   };
   cout << "Wecome to Othello!" << endl;
	while (repeat < END_OF_GAME) {
      if (repeat % 2 == 1) {
         player = NEG_ONE;
         mainPlayer = "White";
      }
      if (repeat % 2 == 0) {
         player = 1;
         mainPlayer = "Black";
      }
      cout << " \n" << endl;
      PrintBoard(gameBoard);
      cout << mainPlayer << "'s turn: Please choose a move: " << endl;
      GetMove(&row, &col);
		while (!IsValidMove(gameBoard, row, col)) {
         cout << "Invalid move. Please choose a move:" << endl;
         cout << mainPlayer << "'s turn: ";
         GetMove(&row, &col);
      }
		(row == NEG_ONE && col == NEG_ONE) ? passCondition++ : passCondition = 0;
		ApplyMove(gameBoard, row, col, player);
		repeat++;
		if (passCondition == 2) {
			break;
		}
	} 

	if (GetValue(gameBoard) == 0) {
		cout << "Game over. We have a tie!" << endl;
	}
	else if (GetValue(gameBoard) < 0) {
		cout << "Game over. White is the winner!" << endl;
	}
	else {
		cout << "Game over. Black is the winner!" << endl;
	}
}