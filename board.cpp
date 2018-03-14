#include "board.h"

Board::Board() {
	tiles[0][0]=bluePawn;
	tiles[0][1]=bluePawn;
	tiles[0][2]=blueKing;
	tiles[0][3]=bluePawn;
	tiles[0][4]=bluePawn;

	tiles[4][0]=redPawn;
	tiles[4][1]=redPawn;
	tiles[4][2]=redKing;
	tiles[4][3]=redPawn;
	tiles[4][4]=redPawn;
}

TileObject Board::get_tile_object(int row, int col) {
	return tiles[row][col];
}

void Board::move_piece(int initrow, int initcol, int endrow, int endcol) {
	tiles[endrow][endcol] = tiles[initrow][initcol];
	tiles[initrow][initcol] = empty;
}
