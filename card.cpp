#include "card.h"
#include <iostream>
using namespace std;

//All cards should be here or they cannot be played
string cardList[numCards] = {"mantis", "ox", "goose", "eel", "crane", "cobra", "rooster", "elephant", "crab", "monkey", "rabbit", "tiger", "frog", "horse", "boar", "dragon"};

Card::Card(std::string cardName) {
	name = cardName;
	vector <Pos> cardMoves;

	//All card options are here, add any custom cards here
	if (cardName == "rabbit") {
		color = blue;
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(0,2));
	} else if (cardName == "dragon") {
		color = red;
		cardMoves.push_back(Pos(-1,-2));
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(1,1));
		cardMoves.push_back(Pos(-1,2));
	} else if (cardName == "frog") {
		color = red;
		cardMoves.push_back(Pos(0,-2));
		cardMoves.push_back(Pos(-1,-1));
		cardMoves.push_back(Pos(1,1));
	} else if (cardName == "crab") {
		color = blue;
		cardMoves.push_back(Pos(0,-2));	
		cardMoves.push_back(Pos(-1,0));
		cardMoves.push_back(Pos(0,2));
	} else if (cardName == "elephant") {
		color = red;
		cardMoves.push_back(Pos(-1,-1));	
		cardMoves.push_back(Pos(0,-1));
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(0,1));
	} else if (cardName == "goose") {
		color = blue;
		cardMoves.push_back(Pos(-1,-1));	
		cardMoves.push_back(Pos(0,-1));
		cardMoves.push_back(Pos(0,1));
		cardMoves.push_back(Pos(1,1));
	} else if (cardName == "rooster") {
		color = red;
		cardMoves.push_back(Pos(0,-1));	
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(0,1));
	} else if (cardName == "monkey") {
		color = blue;
		cardMoves.push_back(Pos(-1,-1));	
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(1,1));
	} else if (cardName == "mantis") {
		color = red;
		cardMoves.push_back(Pos(-1,-1));	
		cardMoves.push_back(Pos(1,0));
		cardMoves.push_back(Pos(-1,1));
	} else if (cardName == "horse") {
		color = red;
		cardMoves.push_back(Pos(0,-1));	
		cardMoves.push_back(Pos(-1,0));
		cardMoves.push_back(Pos(1,0));
	} else if (cardName == "ox") {
		color = blue;
		cardMoves.push_back(Pos(-1,0));	
		cardMoves.push_back(Pos(1,0));
		cardMoves.push_back(Pos(0,1));
	} else if (cardName == "crane") {
		color = blue;
		cardMoves.push_back(Pos(1,-1));	
		cardMoves.push_back(Pos(-1,0));
		cardMoves.push_back(Pos(1,1));
	} else if (cardName == "boar") {
		color = red;
		cardMoves.push_back(Pos(0,-1));	
		cardMoves.push_back(Pos(-1,0));
		cardMoves.push_back(Pos(0,1));
	} else if (cardName == "eel") {
		color = blue;
		cardMoves.push_back(Pos(-1,-1));	
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(0,1));
	} else if (cardName == "cobra") {
		color = red;
		cardMoves.push_back(Pos(0,-1));	
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(1,1));
	} else if (cardName == "tiger") {
		color = blue;
		cardMoves.push_back(Pos(-2,0));	
		cardMoves.push_back(Pos(1,0));
	} else {
		cout << "card of selected name not found" << endl;
	}
	availableMoves = cardMoves;
}

vector<Pos> Card::getAvailableMoves() {
	return availableMoves;
}

string Card::getName() {
	return name;
}

bool Card::getColor() {
	return color;
}
