/* CECS 282-01 T/TH 8:00 - 10:15 Project 1
*	Dustin Chhum 011009178
*/
const int BOARD_SIZE = 8;
const char NEG_ONE = -1;
const int END_OF_GAME = 62;

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]);

void GetMove(int *row, int *col);

bool InBounds(int row, int col);

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player);

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]);