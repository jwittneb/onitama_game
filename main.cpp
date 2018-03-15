#include <iostream>
#include "board.h"

//Just for testing right now, will be made to streamline the process later


int main() {
	Board *theBoard = Board::getInstance();
	theBoard->print_board();
	theBoard->move_piece(0,0,1,3);
	Board *secondBoard = Board::getInstance();
	theBoard->print_board();
	secondBoard->print_board();
}
