#include "OthelloMove.h"
#include "OthelloBoard.h"
#include "GameExceptions.h"
#include "GameMove.h"

#include <string>
#include <sstream>

using namespace std;

//int OthelloMove::mOutstanding = 0;

OthelloMove::OthelloMove() : mRow(-1), mCol(-1) {}
OthelloMove::OthelloMove(int row, int col) : mRow(row), mCol(col) {}
OthelloMove::OthelloMove(const OthelloMove &other) : mRow(other.mRow), mCol(other.mCol) {}
OthelloMove& OthelloMove::operator=(const OthelloMove &other) {
	if (*this == other) {
	   return *this;
	}

	mRow = other.mRow;
	mCol = other.mCol;
	return *this;
}
GameMove& OthelloMove::operator=(const std::string &other) { // 11 LINES
   if (other == "pass") {
      mRow = -1;
      mCol = -1;
      return *this;
   }
   else {
      istringstream stream(other);
      char temp;
      stream >> temp >> mRow >> temp >> mCol >> temp;
		if (mRow >= BOARD_SIZE && mCol >= BOARD_SIZE || mRow < 0 && mCol < 0) {
			throw OthelloException("Move is not in-bounds!");
		}
		return *this;
   }
}
OthelloMove::operator string() const { // 5 LINES
	ostringstream format;
	(mRow != -1 && mCol != -1) ? format << "(" << mRow << ", " << mCol << ")" : format << "PASS";
	return format.str();
}

bool OthelloMove::Equals(const GameMove &other) const {
	OthelloMove &casted = (OthelloMove&)other;
	if (this->mRow == casted.mRow && this->mCol == casted.mCol) {
		return true;
	}
	return false;
}



