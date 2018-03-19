#ifndef __CARD_H__
#define __CARD_H__
#include "enums.h"
#include <string>
#include <vector>
using namespace std;

int numCards = 16;

//All cards should be here or they cannot be played
Card cardList [numCards] = {"mantis", "ox", "goose", "eel", "crane", "cobra", "rooster", "elephant", "crab", "monkey", "rabbit", "tiger", "frog", "horse", "boar", "dragon"};
	


//make this less terrible some time
struct Pos {
	int x;
	int y;
	Pos(int a, int b) { x=a; y=b;} 
};

class Card {
	string name;
	vector <Pos> availableMoves; 
	bool color;

	public:
	Card(string cardName);
	string getName();
	vector <Pos>* getAvailableMoves();
	bool getColor();
};
#endif
