#include "OthelloBoard.h"
#include "GameBoard.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

OthelloBoard::OthelloBoard() : GameBoard() { // 10 LINES
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (row == 3 && col == 3 || row == 4 && col == 4) {
				mBoard[row][col] = -1;
			}
			else if (row == 3 && col == 4 || row == 4 && col == 3) {
				mBoard[row][col] = 1;
			}
			else {
				mBoard[row][col] = 0;
			}

		}
	}
}

void OthelloBoard::ApplyMove(GameMove* other) { // 35 LINES
	OthelloMove* move = (OthelloMove*)other;
	if (mNextPlayer == OthelloBoard::Player::BLACK) {
		mBoard[move->mRow][move->mCol] = 1;
		mValue += 1;
	}
	if (mNextPlayer == OthelloBoard::Player::WHITE) {
		mBoard[move->mRow][move->mCol] = -1;
		mValue -= 1;
	}
	if (move->mRow == -1 && move->mCol == -1) {
		mPassCount++;
	}
	else {
		mPassCount = 0;
	}
	char defender = mNextPlayer * -1;
	for (int r = -1; r <= 1; r++) {
		for (int c = -1; c <= 1; c++) {
			char eCount = 0;
			int updatedRow = move->mRow;
			int updatedCol = move->mCol;
			updatedRow += r;
			updatedCol += c;
			while (mBoard[updatedRow][updatedCol] == defender) {
				eCount++;
				updatedRow += r;
				updatedCol += c;
			}
			if (mBoard[updatedRow][updatedCol] == mNextPlayer) {
				if (eCount > 0) {
					move->AddFlipSet(OthelloMove::FlipSet(eCount, r, c));

					for (int i = 0; i < eCount; i++) {
						updatedRow -= r;
						updatedCol -= c;
						mBoard[updatedRow][updatedCol] = mNextPlayer;
						if (mNextPlayer == OthelloBoard::Player::BLACK) {
							mValue += 2;
						}
						else {
							mValue -= 2;
						}
					}
				}
			}
		}
	}
	mHistory.push_back(move);
	mNextPlayer = defender;
}

void OthelloBoard::GetPossibleMoves(std::vector<GameMove *> *list) const {
	char defender = -mNextPlayer;
	bool switchy = false;
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			bool broke = false;
			if (mBoard[row][col] == 0) {
				for (int r = -1; r <= 1; r++) {
					for (int c = -1; c <= 1; c++) {
						char eCount = 0;
						int updatedRow = row;
						int updatedCol = col;
						updatedRow += r;
						updatedCol += c;
						while (mBoard[updatedRow][updatedCol] == defender) {
							eCount++;
							updatedRow += r;
							updatedCol += c;
						}
						if (mBoard[updatedRow][updatedCol] == mNextPlayer) {
							bool yes = true;
							if (eCount > 0) {
								list->push_back(new OthelloMove(row, col));
								switchy = true;
								broke = true;
								break;
							}
						}
					}
					if (broke) {
						break;
					}
				}
			}
		}
	}
	if (!switchy) {
		list->push_back(new OthelloMove());
	}
}

void OthelloBoard::UndoLastMove() { // 21 LINES
	OthelloMove *move = (OthelloMove*)mHistory.back();
	char lastPlayer = -mNextPlayer;
	mBoard[move->mRow][move->mCol] = 0;
	(mNextPlayer == OthelloBoard::Player::BLACK) ? mValue += 1 : mValue -= 1;

	for (vector<OthelloMove::FlipSet>::iterator itr = move->mFlips.begin(); itr != move->mFlips.end(); itr++) {
		OthelloMove::FlipSet flip = *itr;
		char eCount = flip.switched;
		int updatedRow = move->mRow;
		int updatedCol = move->mCol;
		updatedRow += flip.rowDelta;
		updatedCol += flip.colDelta;
		while (eCount > 0) {
			if (mBoard[updatedRow][updatedCol] == 1) {
				mValue -= 2;
			}
			else {
				mValue += 2;
			}
			mBoard[updatedRow][updatedCol] = -lastPlayer;
			eCount--;
		}
	}
	mHistory.pop_back();
	delete move;
	mNextPlayer = lastPlayer;
}


