#include "OthelloView.h"
#include "GameView.h"

using namespace std;

void OthelloView::PrintBoard(std::ostream &s) const{
   s << "- " << "0 " << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 "
      << endl;
   for (int row = 0; row < BOARD_SIZE; row++) {
      cout << row << " ";
      for (int col = 0; col < BOARD_SIZE; col++) {
         if (mOthelloBoard->mBoard[row][col] == 1) {
            s << 'B' << " ";
         }
         if (mOthelloBoard->mBoard[row][col] == -1) {
            s << 'W' << " ";
         }
         if (mOthelloBoard->mBoard[row][col] == 0) {
            s << '.' << " ";
         }
      }
      s << " " << endl;
   }
	s << endl;
}