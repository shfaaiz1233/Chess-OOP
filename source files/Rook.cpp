#include "Rook.h"
#include"chessBoard.h"
extern chessBoard board;
Rook::Rook(char c, Position p)
{
	color = c;
	position = p;
	type = "R";
}
bool Rook::validMove(Position& to)
{
	bool isValid = false;
	int hor = 1, ver = 1;
	//for vertical move
	if (to.getYpos() == position.getYpos())
	{
		if (to.getXpos() < position.getXpos())
			ver = -1;
		for (int i = position.getXpos()+ver; i != to.getXpos(); i += ver)
		{
			Position temp(i, position.getYpos());
			if (board.getPiece(temp) != nullptr)
			{
				if (board.getPiece(temp)->getColor() == this->color) {

					isValid = false;
					return isValid;
				}
			}
		}
		if (board.getPiece(to) != nullptr) {
			if (board.getPiece(to)->getColor() == this->color)
				isValid = false;
			else
				isValid = true;
		}
		else
			isValid = true;
		return isValid;
	}
	// for horizontal move
	else if (to.getXpos() == position.getXpos())
	{
		if(to.getYpos()<position.getYpos())
		hor = -1;
		for (int i = position.getYpos() + hor; i != to.getYpos(); i += hor)
		{
			Position temp(position.getXpos(), i);
			if (board.getPiece(temp) != nullptr)
			{
				if (board.getPiece(temp)->getColor() == this->color) {
					isValid = false;
					return isValid;
				}
			}
		}
		if (board.getPiece(to) != nullptr) {
			if (board.getPiece(to)->getColor() == this->color)
				isValid = false;
			else
				isValid = true;
		}
		else
			isValid = true;
		return isValid;
	}
	return isValid;
}