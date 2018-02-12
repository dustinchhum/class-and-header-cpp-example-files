const int GAMEBOARD_SIZE = 3;
int *ptrToRow;
int *ptrToCol;

void PrintBoard(char board[GAMEBOARD_SIZE][GAMEBOARD_SIZE]) {
	char newBoard[GAMEBOARD_SIZE][GAMEBOARD_SIZE] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};		
	for (int row = 0; row < GAMEBOARD_SIZE; row++) {
		for (int col = 0; col < GAMEBOARD_SIZE; col++) {
			if (board[row][col] == 1) {
				newBoard[row][col] = 'X';
			}
			if (board[row][col] == -1) {
				newBoard[row][col] = 'O';
			}
			if (board[row][col] == 0) {
				newBoard[row][col] = '.';
			}
		}
	}
	
   cout << "- " << "0 " << "1 " << "2 " << endl;
   cout << "0 " << newBoard[0][0] << " " << newBoard[0][1] << " " << 
	 newBoard[0][2] << " " << endl;
   cout << "1 " << newBoard[1][0] << " " << newBoard[1][1] << " " << 
	 newBoard[1][2] << " " << endl;
	cout << "2 " << newBoard[2][0] << " " << newBoard[2][1] << " " << 
	 newBoard[2][2] << " " << endl;
}

void GetMove(int *row, int *col) {
	char comma = 'a';
	cin >> *row >> comma >> *col;
}

bool MoveIsValid(char board[GAMEBOARD_SIZE][GAMEBOARD_SIZE], int row, int col) {
	if (board[row][col] == 0) {
		return true;
	}
	else {
		return false;
	}
}
