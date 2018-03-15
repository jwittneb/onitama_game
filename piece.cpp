#include "piece.h"
#include "board.h"

Piece::Piece(int initx, int inity) {	
	theBoard = Board.getInstance();
	x = initx;
	y = inity;
	if (initx == thronePos) isKing = true;
	else isKing = false;
}

bool Piece::is_king() {
	return isKing;
}

void Piece::move_piece(int endx, int endy) {
	theBoard->move_piece(x,y,endx,endy);
	x = endx;
	y = endy;
}

