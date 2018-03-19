#include <iostream>
#include "board.h"
#include "card.h"
#include <vector>
#include "action.h"
#include <time.h>

using namespace std;

void initializeCards(vector<Card>& blueCards, vector<Card>& redCards, Card *&nextCard) {
	srand(time(NULL));
	int cardInPlay = 
}

int main() {
	int currPlayer;
	bool win = false;

	Board *theBoard = Board::getInstance();
	//The board is now in position to start the game
	//Maybe make this NOT singleton so that players cant get it on their turn and use move_piece
	//arbitrarily

	vector<Card> blueCards;
	vector<Card> redCards;
	Card *nextCard;

	initializeCards(blueCards,redCards,nextCard);
	//Get the set of cards which will be used during this game, change to allow card selection
	
	if (nextCard->getColor() == red) {
		currPlayer = red;
	} else {
		currPlayer = blue;
	}
	//Find out who is playing first based on the spare card

	//Main game loop
	while (true) {
		//get the current player's action
		Action nextAction = getAction(currPlayer);
		
		//execute the action requested, check if win condition achieved by the current player
		win = executeAction(nextAction,currPlayer);
		if (win) {
			break;
		}
		
		//game has not yet ended
		//swap who the current player is
		if (currPlayer == blue) {
			currPlayer = red;
		} else {
			currPlayer = blue;
		}
	}
	
	declare_win(currPlayer);
}
