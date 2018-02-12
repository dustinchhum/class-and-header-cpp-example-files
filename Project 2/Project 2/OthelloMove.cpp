#include "OthelloMove.h"

#include <string>
#include <sstream>

using namespace std;

OthelloMove::OthelloMove() : mRow(-1), mCol(-1) {}
OthelloMove::OthelloMove(int row, int col) : mRow(row), mCol(col) {}
OthelloMove::OthelloMove(const OthelloMove &other){
	mRow = other.mRow;
	mCol = other.mCol;
}
OthelloMove& OthelloMove::operator=(const OthelloMove &other) {
	if (*this == other) {
	   return *this;
	}

	mRow = other.mRow;
	mCol = other.mCol;
	return *this;
}
OthelloMove& OthelloMove::operator=(const std::string &other) {
	istringstream stream(other);
	char temp;
	stream >> temp >> mRow >> temp >> mCol >> temp;
	return *this;
}
OthelloMove::operator string() const {
	ostringstream format;
	if (mRow != -1 && mCol != -1) {
		format << "(" << mRow << ", " << mCol << ")";
	}
	else {
		format << "PASS";
	}
	return format.str();
}
bool operator==(const OthelloMove &lhs, const OthelloMove &rhs) {
	if (lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol) {
		return true;
	}



