#ifndef __TICTACTOEMOVE_H
#define __TICTACTOEMOVE_H
#include "GameBoard.h"
#include <string>
#include <vector>
#include <iostream>

class TicTacToeMove : public GameMove {
private:
	friend class TicTacToeBoard;
	int mRow, mCol;
	TicTacToeMove();
	TicTacToeMove(int, int);

public:
	virtual ~TicTacToeMove() {}

	TicTacToeMove(const TicTacToeMove &);
	TicTacToeMove& operator=(const TicTacToeMove &rhs);

	virtual bool Equals(const GameMove &other) const;

	virtual GameMove& operator=(const std::string &);

	operator std::string() const;

	inline bool IsPass() const {
		return mRow == -1 && mCol == -1 ? true : false;
	}

	virtual GameMove *Clone() const {
		return new TicTacToeMove(*this);
	}
};
#endif