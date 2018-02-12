#include "GameExceptions.h"
#include "GameBoard.h"
#include "GameMove.h"
#include "GameView.h"
#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include "TicTacToeBoard.h"
#include "TicTacToeMove.h"
#include "TicTacToeView.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cout << "Do you want to play Othello or TicTacToe?" << endl;
	cout << "Enter: 1) Othello, Any Key) Tic-Tac-Toe" << endl;
	cin >> s;
	GameBoard *board;
	GameView *v;
	if (s == "1") {
		board = new OthelloBoard();
		v = new OthelloView(board);
	}
	else {
		board = new TicTacToeBoard();
		v = new TicTacToeView(board);
	}
	getline(cin, s);
	string input;
	vector<GameMove *> possMoves; 
	do {
		cout << *v;
		board->GetPossibleMoves(&possMoves);
		for (vector<GameMove *>::iterator itr = possMoves.begin(); itr != possMoves.end(); itr++) {
			cout << (string)**itr << " ";
			delete *itr;
		}
		cout << endl;
		possMoves.clear();
		char playerOne = board->GetNextPlayer();
		string player = board->GetPlayerString(playerOne);
		cout << player << ", make a move?" << endl;
		getline(cin, input);
		if (input.find("move") == 0) {
			GameMove *move = board->CreateMove();
			try {
				*move = input.substr(5);
				board->GetPossibleMoves(&possMoves);
            bool useAgain = false;
            for (vector<GameMove*>::iterator itr = possMoves.begin(); itr != possMoves.end(); itr++) {
					if (**itr == *move && !useAgain) {
                  useAgain = true;
					}
               delete *itr;
				}
				possMoves.clear();
            if (useAgain) {
               board->ApplyMove(move);
            }
				else {
					delete move;
				}
			}
			catch (GameException& e) {
				cout << endl;
				cout << e.GetMessage() << endl;
				cout << endl;
            delete move;
			}
		}
		if (input.find("undo") == 0) {
			vector<GameMove *> history = *board->GetMoveHistory();
			string s = input.substr(5);
			istringstream stream(s);
			int sizeOfHistory = 0;
			int numUndos = 0;
			stream >> numUndos;
			for (vector<GameMove*>::iterator itr = history.begin(); itr != history.end(); itr++) {
				sizeOfHistory++;
			}
			for (int i = 0; i < numUndos; i++) {
				if (sizeOfHistory == 0) {
					break;
				}
				board->UndoLastMove();
			}
		}
		if (input.find("show value") == 0) {
			cout << endl;
			cout << "Value: " << board->GetValue() << endl;
			cout << endl;
		}
		if (input.find("show history") == 0) {
			string person = "";
			char player = playerOne * -1;
			cout << endl;
			for (vector<GameMove* >::const_reverse_iterator itr = board->GetMoveHistory()->rbegin(); 
		    itr != board->GetMoveHistory()->rend(); itr++) {
				person = board->GetPlayerString(player);
				cout << person << " " << (string)**itr << endl;
				player *= -1;
			}
			cout << endl;
		}
		if (input.find("quit") == 0) {
			break;
		}
	} while (!board->IsFinished());
	if (board->GetValue() == 0) {
		cout << "Its a tie!" << endl;
	}
	else {
		cout << board->GetPlayerString(board->GetNextPlayer()) << " wins!";
	}
} 