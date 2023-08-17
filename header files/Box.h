#pragma once
#include"Pieces.h"
class Box
{
	Pieces* chessPiece;
public:
	Box(Pieces* = nullptr);
	void setPiece(Pieces*);
	Pieces* getPiece()const;
	void clear();
};

