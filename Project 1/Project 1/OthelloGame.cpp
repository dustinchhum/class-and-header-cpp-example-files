/* CECS 282-01 T/TH 8:00 - 10:15 Project 1
*	Dustin Chhum 011009178
*/
#include <iostream>;

using namespace std;

#include "OthelloGame.h";

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) { // 12 LINES
	cout << "- " << "0 " << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 "
		<< endl;
	for (int row = 0; row < BOARD_SIZE; row++) {
		cout << row << " ";
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == 1) {
            cout << 'B' << " ";
         }
         if (board[row][col] == -1) {
            cout << 'W' << " ";
         }
         if (board[row][col] == 0) {
            cout << '.' << " ";
         }
      }
		cout << " " << endl;
   }
}

void GetMove(int *row, int *col) { // 2 LINES
   char comma, front, back;
   cin >> front >> *row >> comma >> *col >> back;
}

bool InBounds(int row, int col) { // 1 LINE
	return row >= 0 && row <= 7 && col >= 0 && col <= 7 ? true : false;
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) { // 2 LINES
	return InBounds(row, col) && board[row][col] == 0 
	 || row == -1 && col == -1 ? true : false;
}

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, // 19 LINES
 char player) {
	player == 1 ? board[row][col] = 1 : board[row][col] = -1;
	char defender = player * -1; 

	for (int r = -1; r <= 1; r++) {
		for (int c = -1; c <= 1; c++) {
			int eCount = 0;
			int updatedRow = row;
			int updatedCol = col;
			updatedRow += r;
			updatedCol += c;
			while (board[updatedRow][updatedCol] == defender) {
				eCount++;
				updatedRow += r;
				updatedCol += c;
			}
			if (board[updatedRow][updatedCol] == player) {
				for (int i = 0; i < eCount; i++) {
					updatedRow -= r;
					updatedCol -= c;
					board[updatedRow][updatedCol] = player;
				}
			}
		}		
	}
}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) { // 5 LINES!
	int value = 0;
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			value += board[row][col];
		}
	}
	return value;
}