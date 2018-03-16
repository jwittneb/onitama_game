#include "card.h"
using namespace std;

Card::Card(std::string cardName) {
	name = cardName;
	vector <Pos> cardMoves;


	if (cardName == "rabbit") {
		color = blue;
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(-1,1));
		cardMoves.push_back(Pos(0,2));
	}

	if (cardName == "dragon") {
		color = red;
		cardMoves.push_back(Pos(-1,-2));
		cardMoves.push_back(Pos(1,-1));
		cardMoves.push_back(Pos(1,1));
		cardMoves.push_back(Pos(-1,2));
	}

	availableMoves = cardMoves;
}

vector<Pos> *Card::getAvailableMoves() {
	return &availableMoves;
}

string Card::getName() {
	return name;
}

bool Card::getColor() {
	return color;
}
