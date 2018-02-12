#include "TicTacToeView.h"
#include "GameView.h"

using namespace std;

void TicTacToeView::PrintBoard(std::ostream &s) const{
	s << "- " << "0 " << "1 " << "2 " << endl;
	for (int row = 0; row < BOARD_SIZE_; row++) {
		cout << row << " ";
		for (int col = 0; col < BOARD_SIZE_; col++) {
			if (mTicTacToeBoard->mBoard[row][col] == 0) {
				s << '.' << " ";
			}
			if (mTicTacToeBoard->mBoard[row][col] == 1) {
				s << 'X' << " ";
			}
			if (mTicTacToeBoard->mBoard[row][col] == -1) {
				s << 'O' << " ";
			}
		}
		s << " " << endl;
	}
	s << endl;
}