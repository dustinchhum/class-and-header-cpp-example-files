#include "TicTacToeMove.h"
#include "TicTacToeBoard.h"
#include "GameExceptions.h"
#include "GameMove.h"

#include <string>
#include <sstream>

using namespace std;

TicTacToeMove::TicTacToeMove() : mRow(-1), mCol(-1) {}
TicTacToeMove::TicTacToeMove(int row, int col) : mRow(row), mCol(col) {}
TicTacToeMove::TicTacToeMove(const TicTacToeMove &other) : mRow(other.mRow), mCol(other.mCol) {}
TicTacToeMove& TicTacToeMove::operator=(const TicTacToeMove &other) {
	if (*this == other) {
		return *this;
	}

	mRow = other.mRow;
	mCol = other.mCol;
	return *this;
}
GameMove& TicTacToeMove::operator=(const std::string &other) { // 11 LINES
	if (other == "pass") {
		mRow = -1;
		mCol = -1;
		return *this;
	}
	else {
		istringstream stream(other);
		char temp;
		stream >> temp >> mRow >> temp >> mCol >> temp;
		if (mRow >= BOARD_SIZE_ && mCol >= BOARD_SIZE_ || mRow < 0 && mCol < 0) {
			throw TicTacToeException("Move is not in-bounds!");
		}
		return *this;
	}
}
TicTacToeMove::operator string() const { // 5 LINES
	ostringstream format;
	(mRow != -1 && mCol != -1) ? format << "(" << mRow << ", " << mCol << ")" : format << "PASS";
	return format.str();
}

bool TicTacToeMove::Equals(const GameMove &other) const {
	TicTacToeMove &casted = (TicTacToeMove&)other;
	if (this->mRow == casted.mRow && this->mCol == casted.mCol) {
		return true;
	}
	return false;
}