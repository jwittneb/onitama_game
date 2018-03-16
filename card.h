#ifndef __CARD_H__
#define __CARD_H__
#include "enums.h"
#include <string>
#include <vector>
using namespace std;

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
