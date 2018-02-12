#ifndef __TICTACTOEVIEW_H
#define __TICTACTOEVIEW_H
#include "TicTacToeBoard.h"
#include "GameView.h"
#include <iostream>
class TicTacToeView : public GameView {
private:
	TicTacToeBoard *mTicTacToeBoard;
	virtual void PrintBoard(std::ostream &s) const;

public:
	TicTacToeView(GameBoard *b) : mTicTacToeBoard((TicTacToeBoard*)b) {}
};
#endif