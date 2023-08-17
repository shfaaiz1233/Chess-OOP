#pragma once
#include"Box.h"
class chessBoard
{
	Box board[8][8];
	void initializeBoard();
	bool checkInRange(Position&);
public:
	chessBoard();
	void draw();
	Pieces* getPiece(Position&);
	bool movePiece(Position&, Position&);
};

