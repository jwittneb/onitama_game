#ifndef __PIECE_H__
#define __PIECE_H__

class Piece {
	int posx;
	int posy;
	bool isKing;	
	bool alignment;

	public:
	//move should take in a cord+movement
	void move_piece(int xchange, int ychange);
	bool is_king();
	bool getAlignment();
	Piece(int initx, int inity, bool alignment);
	~Piece();
	
	int get_posx() {return posx;}
	int get_posy() {return posy;}
	void set_posx(int x) {posx = x;}
	void set_posy(int y) {posy = y;}
};
#endif
