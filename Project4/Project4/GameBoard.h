#ifndef __GAMEBOARD_H
#define __GAMEBOARD_H

#include "GameMove.h"
#include <vector>
#include <string>

class GameBoard {
public:
   // Virtual destructors are important for class hierarchies. Add a virtual 
   // destructor to all your classes; the destructor can be empty like this.
   virtual ~GameBoard() {}

   // Initializes a GameBoard with a NextPlayer of 1 and a Value of 0.
   GameBoard() : mNextPlayer(1), mValue(0) {}

   /* 
   Fills a vector with all possible GameMoves that can be applied to this
   board. The moves returned must be deleted by whoever calls the function.
   */
   virtual void GetPossibleMoves(std::vector<GameMove *> *list) const = 0;

   /*
   Applies a given move to the board, updating its game state and history
   accordingly. The board takes ownership of the move pointer given. The 
   GameMove must an appropriate type for this GameBoard.
   */
   virtual void ApplyMove(GameMove *move) = 0;

   /*
   Undoes the last move on the board.
   */
   virtual void UndoLastMove() = 0;

   /*
   Creates an appropriate GameMove-derived object representing a "blank" move
   on this type of board. This object can be assigned to with a string.
   */
   virtual GameMove *CreateMove() const = 0;

   /*
   Returns true if the game board is "finished", e.g., if one player has won
   and no more moves should be allowed.
   */
   virtual bool IsFinished() const = 0;

   /*
   Returns a string representation for the given player value. For most games 
   this should be "Black" or "White", but this can be customized, e.g. for 
   Tic-Tac-Toe.
   */
   virtual std::string GetPlayerString(char player) {
      return (player == 1 ? "Black" : "White");
   }

   inline int GetValue() const {return mValue;}
   inline int GetNextPlayer() const {return mNextPlayer;}

   /*
   Gets a vector of all moves applied to this board. The last move in the vector
   is the most recent move applied to the board.
   */
   inline const std::vector<GameMove *>* GetMoveHistory() const {
      return &mHistory;
   }

   inline int GetMoveCount() const {
      return mHistory.size();
   }

protected:
   char mNextPlayer;
   int mValue;
   std::vector<GameMove *> mHistory;
};

#endif