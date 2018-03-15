#include "piece.h"
#include "board.h"

Piece::Piece(int inity, int initx, bool myalignment) {	
	posx = initx;
	posy = inity;
	alignment = myalignment;
	if (initx == thronePos) {
		isKing = true;
	} else { 
		isKing = false;
	}
}

bool Piece::is_king() {
	return isKing;
}

bool Piece::get_alignment() {
	return alignment;
}

void Piece::move_piece(int endx, int endy) {
	posx = endx;
	posy = endy;
}

