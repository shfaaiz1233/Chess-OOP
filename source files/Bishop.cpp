#include "Bishop.h"
#include"chessBoard.h"
extern chessBoard board;
Bishop::Bishop(char c, Position p)
{
	color = c;
	position = p;
	type = "B";
}
bool Bishop::validMove(Position& to)
{
	bool isValid = false;
	int row = 0, col = 0;
	if (position.getXpos() - to.getXpos() == position.getYpos() - to.getYpos() || position.getXpos() - to.getXpos() == to.getYpos() - position.getYpos())
	{
		if (position.getXpos() < to.getXpos())
			row = 1;
		else
			row = -1;
		if (position.getYpos() < to.getYpos())
			col = 1;
		else
			col = -1;
		for (int i = position.getXpos() + row, j = position.getYpos() + col; i != to.getXpos() && j != to.getYpos(); i+=row, j+=col)
		{
			Position temp(i, j);
			if (board.getPiece(temp) != nullptr)
			{
				isValid = false;
				return isValid;
			}
			else if (board.getPiece(temp) != nullptr || (board.getPiece(temp) != nullptr && board.getPiece(temp)->getColor() != this->color))
			{
				isValid = true;
				return isValid;
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