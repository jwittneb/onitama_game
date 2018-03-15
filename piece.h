#ifndef __PIECE_H__
#define __PIECE_H__
#include "board.h"

Class Piece {
	int posx;
	int posy;
	bool isKing;	
	Board *theBoard;

	public:
	//move should take in a cord+movement
	void move_piece(int xchange, int ychange);
	bool is_king();
	Piece(int initx, int inity);
	~Piece()
}
#endif
