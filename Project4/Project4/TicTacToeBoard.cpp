#include "TicTacToeBoard.h"
#include "GameBoard.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

TicTacToeBoard::TicTacToeBoard() : GameBoard() {
	for (int row = 0; row < BOARD_SIZE_; row++) {
		for (int col = 0; col < BOARD_SIZE_; col++) {
			mBoard[row][col] = 0;
		}
	}
}

void TicTacToeBoard::ApplyMove(GameMove* other) {
	TicTacToeMove* move = (TicTacToeMove*)other;
	if (mNextPlayer == TicTacToeBoard::Player::BLACK) {
		mBoard[move->mRow][move->mCol] = 1;
		mValue += 1;
	}
	if (mNextPlayer == TicTacToeBoard::Player::WHITE) {
		mBoard[move->mRow][move->mCol] = -1;
		mValue -= 1;
	}
	char defender = mNextPlayer * -1;
	mHistory.push_back(move);
	mNextPlayer = defender;
}

void TicTacToeBoard::GetPossibleMoves(std::vector<GameMove *> *list) const {
	char defender = -mNextPlayer;
	bool switchy = false;
	for (int row = 0; row < BOARD_SIZE_; row++) {
		for (int col = 0; col < BOARD_SIZE_; col++) {
			if (mBoard[row][col] == 0) {
				list->push_back(new TicTacToeMove(row, col));
				switchy = true;
			}
		}
	}
	if (!switchy) {
		list->push_back(new TicTacToeMove());
	}
}

void TicTacToeBoard::UndoLastMove() {
	TicTacToeMove *move = (TicTacToeMove*)mHistory.back();
	char lastPlayer = -mNextPlayer;
	mBoard[move->mRow][move->mCol] = 0;
	(mNextPlayer == TicTacToeBoard::Player::BLACK) ? mValue += 1 : mValue -= 1;
	mHistory.pop_back();
	delete move;
	mNextPlayer = lastPlayer;
}

bool TicTacToeBoard::IsWinner() const {
	TicTacToeMove *move = (TicTacToeMove*)mHistory.back();
	char defender = -mNextPlayer;
	char rRow = move->mRow;
	char cCol = move->mCol;
	char row = 0;
	char col = 0;
	char diag = 0;
	char rDiag = 0;
	const char N = 3;

	for (int i = 0; i < N; i++) {
		if (mBoard[rRow][i] == mNextPlayer) {
			row++;
		}
		if (mBoard[i][cCol] == mNextPlayer) {
			col++;
		}
		if (mBoard[i][i] == mNextPlayer) {
			diag++;
		}
		if (mBoard[i][N - i + 1]) {
			rDiag++;
		}
	}
	bool win;
	if (row == N || col == N || diag == N || rDiag == N) {
		win = true;
	}
	else {
		win = false;
	}
	return win;
}

