/*
Lab 1
Dustin Chhum 9178
*/
#include <iostream>;
#include <cstdlib>;
#include <iomanip>;
#include <time.h>;
using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0));
	const int THREE = 3;
	const int FOUR = 4;
	const int PRIZE_MAX = 5;
	char response; // Player response to switch doors
	int newDoor = 0; // Door that is revealed to player
	int otherDoor = 0; // Other door choice that the player can pick
	int playerDoor = 0; //Door that player chooses first
	int winningDoor = 1 + rand() % THREE;
	int randomPrize = 1 + rand() % PRIZE_MAX;

	while (playerDoor < 1 || playerDoor > THREE) {
		cout << "Choose a door between 1 - 3!" << endl;
		cin >> playerDoor;
	}

	if (winningDoor == 1) {
		if (playerDoor == 1) {
			newDoor = 2;
			otherDoor = THREE;
		}
		if (playerDoor == 2) {
			newDoor = THREE;
			otherDoor = winningDoor;
		}
		if (playerDoor == THREE) {
			newDoor = 2;
			otherDoor = winningDoor;
		}
	}
   if (winningDoor == 2) {
		if (playerDoor == 1) {
			newDoor = THREE;
			otherDoor = winningDoor;
		}
		if (playerDoor == 2) {
			newDoor = 1;
			otherDoor = THREE;
		}
		if (playerDoor == THREE) {
			newDoor = 1;
			otherDoor = winningDoor;
		}
	}
	if (winningDoor == THREE) {
		if (playerDoor == 1) {
			newDoor = 2;
			otherDoor = winningDoor;
		}
		if (playerDoor == 2) {
			newDoor = 1;
			otherDoor = winningDoor;
		}
		if (playerDoor == THREE) {
			newDoor = 2;
			otherDoor = 1;
		}
	}

	cout << "Okay! Door " << newDoor << " has a goat behind it, " <<
	 "choose the remaning door? (y/n)" << endl;
	cin >> response;
	if (response == 'y') {
		playerDoor = otherDoor;
	}

	if (playerDoor == winningDoor) {
		if (randomPrize == 1) {
			cout << "Congratulations! You won a life-time supply of " <<
			 "college supplies! Er .. It's all we got." << endl;
		}
		if (randomPrize == 2) {
			cout << "Congratulations! You won your own traveling circus! " <<
			 "Animal food is NOT included." << endl;
		}
		if (randomPrize == THREE) {
			cout << "Woo! You won a thousand bitcoins! Wait, just kidding " <<
			 "... we lost them on a hard drive in a landfill." << endl;
		}
		if (randomPrize == FOUR) {
			cout << "Alright! It looks like you won a billion dollars worth of " <<
			 "women's beauty supplies! Who said these prizes were only for guys" <<
	       " huh?" << endl;
		}
		if (randomPrize == PRIZE_MAX) {
			cout << "Congratuations! You've won $20 dollars everyday for the " <<
			 "rest of your life! What? You don't like it? Take these old fitness D"
	       << "VDs then." << endl;
		}
	}
	else {
		cout << "Darn! It looks like you lose. How's it feel to lose, loser?! " <<
		 "Get out of here ... Loser." << endl;
	}
}

/*
No Switch & Win:

Choose a door between 1 - 3!
1
Okay! Door 3 has a goat behind it, choose the remaining door? (y/n)
y
Alright! It looks like you won a billion dollars worth of women's beauty
 supplies! Who said these prizes were only for guys huh?

No Switch & Lose:

Choose a door between 1 - 3!
2
Okay! Door 3 has a goat behind it, choose the remaining door? (y/n)
n
Darn! It looks like you lose. How's it feel to lose, loser?! Get out of here ...
 Loser.

Switch & Win:

Choose a door between 1 - 3!
3
Okay! Door 2 has a goat behind it, choose the remaining door? (y/n)
Congratulations! You won your own traveling circus! Animal food is NOT included.

Switch & Lose:

Choose a door between 1 - 3!
2
Okay! Door 1 has a goat behind it, choose the remaining door? (y/n)
y
Darn! It looks like you lose, How's it feel to lose, loser?! Get out of here ...
Loser.

*/
