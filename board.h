#ifndef __BOARD_H__
#define __BOARD_H__
//#include "tile.h"
#include <vector>

enum TileObject {empty, redPawn, redKing, bluePawn, blueKing};

class Board {
		TileObject tiles[5][5]; //change this, eventually
//		Tile tiles[5][5];
	public:
		void move_piece(int init_row, int init_col, int end_row, int end_col);

		TileObject get_tile_object(int row, int col);	
//		static Board* getInstance;
		~Board();
		Board();
};


#endif
