#ifndef __BOARD_H__
#define __BOARD_H__
//#include "tile.h"
#include <vector>

const int boardHeight = 5;
const int boardWidth = 5;
const int thronePos = 2;

enum TileObject {empty, redPawn, redKing, bluePawn, blueKing};

class Board {
 	static Board *_instance;
	Board();
	Board(Board const&);
	void operator=(Board const&);

	TileObject tiles[boardHeight][boardWidth]; //change this, eventually
	

	public:	
	static Board *getInstance() {
		if (_instance == 0) {
			_instance = new Board();
		}
		return _instance;
	}

	void move_piece(int initRow, int initCol, int endRow, int endCol);
	TileObject get_tile_object(int row, int col);	
};


#endif
