#include "Knight.h"
#include"chessBoard.h"
extern chessBoard board;
Knight::Knight(char c, Position p)
{
	color = c;
	position = p;
	type = "Kn";
}
bool Knight::validMove(Position& to)
{
	bool isValid = false;
	int mov2box = 2;
	if (color == 'b' || color == 'B')
		mov2box = -2;
	if ((to.getXpos() == position.getXpos() + mov2box) && (to.getYpos() == position.getYpos()+1))
	{
		Position temp(to.getXpos(), to.getYpos() - 1);
		if (board.getPiece(temp) == nullptr||(board.getPiece(temp)!=nullptr&&board.getPiece(temp)->getColor()!=this->color))
			isValid = true;
	}
	else if ((to.getXpos() == position.getXpos() - mov2box) && (to.getYpos() == position.getYpos() + 1))
	{
		Position temp(to.getXpos(), to.getYpos() - 1);
		if (board.getPiece(temp) == nullptr|| (board.getPiece(temp) != nullptr && board.getPiece(temp)->getColor() != this->color))
			isValid = true;
	}
	else if ((to.getXpos() == position.getXpos() + mov2box) && (to.getYpos() == position.getYpos() - 1))
	{
		Position temp(to.getXpos(), to.getYpos() + 1);
		if (board.getPiece(temp) == nullptr|| (board.getPiece(temp) != nullptr && board.getPiece(temp)->getColor() != this->color))
			isValid = true;
	}
	else if ((to.getXpos() == position.getXpos() - mov2box) && (to.getYpos() == position.getYpos() - 1))
	{
		Position temp(to.getXpos(), to.getYpos() + 1);
		if (board.getPiece(temp) == nullptr|| (board.getPiece(temp) != nullptr && board.getPiece(temp)->getColor() != this->color))
			isValid = true;
	}
	return isValid;
}