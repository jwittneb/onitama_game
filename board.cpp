#include "board.h"


//constructor sets up the board to the starting game position
Board::Board() {
	//setting up the blue/red
	for (int i=0; i<boardWidth; ++i) {
		tiles[0][i] = bluePawn;
		tiles[boardHeight-1][i] = redPawn;
	}
	tiles[0][thronePos] = blueKing;
	tiles[boardHeight-1][thronePos] = redKing;
	
	//make sure that the rest of the board is empty
	for (int i=1; i<boardHeight-1; ++i) {
		for (int j=0; j<boardWidth; ++j) {
			tiles[i][j]=empty;
		}
	}
}

TileObject Board::get_tile_object(int row, int col) {
	return tiles[row][col];
}

//Function to move pieces, does not do checking that you are moving your own pieces, which should be
//checked in the player move functions
void Board::move_piece(int initrow, int initcol, int endrow, int endcol) {
	if (tiles[initrow][initcol]==empty) {
		cerr << "Attempting to move from an empty location" << endl;	
	} else {
		tiles[endrow][endcol] = tiles[initrow][initcol];
		tiles[initrow][initcol] = empty;
	}
}
