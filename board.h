#ifndef __BOARD_H__
#define __BOARD_H__
//#include "tile.h"
#include <vector>
#include "piece.h"

const int boardHeight = 5;
const int boardWidth = 5;
const int thronePos = 2;

class Board {
 	static Board *_instance;
	Board();
	Board(Board const&);
	void operator=(Board const&);

	Piece *tiles[boardHeight][boardWidth]; 
	Piece *redPieces[boardWidth];
	Piece *bluePieces[boardWidth];

	public:	
	static Board *getInstance() {
		if (_instance == 0) {
			_instance = new Board();
		}
		return _instance;
	}

	void move_piece(int initRow, int initCol, int endRow, int endCol);
	Piece *get_tile_object(int row, int col);	
	void print_board();
};


#endif
