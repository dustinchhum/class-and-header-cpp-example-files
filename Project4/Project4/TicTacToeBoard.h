#ifndef __TICTACTOEBOARD_H
#define __TICTACTOEBOARD_H

#include <vector>
#include "TicTacToeMove.h"
#include "GameBoard.h"
#include "GameMove.h"

const int BOARD_SIZE_ = 3;


class TicTacToeBoard : public GameBoard {

public:
	enum Player { EMPTY = 0, BLACK = 1, WHITE = -1 };

	TicTacToeBoard();

	virtual void GetPossibleMoves(std::vector<GameMove *> *list) const;

	virtual void ApplyMove(GameMove *move);

	virtual void UndoLastMove();

	virtual GameMove *CreateMove() const { return new TicTacToeMove; }

	inline static bool InBounds(int row, int col) { return row >= 0 && row < BOARD_SIZE_ && col >= 0 && col < BOARD_SIZE_; }

	bool IsWinner() const;

	virtual bool IsFinished() const {
		char END_GAME = 9;
		if (mHistory.size() == END_GAME) {
			return true;
		}
		else {
			return IsWinner();
		}
	}

	virtual std::string GetPlayerString(char player) {
		return (player == 1 ? "X" : "O");
	}

private:
	friend class TicTacToeView;

	char mBoard[BOARD_SIZE_][BOARD_SIZE_];
	static char mWeights[BOARD_SIZE_][BOARD_SIZE_];
	int mPassCount;
};
#endif