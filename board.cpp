#include "board.h"
#include <iostream>

Board *Board::_instance = 0;

//constructor sets up the board to the starting game position
Board::Board() {
	//setting up the blue/red
	for (int i=0; i<boardWidth; ++i) {
		Piece *nextBluePiece = new Piece(0,i,0);
		tiles[0][i] = nextBluePiece;
		bluePieces[i] = nextBluePiece;

		Piece *nextRedPiece = new Piece(boardHeight-1,i,1);
		tiles[boardHeight-1][i] = nextRedPiece;
		redPieces[i] = nextRedPiece;
	}
	
	//make sure that the rest of the board is empty
	for (int i=1; i<boardHeight-1; ++i) {
		for (int j=0; j<boardWidth; ++j) {
			tiles[i][j]=0;
		}
	}
}

Piece *Board::getTileObject(int row, int col) {
	return tiles[row][col];
}

//Function to move pieces, does not do checking that you are moving your own pieces, which should be
//checked in the player move functions
void Board::move_piece(int initrow, int initcol, int deltax, int deltay) {
	if (tiles[initrow][initcol]==0) {
		std::cout << "Attempting to move from an empty location" << std::endl;	
	} else {
		tiles[initrow+deltax][initcol+deltay] = tiles[initrow][initcol];
		tiles[initrow][initcol] = 0;
		tiles[initrow+deltax][initcol+deltay]->set_posx(initrow+deltax);
		tiles[initrow+deltax][initcol+deltay]->set_posy(initcol+deltay);
	}
}

//print the game board, with the following legend:
// 0 -> empty space
// b -> blue pawn
// r -> red pawn
// B -> blue king
// R -> red king
void Board::print_board() {
	for (int i=0; i<boardHeight; ++i) {
		for (int j=0; j<boardWidth; ++j) {
			Piece *toPrint = getTileObject(i,j);
			if (toPrint == 0) {
				std::cout << 0;
			} else {
				if ((toPrint->get_alignment() == 0) && (toPrint->is_king() == 0)) {
					std::cout << "b";
				}
				if ((toPrint->get_alignment() == 1) && (toPrint->is_king() == 0)) {
					std::cout << "r";
				}
				if ((toPrint->get_alignment() == 0) && (toPrint->is_king() == 1)) {
					std::cout << "B";
				}
				if ((toPrint->get_alignment() == 1) && (toPrint->is_king() == 1)) {
					std::cout << "R";
				}
			}
		}
		std::cout << std::endl;
	}	
}
