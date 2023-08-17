#include "King.h"
#include"chessBoard.h"
extern chessBoard board;
King::King(char c, Position p)
{
	color = c;
	position = p;
	type = "K";
}
bool King::validMove(Position& to)
{
	bool isValid = false;
	int row_move = 1;
	if (board.getPiece(position)->getColor() == 'b')
		row_move = -1;
	if (to.getXpos() == position.getXpos()&&(to.getYpos()==position.getYpos()+1||to.getYpos()==position.getYpos()-1))
	{
		if(board.getPiece(to)==nullptr)
		isValid = true;
		else {
			if (board.getPiece(to)->getColor() == this->color)
				isValid = false;
			else
				isValid = true;
		}
	}
	else if (to.getYpos() == position.getYpos() && (to.getXpos() == position.getXpos() + row_move || to.getXpos() == position.getXpos() - row_move))
	{
		if (board.getPiece(to) == nullptr)
			isValid = true;
		else {
			if (board.getPiece(to)->getColor() == this->color)
				isValid = false;
			else
				isValid = true;
		}
	}
	else if ((to.getXpos() == position.getXpos() + 1|| to.getXpos() == position.getXpos() -1) && (to.getYpos() == position.getYpos() + 1 || to.getYpos() == position.getYpos() - 1))
	{
		if (board.getPiece(to) == nullptr)
			isValid = true;
		else {
			if (board.getPiece(to)->getColor() == this->color)
				isValid = false;
			else
				isValid = true;
		}
		
	}
	return isValid;
}