#include <iostream>
#include "board.h"

//Just for testing right now, will be made to streamline the process later

using namespace std;

void printBoard(Board *theBoard) {
	for (int i=0;i<5;++i) {
		for (int j=0;j<5;++j) {
			cout << theBoard->get_tile_object(i,j);
		}
		cout << endl;
	}	
}

int main() {
	Board *theBoard = Board::getInstance();
	printBoard(theBoard);
	theBoard->move_piece(0,0,1,3);
	Board *secondBoard = Board::getInstance();
	printBoard(theBoard);
	printBoard(secondBoard);
}
