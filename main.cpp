#include <iostream>
#include "board.h"
#include "card.h"
#include <vector>
#include "action.h"
#include <time.h>
#include <string>
#include <stdlib.h>
#include "piece.h"
#include <sstream>

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

//outputs true if the action was legal, false otherwise
bool executeAction(Board *theBoard, string nextPiece, string nextAction, int nextActionNum, int currPlayer,
vector<Card> &blueCards, vector<Card> &redCards, Card *nextCard) {
	Card *swap;

	//Figure out which piece the player wants to move
	Piece *toMove = theBoard->getTileObject((int)nextPiece[0],(int)nextPiece[1]);
	cout << "OKAY" << endl;

	//Check to see that the piece belongs to the player who is trying to move it
	if (toMove->getAlignment() != currPlayer) {
		return 0;
	} else {
		for (int i=0; i<2; ++i) {
			cout << "GOOD" << endl;
	//		if (blueCards[i].getName() == nextAction) {
	//			theBoard->movePiece((int)nextPiece[0],(int)nextPiece[1],(blueCards[i].getAvailableMoves())[nextActionNum].x,(blueCards[i].getAvailableMoves())[nextActionNum].y);
	//		} else if (redCards[i].getName() == nextAction) {
	//			theBoard->movePiece((int)nextPiece[0],(int)nextPiece[1],(redCards[i].getAvailableMoves())[nextActionNum].x,(redCards[i].getAvailableMoves())[nextActionNum].y);	
	//		}
		}
	}
}

int main() {
	int currPlayer;
	bool win = false;
	bool legalMove = true;

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
	//Find out who is playing first based on the spare card

	string nextAction;
	string nextPiece;
	int nextActionNum;
	string temp;

	//Main game loop
	while (true) {
		//get the current player's action
		//Action nextAction = getAction(currPlayer);

		theBoard->printBoard();
		cout << "Blue Cards: " << blueCards[0].getName() << "," << blueCards[1].getName() << endl;
		cout << "Red Cards: " << redCards[0].getName() << "," << redCards[1].getName() << endl;
		cout << "Spare Card: " << nextCard->getName() << endl;
		if (currPlayer == blue) {
			cout << "It is blue's turn" << endl;
		} else {
			cout << "It is red's turn" << endl;
		}
		cout << "Piece to Move: ";
		cin >> nextPiece;
		cout << endl;
		cout << "Card to Use: ";
		cin >> nextAction;
		cout << "Action to Use: ";
		cin >> temp;
		cout << endl;
		stringstream ss(temp);
		ss >> nextActionNum;
		
		//execute the action requested, check if win condition achieved by the current player
		legalMove = executeAction(theBoard,nextPiece,nextAction,nextActionNum,currPlayer,blueCards,redCards,nextCard);
	}
//		win = theBoard.checkWin();

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
