#include "Queen.h"
#include"Bishop.h"
#include"Rook.h"
#include"chessBoard.h"
extern chessBoard board;
Queen::Queen(char c, Position p)
{
	color = c;
	position = p;
	type = "Q";
}
bool Queen::validMove(Position& to)
{
	Rook rook(this->color,this->position);
	Bishop bishop(this->color,this->position);
	bool isValid = false;
	if (rook.validMove(to)||bishop.validMove(to))
	{
		isValid = true;
	}
	return isValid;
}