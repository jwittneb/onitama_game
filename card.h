#ifndef __CARD_H__
#define __CARD_H__
#include "enums.h"
#include <string>
#include <vector>
using namespace std;

const int numCards = 16;

//Note: this value MUST be odd
const int cardsPerGame = 5;

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
	vector <Pos> getAvailableMoves();
	bool getColor();
};

//Where all the cards will be listed
extern string cardList[numCards];
#endif
