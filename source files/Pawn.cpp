#include "Pawn.h"
#include"chessBoard.h"
extern chessBoard board;
Pawn::Pawn(char c, Position p)
{
	this->color = c;
	this->type = "p";
	this->position = p;
	this->doubleJump = true;
}
bool Pawn::validMove(Position& to)
{
	bool isValid = false;
	int move1box = 1;
	int move2box = 2;
	if (color == 'b'|| color=='B')
	{
		move1box = -1;
		move2box = -2;
	}
	if ((to.getXpos() == this->position.getXpos() + move1box) && (to.getYpos() == this->position.getYpos()) && board.getPiece(to) == nullptr)
	{
		isValid = true;
		this->doubleJump = false;
	}
	else if (doubleJump && (to.getXpos() == this->position.getXpos() + move2box) && (to.getYpos() == this->position.getYpos()) && board.getPiece(to) == nullptr)
	{
		isValid = true;
		this->doubleJump = false;
	}
	else if ((to.getXpos()==position.getXpos()+move1box)&&(to.getYpos()==position.getYpos()+1||to.getYpos()==position.getYpos()-1))
	{
		if (board.getPiece(to) != nullptr && board.getPiece(to)->getColor() != this->color)
			isValid = true;
	}
	return isValid;
}