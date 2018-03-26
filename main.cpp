#include <iostream>
#include "board.h"
#include "card.h"
#include <vector>
#include "action.h"
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;

//Returns true if and only if the vector contains the element requested
bool vectorContains(vector<int>& myvec, int elem) {
	for (vector<int>::iterator i=myvec.begin(); i != myvec.end(); ++i) {
		if (*i == elem) {
			return true;
		}
	}
	return false;
}

//Initializes the set of cards that will be in play for randomly, later allow selection
void initializeCards(vector<Card>& blueCards, vector<Card>& redCards, Card *&nextCard) {
	srand(time(0));
	vector<int> cardsInPlay;
	//Could make this more efficient, but likely wont be a problem ever
	
	//While we still need to add cards to the game
	while (cardsInPlay.size() < cardsPerGame) {
		//generate a random number, corresponding to a card
		int nextCard = rand() % numCards;

		//make sure that the card is not already selected, to avoid duplicates
		if (!vectorContains(cardsInPlay,nextCard)) {
		//the card is not a duplicate, add to the set of cards in play
			cardsInPlay.push_back(nextCard);
		}
	}	
	//At this point, the cards in play are just integers, they need to be converted to actual card
	//classes, but the Card constructor handles this

	string tempCard;
	for (int i=0; i < cardsPerGame/2; ++i) {
		tempCard = cardList[cardsInPlay[i]]; 
		blueCards.push_back(Card(tempCard));
		tempCard = cardList[cardsInPlay[cardsPerGame/2 + i]];
		redCards.push_back(Card(tempCard));
	}
	//At this point, all the blue and red cards are set up as the first half of the random cards and
	//second half, respectively. The only remaining card is the last card, which is the spare card

	tempCard = cardList[cardsInPlay[cardsPerGame-1]];
	nextCard = new Card(tempCard);
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

	for (int i=0;i<2;++i) {
		cout << blueCards[i].getName() << endl;
		cout << redCards[i].getName() << endl;
	}
	cout << nextCard->getName() << endl;
	//Find out who is playing first based on the spare card

	//Main game loop
//	while (true) {
		//get the current player's action
//		Action nextAction = getAction(currPlayer);
		
		//execute the action requested, check if win condition achieved by the current player
//		win = executeAction(nextAction,currPlayer);
//		if (win) {
//			break;
//		}
		
		//game has not yet ended
		//swap who the current player is
//		if (currPlayer == blue) {
//			currPlayer = red;
//		} else {
//			currPlayer = blue;
//		}
//	}
	
//	declare_win(currPlayer);
}
