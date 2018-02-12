#include "OthelloExceptions.h"
#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {
   // Initialization
   OthelloBoard board; // the state of the game board
   OthelloView v(&board); // a View for outputting the board via operator<<
   string userInput; // a string to hold the user's command choice
   vector<OthelloMove *> possMoves; // a holder for possible moves

   // Main loop
   do {
	   // Print the game board using the OthelloView object

      // Print all possible moves

      // Ask to input a command

      // Command loop:
         // move (r,c)
         // undo n
         // showValue
         // showHistory
         // quit
      
   } while (!board.IsFinished()); 
}