#ifndef __BOARD_H__
#define __BOARD_H__
//#include "tile.h"
#include <vector>

const int boardHeight = 5;
const int boardWidth = 5;
const int thronePos = 2;

enum TileObject {empty, redPawn, redKing, bluePawn, blueKing};

class Board {
		TileObject tiles[boardHeight][boardWidth]; //change this, eventually
	public:
		void move_piece(int initRow, int initCol, int endRow, int endCol);

		TileObject get_tile_object(int row, int col);	
//		static Board* getInstance;
		~Board();
		Board();
};


#endif
